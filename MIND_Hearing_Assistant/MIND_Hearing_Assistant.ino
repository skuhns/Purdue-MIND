
#include <SPI.h> /*SPI communication with OLED*/
#include <Wire.h>
#include <Adafruit_GFX.h> /*OLED Graphics*/
#include <Adafruit_SSD1306.h> /*OLED Driver*/
//Trig Def's for Orlando's FFT courtesy of Orlando Hoilett
#include <TrigDef.h>

#define audio_in 2/*Audio in from microphone*/
#define motor 1 /*TODO: Pin for motor attachment*/

#define safe 0 /*Determined safe response in analyzeFrequency()*/
#define emergency 1 /*Determined emergency response in analyzeFrequency()*/
#define alert 2 /*Signal for basic haptic alert*/
#define button 3 /*TODO: get button pin*/


/* Initialize OLED Constants*/
#define OLED_MOSI  5
#define OLED_CLK   6
#define OLED_DC    20
#define OLED_CS    3
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

/*
These values can be changed in order to evaluate the functions.
These will likely have to be changed based on our microphone and decided rates
*/
const uint16_t samples = 128; //This value MUST ALWAYS be a power of 2
const double signalFrequency = 1000;
const double samplingFrequency = 10989.00;
/*
These are the input and output vectors
Input vectors receive computed results from FFT
*/
uint16_t audioInputs[samples];
uint16_t frequencies[samples];

int sensitivity = 5; /*On a scale of 1-10 levels, this will determine the haptic feedback response*/
int level = 0; /*Value keeping track of level at any given time */

void setup() {
  pinMode(motor,OUTPUT);
  pinMode(button,INPUT);
  pinMode(audio_in, INPUT);

//LOW or HIGH depending on if button is configured active LOW or active HIGH
//attachPinInterrup is Simblee specific
  attachPinInterrupt(motor,increaseSensitivity,LOW);
  
  Serial.begin(115200); //High baud rate
  display.begin(SSD1306_SWITCHCAPVCC);//Begin OLED
  display.display(); //Boot screen
  delay(1000);
  display.clearDisplay();

}

void loop() {
  int f;
  //TODO Display Clock Interface
  int arr[3];
  buildSamples(&arr[0]);
  level = arr[0];
  if(level >= sensitivity){
    hapticResponse(alert); 
  }
  f = analyzeFrequency();
  if(f == emergency) {
    hapticResponse(emergency);
    //Display Emergency()
  }
}


void buildSamples(int * arr) {
  /*This function will fill the audioInput array with raw input data 
   * TODO: Find high benchmark for loud sound
   * RETURN: Max Freq Value
  */
  int maxVol = 0;// Loudest sound heard in sample
  int dat=0; // var used to display frequency distribution on 64x96px OLED
  int mag = 0; //magnitude of highest frequency bin
  int bin = 0; //Range of where frequency was detected (bin,bin+95Hz)
  for(int i = 0; i < samples; i++) {
    audioInputs[i] = analogRead(audio_in);
    if(audioInputs[i] > maxVol) {
      maxVol = audioInputs[i]; 
    }
  }
  
  solveFFT(); //Compute FFT
  
  for(int i = 1; i < 64; i++) {
      dat = frequencies[i]/60;
      if(frequencies[i] >= mag){
        //TODO figure out what to do with these
        mag = frequencies[i];
        bin = i*((samplingFrequency)/samples);
      }
      display.drawLine(i*2, 0, i*2, dat, WHITE); // draw bar graphics for freqs above 500Hz to buffer
      display.drawLine((i*2)+1, 0, (i*2)+1,dat, WHITE); // draw bar graphics for freqs above 500Hz to buffer
  }
  display.setCursor(0,0);                             //set cursor to top of screen
  display.display();                                  //show the buffer
  
  arr[0] = maxVol;
  arr[1] = mag;
  arr[2] = bin;
   
}


void hapticResponse(int sig) {
  /*TODO: Something like this, we will generate more complex feedback later
    */
  if(sig == alert) {  //little buzz
    digitalWrite(motor,HIGH);
    delay(200);
    digitalWrite(motor,LOW);
  }
  else if(sig == emergency) { //bigger buzzes
    digitalWrite(motor,HIGH);
    delay(500);
    digitalWrite(motor,LOW);
    delay(200);
    digitalWrite(motor,HIGH);
    delay(500);
    digitalWrite(motor,LOW);
  }
}
int analyzeFrequency(){
  /*TODO: given frequency from FFT attempt to identify an emergency sound
    RETURN safe if no pattern is detected at alert frequencies
      else 
    RETURN emergency
    https://pdfs.semanticscholar.org/c4cc/281380e4ae4903fc7dfbd316b14716383d7f.pdf
    https://pdfs.semanticscholar.org/11db/07338521c72331c3a8a89e0253e669b6547d.pdf
  */
  //Look at raw audio inputs
  int isLoud = 0;
  int isFreq = 0;
  //TODO Replace 1500 with valid number based on testing
  for (int i = 0; i < samples; i++) {
    if(audioInputs[i] > 1500) {
      isLoud = 1;
    }
  }
  //j=10 because we arent concerned with low frequencies (Lower than (j * 95 Hz)
  for(int j = 10; j < samples; j++) {
    if(frequencies[j] > 1800) {
      isFreq = 1;
    }
  }
  if(isLoud == 1 && isFreq == 1) {
    return emergency;
  }
  if(isLoud==1) {
    return alert;
  }
  return safe;
}

int increaseSensitivity(uint32_t probablyConventionBecauseThisIsACallbackFunction) {
  
  sensitivity++;
  if(sensitivity > 10) {
    sensitivity = 0;
  }
  /*
   * update screen
  while(digitalRead(motor) == 1) {
    increaseSensitivity();
    delay(100);
  }*/
  return 0;
}


void solveFFT()
{
  //Print the column names
  Serial.print("fftFreqIncr");
  Serial.print(",");
  Serial.println("sound");
  //Comput the FFT from n = 0 to n = N-1
  //n is the current index, N is the number of samples
  for (int i = 0; i < samples; i++)
  {
    signed long int pulseResult_Real = 0;
    signed long int pulseResult_Imag = 0;
    //definition of the summation. Adding up each index
    for (int j = 0; j < samples; j++)
    {
      //not using native trig definitions, instead using look-up tables
      //to save on computational power
      //
      //since the sine and cosine functions are cyclic,
      //this (i*j) - (samples*((i*j)/samples)) ensures that we adjust
      //for how many cycles of the cosine and since function have
      //already occured. For example, if we get 7pi, we subtract 6pi
      //since 7pi is equivalent to pi.
      //"i" is in equivalent to n in the summation definition of the FFT
      //"i" is not an imaginary number in this case
      //"J" is equivalent to the k in the summation definition of the FFT
      //where k is the current index of the summation, while n is the index
      //in the dataset the FFT is being computed on
      //also, since the real and imaginary number are square anyway, we
      //do not need to do explicit complex math at all
      pulseResult_Real += intcosine128[ (i*j) - (samples*((i*j)/samples)) ] * audioInputs[j];
      pulseResult_Imag += intsine128[ (i*j) - (samples*((i*j)/samples)) ] * audioInputs[j];
    }
    //divide by 1000 to prevent each number from getting too large
    //and from being more computationally expensive
    pulseResult_Real = pulseResult_Real/1000;
    pulseResult_Imag = pulseResult_Imag/1000;
    //calculate the magnitude of the complex number
    frequencies[i] = sqrt(pow(pulseResult_Real,2) + pow(pulseResult_Imag,2));
    //fsHR = sampling period in milliseconds
    //this calculates the frequency bins for the FFT
    //the first value is always 0
    //each bin is now defined as sampling frequency/number of samples
    //this is simply the definition of the FFT
    //
    //in this case, fsHR is in milliseconds so divide by 1000 to put it into
    //seconds, then take the reciprocal to put it into Hertz, then divide
    //by samples to get each frequency bin
    Serial.print(i*((1.0/(samplingFrequency/1000.0))/samples));
    Serial.print(",");
    Serial.println(frequencies[i]);
  }
}





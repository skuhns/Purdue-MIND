
#include <SPI.h> /*SPI communication with OLED*/
#include <Wire.h>
#include <Adafruit_GFX.h> /*OLED Graphics*/
#include <Adafruit_SSD1306.h> /*OLED Driver*/
#include <TrigDef.h>

#define audio_in 2 /*Audio in from microphone*/

/*
These values can be changed in order to evaluate the functions.
These will likely have to be changed based on our microphone and decided rates
*/
const uint16_t samples = 128; //This value MUST ALWAYS be a power of 2
const double samplingFrequency = 10989.00;
/*
These are the input and output vectors
Input vectors receive computed results from FFT
*/
uint16_t audioInputs[samples];
uint16_t frequencies[samples];


int sensitivity = 7; /*On a scale of 1-10 levels, this will determine the haptic feedback response*/
int level = 0; /*Value keeping track of level at any given time */
int ylim = 96;
/* Initialize OLED Constants*/
#define OLED_MOSI  5
#define OLED_CLK   6
#define OLED_DC    20
#define OLED_CS    3
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup() {

  pinMode(audio_in, INPUT);
  Serial.begin(115200); //High baud rate
  display.begin(SSD1306_SWITCHCAPVCC);//Begin OLED
  display.display(); //Boot screen
  delay(1000);
  display.clearDisplay();

}

void loop() {
  //TODO Display Clock Interface
  buildSamples();
  int dat=0;
  int mag = 0;
  int bin = 0;
  for(int i = 2; i < 64; i++) {
      dat = frequencies[i]/60;
      if(frequencies[i] >= mag){
        mag = frequencies[i];
        bin = i*((samplingFrequency)/samples);
      }
      display.drawLine(i*2, 0, i*2, dat, WHITE); // draw bar graphics for freqs above 500Hz to buffer
      display.drawLine((i*2)+1, 0, (i*2)+1,dat, WHITE); // draw bar graphics for freqs above 500Hz to buffer
  }
  Serial.print("Highest Frequency:");
  Serial.print(bin);
  Serial.print("-");
  Serial.print(bin+95);
  Serial.print("Hz, Magnitude");
  Serial.println(mag);
  
  display.setCursor(0,0);                             //set cursor to top of screen
  display.display();                                  //show the buffer
}


int buildSamples() {
  /*TODO: This function will fill the audioInput array with raw input data 
    RETURN: Highest level from sample 
  */
  for(int i = 0; i < samples; i++) {
    audioInputs[i] = analogRead(audio_in);
  }
  solveFFT();
  //TODO: get max freq from fft
  return 1;
   
}

void solveFFT()
{
  display.clearDisplay();                             //clear display

  //Print the column names
//  Serial.print("fftFreqIncr");
//  Serial.print(",");
//  Serial.println("sound");
  //Comput the FFT from n = 0 to n = N-1
  //n is the current index, N is the number of samples
  for (int i = 0; i < samples; i++)
  {
    signed long int pulseResult_Real = 0;
    signed long int pulseResult_Imag = 0;
    //definition of the summation. Adding up each index
    for (int j = 0; j < samples; j++)
    {

      pulseResult_Real += intcosine128[ (i*j) - (samples*((i*j)/samples)) ] * audioInputs[j];
      pulseResult_Imag += intsine128[ (i*j) - (samples*((i*j)/samples)) ] * audioInputs[j];
    }
    //divide by 1000 to prevent each number from getting too large
    //and from being more computationally expensive
    pulseResult_Real = pulseResult_Real/1000;
    pulseResult_Imag = pulseResult_Imag/1000;
    //calculate the magnitude of the complex number
    frequencies[i] = sqrt(pow(pulseResult_Real,2) + pow(pulseResult_Imag,2));

//    Serial.print(i*((samplingFrequency))/samples);
//    Serial.print(",");
//    Serial.println(frequencies[i]);
  }
}





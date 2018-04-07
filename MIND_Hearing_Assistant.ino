
#include <SPI.h> /*SPI communication with OLED*/
#include <Wire.h>
#include <Adafruit_GFX.h> /*OLED Graphics*/
#include <Adafruit_SSD1306.h> /*OLED Driver*/

#include <arduinoFFT.h> //FFT option 1
/*I think arduinoFFT is the library we want to use. It supports a lot of features
 * It is also far more calculation heavy which could create a speed issue
 */
#include <fix_fft.h> //FFT option 2

#define audio_in A0 /*Audio in from microphone*/
#define motor 1 /*Pin for motor attachment*/

#define safe 0 /*Determined safe response in analyzeFrequency()*/
#define emergency 1 /*Determined emergency response in analyzeFrequency()*/
#define alert 2 /*Signal for basic haptic alert*/
#define button 2


/* Initialize OLED Constants*/
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

arduinoFFT FFT = arduinoFFT(); /* Create FFT object */
/*
These values can be changed in order to evaluate the functions.
These will likely have to be changed based on our microphone and decided rates
*/
const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
const double signalFrequency = 1000;
const double samplingFrequency = 5000;
const uint8_t amplitude = 100;
/*
These are the input and output vectors
Input vectors receive computed results from FFT
*/
double vReal[samples];
double vImag[samples];

int sensitivity = 7; /*On a scale of 1-10 levels, this will determine the haptic feedback response*/
int level = 0; /*Value keeping track of level at any given time */

void setup() {
  pinMode(motor,OUTPUT);
  pinMode(button,INPUT);
  Serial.begin(115200); //High baud rate
  display.begin(SSD1306_SWITCHCAPVCC);//Begin OLED
  display.display(); //Boot screen
  delay(1000);
  display.clearDisplay();

}

void loop() {
  //TODO Display Clock Interface
  
  //TODO get button 
  if(digitalRead(motor) == 1) {
    increaseSensitivity();
  }
  level = buildSamples();
  if(level >= sensitivity){
    hapticResponse(alert); 
  }
  performFFT();
  if(analyzeFrequency() == emergency) {
    hapticResponse(emergency);
    //Display Emergency
  }
}


int buildSamples() {
  /*TODO: This function will fill the vReal array with raw input data 
    RETURN: Highest level from sample 
  */  
}
void performFFT() {
  /*TODO: Perform FFT on the data*/
}
void hapticResponse(int sig) {
  /*TODO: Something like this, we will generate more complex feedback later
    */
  if(sig == alert) {  
    digitalWrite(motor,HIGH);
    delay(200);
    digitalWrite(motor,LOW);
  }
  else if(sig == emergency) {
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
  return safe;
}
void increaseSensitivity() {
  sensitivity++;
  while(digitalRead(motor) == 1) {
    increaseSensitivity();
    delay(100);
  }
}






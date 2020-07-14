//Luther's version
//Notice: The hardware settings may be different

#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
Adafruit_7segment matrix = Adafruit_7segment();

int measurePin = A5;
int ledPower = 14;

/*****************************************/

// use first channel of 16 channels (started from zero)
#define LEDC_CHANNEL_0     0
// use 13 bit precission for LEDC timer
#define LEDC_TIMER_13_BIT  8
// use 5000 Hz as a LEDC base frequency
#define LEDC_BASE_FREQ     1000
#define LED_PIN            12
 
/*****************************************/
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
 
float voMeasured = 0;
float calcVoltage = 0;  
float dustDensity = 0;
 
void setup(){
//  Serial.begin(9600);
  
//  pinMode(ledPower,OUTPUT);

  Serial.begin(9600);
  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(LED_PIN, LEDC_CHANNEL_0);
  pinMode(ledPower,OUTPUT);
  matrix.begin(0x70);
}
 
void loop(){
  digitalWrite(ledPower,LOW); // power on the LED
  delayMicroseconds(samplingTime);
 
  voMeasured = analogRead(measurePin); // read the dust value
 
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); // turn the LED off
  delayMicroseconds(sleepTime);
 
  // 0 - 3.3V mapped to 0 - 1023 integer values
  // recover voltage
  //calcVoltage = voMeasured * (3.3 / 4096.0); 
  calcVoltage = voMeasured * (5 / 4096.0); //use the 5v value despite 3.3v to create 5V scaled output values

  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  //dustDensity = 0.172 * calcVoltage - 0.0999;

//replace with calc from https://www.pocketmagic.net/sharp-gp2y1010-dust-sensor/

if (calcVoltage < 0.583)  
    dustDensity = 0;
  else
    dustDensity = 6 * calcVoltage / 35 - 0.1;


//if the measured value is negative then the dust density is close enough to 0
  if (dustDensity < 0){
    dustDensity = 0;
  }
   
  Serial.print("Raw Signal Value (0-4096): ");
  Serial.print(voMeasured);
 
  Serial.print(" - Voltage: ");
  Serial.print(calcVoltage);
 
  Serial.print(" - Dust Density (mg/m^3): ");
  Serial.println(dustDensity,3);

  matrix.print(dustDensity,3);
  matrix.writeDisplay();
 
  delay(1000);
}

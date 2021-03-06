//Analog Input Voltage Pin: A0 Digital Output Pin: Pin 12 I am also switching LED on Pin 13 ON/OFF
//Calculations: With 10K, 4.7K Voltage divider, when you take voltage off of 4.7K, following is the rough voltage that gets fed to Arduino Input.
//Voltage -- Arduino Input from 4.7K 12.0V -- 3.836V 12.5V -- 3.996V Approx 4Volts
//3.83 and 4.0V are used for switching between ON/OFF states. Serial Monitor at 9600 baud shows rough voltage.
#include<avr/wdt.h> /* Header for watchdog timers in AVR */

//#define DEBUG true
#define DEBUG false

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int outPin = 12;
int sensorValue = 0;  // variable to store the value coming from the sensor
float voltage= 0.0;
float onVoltage = 4.0;
float offVoltage = 3.83;
int switchState = 0;

void setup() {

  if(DEBUG) {
    Serial.begin(9600);
    Serial.println("Program Start");    
  }
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(outPin, OUTPUT);  
  digitalWrite(outPin, LOW); 
  digitalWrite(ledPin, LOW);   

  //Watchdog Code
  wdt_disable();  /* Disable the watchdog and wait for more than 2 seconds */
  delay(3000);  /* Done so that the Arduino doesn't keep resetting infinitely in case of wrong configuration */
  wdt_enable(WDTO_8S);  /* Enable the watchdog with a timeout of 8 seconds */
 
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  voltage = sensorValue * (5.0 / 1023.0);
  if((switchState == 0) && (voltage > onVoltage)) {
    //Turn on the switch
    switchState = 1;
    digitalWrite(outPin, HIGH); 
    digitalWrite(ledPin, HIGH);     
  }
  if((switchState == 1) && (voltage < offVoltage)) {
    //Turn off the switch
    switchState = 0;
    digitalWrite(outPin, LOW); 
    digitalWrite(ledPin, LOW); 
  }
  if(DEBUG) {
    Serial.print("switchState ");  
    Serial.println(switchState);    
    Serial.print("ADC Voltage ");    
    Serial.println(voltage);
    delay(500);
  }else {
    delay(100);    
  }
  wdt_reset();  /* Reset the watchdog */
}

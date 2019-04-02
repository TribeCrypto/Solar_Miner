
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int outPin = 12;
int sensorValue = 0;  // variable to store the value coming from the sensor
float voltage= 0.0;
float onVoltage = 4.0;
float offVoltage = 3.83;
int switchState = 0;

void setup() {

  Serial.begin(9600);
  Serial.println("Program Start");
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(outPin, OUTPUT);  
  digitalWrite(outPin, LOW); 
  digitalWrite(ledPin, LOW);   
  
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
  Serial.print("switchState ");  
  Serial.println(switchState);    
  Serial.print("ADC Voltage ");    
  Serial.println(voltage);
  delay(500);
}

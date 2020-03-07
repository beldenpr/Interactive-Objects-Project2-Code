/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 4;     // the number of the pushbutton pin
const int ledPin =  5;      // the number of the LED pin

const int buttonPin2 = 2;     // the number of the pushbutton pin
const int ledPin2 =  6;      // the number of the LED pin

const int buttonPin3 = 3;     // the number of the pushbutton pin
const int ledPin3 =  7;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;         // variable for reading the pushbutton status

String inData="";

int light = 0;

void setup() {
  Serial.begin(9600);
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  // initialize the LED pin as an output:
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin2, INPUT);

  // initialize the LED pin as an output:
  pinMode(ledPin3, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin3, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);

//  if (Serial.available() > 0) {
//    int inByte = Serial.read();
//    Serial.write(inByte);
//  }

//  int sensorValue = analogRead(A5);
//  // print out the value you read:
//  sensorValue = map(sensorValue,1023,0,300,0);
//  Serial.println(sensorValue);


//COREY HELLLP ----------------------------------------------/



  if (Serial.available() > 0) {

    while(Serial.available() > 0) {
    char recieved = Serial.read();
    inData.concat(recieved);
    if(recieved == '\n') {
      if(inData.startsWith("code")) {
        digitalWrite(ledPin, HIGH);
        delay(1000);
        digitalWrite(ledPin, LOW);
        
      } else if(inData.startsWith("code2")) {

        
      } else if (inData.startsWith("code3")) {


      }
    }
  }
  }

  //END OF COREY HELLLP ----------------------------------------------/

//  switch(light) {
//    case 1:
//    digitalWrite(ledPin, HIGH);
//    digitalWrite(ledPin, LOW);
//    digitalWrite(ledPin, LOW);
//    break;
//
//    case 2:
//    digitalWrite(ledPin2, HIGH);
//    digitalWrite(ledPin3, LOW);
//    digitalWrite(ledPin, LOW);
//    break;
//
//    case 3:
//    digitalWrite(ledPin3, HIGH);
//    digitalWrite(ledPin2, LOW);
//    digitalWrite(ledPin, LOW);
//    break;
//  }

//  if (Serial.available() > 0) {
//
//    while(Serial.available() > 0) {
//    char recieved = Serial.read();
//    inData.concat(recieved);
//    if(recieved == '\n') {
//      if(inData.startsWith("code2")) {
//
//        digitalWrite(ledPin, LOW);
//        digitalWrite(ledPin2, HIGH);
//        digitalWrite(ledPin3, LOW);
//        
//      }
//    }
//  }
//  }

  
//  if (Serial.available() > 0) {
//
//    while(Serial.available() > 0) {
//    char recieved = Serial.read();
//    inData.concat(recieved);
//    if(recieved == '\n') {
//      if(inData.startsWith("code")) {
//
//        digitalWrite(ledPin3, HIGH);
//        digitalWrite(ledPin2, LOW);
//        digitalWrite(ledPin, LOW);
//        }else if(inData.startsWith("code2")) {
//
//        digitalWrite(ledPin2, LOW);
//        digitalWrite(ledPin3, HIGH);
//        digitalWrite(ledPin, LOW);
//        } else if(inData.startsWith("code3")) {
//
//        digitalWrite(ledPin2, LOW);
//        digitalWrite(ledPin3, LOW);
//        digitalWrite(ledPin, HIGH);
//        }
//      }
//    }
//  }
  }

//  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//  if (sensorValue > 100 && sensorValue < 200) {
//    // turn LED on:
//    digitalWrite(ledPin2, HIGH);
//  } else {
//    // turn LED off:
//    digitalWrite(ledPin2, LOW);
//  }
//
//  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//  if (sensorValue > 200) {
//    // turn LED on:
//    digitalWrite(ledPin3, HIGH);
//  } else {
//    // turn LED off:
//    digitalWrite(ledPin3, LOW);
//  }

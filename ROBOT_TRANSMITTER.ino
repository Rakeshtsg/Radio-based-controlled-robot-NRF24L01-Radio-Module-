/*Arduino JOYSTICK CONTROLLED CAR (TRANSMITTER)
  //based on Arduino
//Using a Arduino|JOYSTICK|NRF24L01 Radio Module|Robot
//This is unlikely to be of much use in a practical applications
//ID OF USER: Rakeshtsg
//INTERFACE: Arduino 
        
YOU HAVE TO INSTALL THE RF24 LIBRARY BEFORE UPLOADING THE CODE
   https://github.com/tmrh20/RF24/      
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(8,9); // CE, CSN
const byte address[6] = "00001";
char xyData[32] = "";
String xAxis, yAxis;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  
  xAxis = analogRead(A1); // Read Joysticks X-axis
  yAxis = analogRead(A0); // Read Joysticks Y-axis
  // X value
  xAxis.toCharArray(xyData, 5); // Put the String (X Value) into a character array
  radio.write(&xyData, sizeof(xyData)); // Send the array data (X value) to the other NRF24L01 modile
  // Y value
  yAxis.toCharArray(xyData, 5);
  radio.write(&xyData, sizeof(xyData));
  delay(20);
}

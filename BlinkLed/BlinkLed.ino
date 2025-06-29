//#############   ElectricCircuit  ###############//
//Code for control of ESP32 through MIT inventor app (Bluetooth).
//This Video Making by ElectriCircuit For More video To Subscribe this Channel
//https://www.youtube.com/channel/UCIr4PGxiEQWmYswJPueRlMQ
// Like this facebook Page: https://www.facebook.com/Electric-Circuit-108154251467438
// Follow In Instagram: https://www.instagram.com/electric_circuit_099/
// View Blog: https://electriccircuitarduino.blogspot.com/

#include"BluetoothSerial.h"  // this header is needed for Bluetooth Serial

BluetoothSerial ESP_BT; 

int LED = 2;
boolean state = 0;

    
int incoming;  // Parameters for Bluetooth interface

void setup() {
  Serial.begin(19200);
  ESP_BT.begin("ESP32_EC"); //Name of your Bluetooth interface -> will show up on your phone
  pinMode (LED, OUTPUT);
  
}

void loop() {
  //Receive Bluetooth signal
  
  if (ESP_BT.available()) 
  {
    incoming = ESP_BT.read(); 
    
    int button = floor(incoming / 10); //button ID is (10,11),value is 1 or 0 You Add More Button (20,21),(30,31)........
    int value = incoming % 10;

    
    switch (button) {
      case 1:  
        Serial.print("Button 1:"); Serial.println(value);
        digitalWrite(LED, value);
        break;
    }
  }

}

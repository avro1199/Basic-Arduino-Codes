boolean red_led_state = 0, green_led_state = 0;

#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 4;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // Serial Monitor @ 9600 baud
  Serial.begin(9600);
  // Enable the IR Receiver
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print Code in HEX
    Serial.println(results.value, HEX);

    switch (results.value) {
      case 0xFE10EF: //Red Keypad Button
        digitalWrite(9, red_led_state);
        red_led_state = !red_led_state;
        break;
      case 0xFE906F: //Red Keypad Button
        digitalWrite(10, green_led_state);
        green_led_state = !green_led_state;
        break;
      default:
        break;

    }
    irrecv.resume();
  }
}

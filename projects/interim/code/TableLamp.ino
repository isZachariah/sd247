#define LED 14
#define BUTTON 15

bool light_state = false;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(BUTTON) == LOW) {
        delay(20);
        if (digitalRead(BUTTON) == LOW) {
            reverseGPIO(LED);
        }
        while (digitalRead(BUTTON) == LOW);
    }
}

void reverseGPIO(int pin) {
    light_state = !light_state;
    digitalWrite(pin, light_state);
}
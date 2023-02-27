#define BUZZER 9
#define BUTTON 15
void setup() {
    pinMode(BUZZER, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    digitalWrite(BUZZER, LOW);
}

void loop() {
    if (digitalRead(BUTTON) == LOW) {
        digitalWrite(BUZZER, HIGH);
    }else{
        digitalWrite(BUZZER, LOW);
    }

}
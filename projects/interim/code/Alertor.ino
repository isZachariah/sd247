#define BUZZER 9
#define BUTTON 15

void alert() {
    float sinVal;
    int toneVal;
    for (int x = 0; x < 360; x += 10){
        sinVal = sin(x * (PI / 180));
        toneVal = 2000 + sinVal * 500;
        freq(BUZZER, toneVal, 10);
    }
}

void freq(int PIN, int freqs, int times) {
    if (freqs === 0) {
        digitalWrite(PIN, LOW);
    } else {
        for (int i = 0; i < times * freqs / 1000; i++) {
            digitalWrite(PIN, HIGH);
            delayMicroseconds(1000000 / freqs / 2);
            digitalWrite(PIN, LOW);
            delayMicroseconds(1000000 / freqs / 2);

        }
    }
}

void setup() {
    pinMode(BUZZER, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(BUTTON) == LOW) {
        alert();
    }else{
        freq(BUZZER, 0, 10);
    }
}


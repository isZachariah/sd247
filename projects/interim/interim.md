# Raspberry Pi - Micropython and C Tutorial:

- [Freenove MicroPython Tutorial](https://github.com/Freenove/Freenove_Basic_Starter_Kit_for_Raspberry_Pi_Pico/blob/main/Python/Python_Tutorial.pdfLinks)
- [Freenove C Tutorial](https://github.com/Freenove/Freenove_Basic_Starter_Kit_for_Raspberry_Pi_Pico/blob/main/C/C_Tutorial.pdfLinks)



###  Tutorials (Due Feb 26):
All tutorials need to have their code submitted in a file as well as a short video of the working prototype.


#### Chapter 1: LED
- [Blink](code/Blink.ino)
![Blink](videos/BlinkLED.gif)
```c++
#define LED 14

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}
```

#### Chapter 2: Button & LED
- [Button LED](code/ButtonLED.ino)
![Button + LED](videos/LEDButton.gif)
```c++
#define LED 14
#define BUTTON 15


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
```


- [Table Lamp](code/TableLamp.ino)
![Table Lamp](videos/TableLamp.gif)
```c++
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
```

#### Chapter 3: LED Bar
- I wasn't able to purchase the freenove kit, I already had a bunch of parts but not all of them needed for these tutorials. I will do my best to make up for the parts I am missing with other projects. 

#### Chapter 4: Analog & PWM
- [Breathing LED](code/BreathingLED.ino)
![Breathing LED](videos/BreathingLED.gif)
```c++
#define LED 14

void setup() {
	pinMode(LED, OUTPUT);
}

void loop() {
	for (int i = 0; i < 255; i++) {
		analogWrite(LED, i);
		delay(5);
	}
	for (int i = 255; i > -1; i--) {
		analogWrite(LED, i);
		delay(5);
	}
}
```

#### Chapter 5: RGBLED


#### Chapter 6: Buzzer

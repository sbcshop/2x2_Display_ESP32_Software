/*
 * Demo code to test onboard programmable buttons and Buzzer
 * Hardware Interfacing =>
    |ESP32  | Button | Function |
    |IO4    | BT1    | Programmable button |
    |IO5    | BT2    | Programmable button |
    |IO0    | BOOT   | Boot button |
    |IO40   | Buz +ve| Buzzer |
 */
const int bootButton = 0; 
const int BT1 = 4; 
const int BT2 = 5; 
const int buzzerPin = 40;

void playbuzzer(const int frequency, const int delayTime){
  tone(buzzerPin, frequency);   // Generate a tone of frequency
  delay(delayTime);             // Wait 
  noTone(buzzerPin);            // Stop the tone
  delay(delayTime);             // Wait 
}

void setup(void) {
  Serial.begin(115200);
  pinMode(bootButton, INPUT);
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.println("Button and Buzzer Demo Test!");
  playbuzzer(2000, 100); // playbuzzer(frequency, delay)
  playbuzzer(1250, 100); // playbuzzer(frequency, delay)
}

void loop() {
  int bootVal = digitalRead(bootButton);
  int bt1Val = digitalRead(BT1);
  int bt2Val = digitalRead(BT2);

  if (bt1Val == 0 | bt2Val == 0 | bootVal == 0){
    playbuzzer(1000, 500); // playbuzzer(frequency, delay)
  }
  Serial.println("Button Value");
  Serial.printf("Boot:%d BT1:%d BT2:%d \n", bootVal, bt1Val,bt2Val);
  delay(200);
}

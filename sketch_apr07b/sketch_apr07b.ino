  double timer1 = 0;
  double timer2 = 0;
  uint16_t reader = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  timer1 = micros();
  reader = analogRead(1);
  timer2 = micros();
  Serial.println(timer2-timer1);
}

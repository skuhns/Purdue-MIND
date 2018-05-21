void setup() {
  pinMode(16,OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(16,HIGH);
  delay(500);
  digitalWrite(16,LOW);
  delay(500);
}

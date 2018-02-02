double vol = 0.0;
double MaxSig = 600.0;
double Sensitivity = .9;

void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  Serial.begin(19200);
}

void loop() {
  // put your main code here, to run repeatedly:
  vol = analogRead(A1);
  Serial.println(vol + '\n');
  delay(50);


    if (vol < (1/9)*Sensitivity*MaxSig) {
      digitalWrite(1,LOW);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
    }
    else if (vol>= (1/9)*Sensitivity*MaxSig && vol < (2/9)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    else if (vol>= (2/9)*Sensitivity*MaxSig && vol < (3/9)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    else if (vol>= (3/9)*Sensitivity*MaxSig && vol < (4/9)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    else if (vol>= (4/9)*Sensitivity*MaxSig && vol < (5/9)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    else if (vol>= (5/9)*Sensitivity*MaxSig && vol < (6/9)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    else if (vol>= (6/9)*Sensitivity*MaxSig && vol < (7/9)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    else if (vol>= (7/9)*Sensitivity*MaxSig && vol < (8/9)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);     
    }
      else if(vol >= (8.0/9.0)*Sensitivity*MaxSig) {
      //Serial.println((8.0/9.0)*Sensitivity*MaxSig);
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);    
    }
  
}

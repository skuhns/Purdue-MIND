
void lightup(int);
void increaseThreshold();
double Sensitivity = 1.0;
double MaxSig = 550.0;
double vol = 0.0;
int threshold = 0;




void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  pinMode(10,INPUT);

  Serial.begin(19200);
}

void loop() {

  // put your main code here, to run repeatedly:
  vol = analogRead(A1);
  Serial.println(vol);
  //Serial.println(digitalRead(10));
  
  if(digitalRead(10) == 1) {
    increaseThreshold();
    delay(500);
  }

  lightup(vol);
  delay(10);
}

void increaseThreshold() {
      threshold++;
      if(threshold >= 9) {
        threshold = 0;
      }
  
      digitalWrite(1,LOW);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);

      digitalWrite(threshold,HIGH);
      delay(500);

    if(digitalRead(10) == 1) {
      increaseThreshold();
      delay(500);
    }
     
  
  
}


void lightup(int vol) {
   
    if (vol < (.111)*Sensitivity*MaxSig) {
      digitalWrite(1,LOW);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
    }
    if (vol>= (.111)*Sensitivity*MaxSig && vol < (.222)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= (.222)*Sensitivity*MaxSig && vol < (.333)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= (.333)*Sensitivity*MaxSig && vol < (.444)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= (.444)*Sensitivity*MaxSig && vol < (.555)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= (.555)*Sensitivity*MaxSig && vol < (.666)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= (.666)*Sensitivity*MaxSig && vol < (.777)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= (.777)*Sensitivity*MaxSig && vol < (.888)*Sensitivity*MaxSig) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);     
    }
    if(vol >= (.888)*Sensitivity*MaxSig) {
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


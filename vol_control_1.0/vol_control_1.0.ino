


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
  double vol = 0.0;
  double MaxSig = 560.0;
  double Sensitivity = 1.0;
  // put your main code here, to run repeatedly:
  vol = analogRead(A1);
  Serial.println(vol);
  Serial.println((.111)*Sensitivity*MaxSig);


  delay(10);


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
/*int vol = 0;

void lightup(int amp);

void setup() {
  //PINS FOR LIGHTS
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  //PIN FOR VIBRATION

  //PIN FOR VOL BUTTONS

  Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  vol = analogRead(A1);
  lightup(vol);

  
}

void lightup(int vol) {
      
    Serial.println(vol + '\n');

    if (vol < 128) {
      digitalWrite(1,LOW);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
    }
    if (vol>= 128 && vol < 256) {
      digitalWrite(1,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= 256 && vol < 384) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= 256 && vol < 384) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= 384 && vol < 512) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= 384 && vol < 512) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= 512 && vol < 640) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);     
    }
    if (vol>= 640 && vol < 768) {
      digitalWrite(1,HIGH);
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);     
    }
    if (vol >= 768 && vol < 896) {
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
*/

const int sensorPin1 = A0;
const int sensorPin2 = A1;
const int sensorPin3 = A2;
const int sensorPin4 = A3;
const int sensorPin5 = A4;
const int mrb = 2; //motor-right-back
const int mrf = 3; //motor-right-front
const int mlf = 4; //motor-left-front
const int mlb = 5; //motor-left-back
const int enaRight = 6;
const int enaLeft = 10;
const int trigPin = 11;
const int echoPin = 12;
const int ldrAnalogPin = A5;
int sensorValue1 ; // 0 or 1
int sensorValue2 ;
int sensorValue3 ;
int sensorValue4 ;
int sensorValue5 ;
int ldrAnalogValue ;
float timer ; // จับเวลา
long duration, distance;


void setup() {
  Serial.begin(9600);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
  pinMode(sensorPin4, INPUT);
  pinMode(sensorPin5, INPUT);
  pinMode(mrb, OUTPUT);
  pinMode(mrf, OUTPUT);
  pinMode(mlf, OUTPUT);
  pinMode(mlb, OUTPUT);
  pinMode(enaRight, OUTPUT);
  pinMode(enaLeft, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ldrAnalogPin, INPUT);

  stopMotors();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034 / 2);
  Serial.println(distance);

}

void moveMotorForward() {
  digitalWrite(mrb, LOW);
  digitalWrite(mrf, HIGH);
  digitalWrite(mlf, HIGH);
  digitalWrite(mlb, LOW);
  analogWrite(enaRight, 90);//251 //93
  analogWrite(enaLeft, 83);//255 //79
}

void turnRight() {
  digitalWrite(mrb, HIGH);
  digitalWrite(mrf, LOW);
  digitalWrite(mlf, HIGH);
  digitalWrite(mlb, LOW);
  analogWrite(enaRight, 90);//155
  analogWrite(enaLeft, 90);//255
}



void turnLeft() {
  digitalWrite(mrb, LOW);
  digitalWrite(mrf, HIGH);
  digitalWrite(mlf, LOW );
  digitalWrite(mlb, HIGH);
  analogWrite(enaRight, 100);//255
  analogWrite(enaLeft, 100);//155
}


void moveBackward() {
  digitalWrite(mrb, HIGH);
  digitalWrite(mrf, LOW);
  digitalWrite(mlf, LOW);
  digitalWrite(mlb, HIGH);
  analogWrite(enaRight, 100);//251
  analogWrite(enaLeft, 100);//255
}

void stopMotors() {
  digitalWrite(mrb, LOW);
  digitalWrite(mrf, LOW);
  digitalWrite(mlf, LOW);
  digitalWrite(mlb, LOW);
  analogWrite(enaRight, 0);
  analogWrite(enaLeft, 0);
}

void updateSensorValues() {
  sensorValue1 = (analogRead(sensorPin1) >= 900) ? 1 : 0;
  sensorValue2 = (analogRead(sensorPin2) >= 900) ? 1 : 0;
  sensorValue3 = (analogRead(sensorPin3) >= 900) ? 1 : 0;
  sensorValue4 = (analogRead(sensorPin4) >= 900) ? 1 : 0;
  sensorValue5 = (analogRead(sensorPin5) >= 900) ? 1 : 0;
}

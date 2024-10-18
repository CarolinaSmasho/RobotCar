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
const int trigPin = 8;
const int echoPin = 9;
const int ldrAnalogPin = A5;
const int ldrDigitalPin = 11;
int sensorValue1 ; // 0 or 1
int sensorValue2 ;
int sensorValue3 ;
int sensorValue4 ;
int sensorValue5 ;
int ldrAnalogValue ;
float timer ; // จับเวลา


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
  pinMode(ldrDigitalPin, INPUT);
  pinMode(ldrAnalogPin, INPUT);

  stopMotors();
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034 / 2);



  updateSensorValues();

  Serial.println(analogRead(sensorPin1));
  Serial.println(analogRead(sensorPin2));
  Serial.println(analogRead(sensorPin3));
  Serial.println(analogRead(sensorPin4));
  Serial.println(analogRead(sensorPin5));
  Serial.println("=================================================================");


  // อ่านทาง
  if (sensorValue1 <= 0 || sensorValue2 <= 0 || sensorValue3 <= 0 ||
  sensorValue4 <= 0 || sensorValue5 <= 0) {
    /*
    11011 // forward
    10011
    11001
    10111
    11101
    
    00001
    00011 
    00111 // left
    01111
    01011 
    0xxx1 
    x0xx1

    10000
    11000 
    11100 //right 
    11110
    11010 
    1xxx0 
    1xx0x
    
    */

    //Forward
      if(sensorValue1==1&& sensorValue2==1 &&sensorValue3==0 &&sensorValue4==1 &&sensorValue5==1 ){
        moveMotorForward();
        updateSensorValues();
        
      }else if(sensorValue1==1&& sensorValue2==0 &&sensorValue3==0 &&sensorValue4==1 &&sensorValue5==1 ){
        moveMotorForward();
        updateSensorValues();
      }
      else if(sensorValue1==1&& sensorValue2==1 &&sensorValue3==0 &&sensorValue4==0 &&sensorValue5==1 ){
        moveMotorForward();
        updateSensorValues();
      }
      else if(sensorValue1==1&& sensorValue2==0 &&sensorValue3==0 &&sensorValue4==0 &&sensorValue5==1 ){
        moveMotorForward();
        updateSensorValues();
      }else if(sensorValue1==1&& sensorValue2==0 &&sensorValue3==1 &&sensorValue4==1 &&sensorValue5==1 ){
        moveMotorForward();
        updateSensorValues();
      }else if(sensorValue1==1&& sensorValue2==1 &&sensorValue3==1 &&sensorValue4==0 &&sensorValue5==1 ){
        moveMotorForward();
        updateSensorValues();
      }

    // Left
      else if(sensorValue1==0&& sensorValue2==0 &&sensorValue3==0 &&sensorValue4==0 &&sensorValue5==1){
        turnLeft();
        delay(300);
        stopMotors();
        updateSensorValues();
      }else if(sensorValue1==0&& sensorValue2==0 &&sensorValue3==0 &&sensorValue4==1 &&sensorValue5==1 ){
        turnLeft();
        delay(200);
        stopMotors();
        updateSensorValues();
      }else if(sensorValue1==0&& sensorValue2==0 &&sensorValue3==1 &&sensorValue4==1 &&sensorValue5==1 ){
        turnLeft();
        delay(300);
        stopMotors();
        updateSensorValues();
      }else if(sensorValue1==0&& sensorValue2==1 &&sensorValue3==1 &&sensorValue4==1 &&sensorValue5==1 ){
        turnLeft();
        updateSensorValues();
        delay(300);
        stopMotors();
      }else if(sensorValue1==0&& sensorValue2==1 &&sensorValue3==0 &&sensorValue4==1 &&sensorValue5==1 ){
        turnLeft();
        delay(300);
        stopMotors();
        updateSensorValues();
      }else if(sensorValue1==0 && (sensorValue4==1 ||sensorValue5==1) ){
        turnLeft();
        delay(200);
        stopMotors();
        updateSensorValues();
      }else if(sensorValue2==0 && (sensorValue4==1 ||sensorValue5==1) ){
        turnLeft();
        delay(200);
        stopMotors();
        updateSensorValues();
      }

    //Right
      else if(sensorValue1==1&& sensorValue2==0 &&sensorValue3==0 &&sensorValue4==0 &&sensorValue5==0){
        turnRight();
        delay(400);
        stopMotors();
        updateSensorValues();
      }else if(sensorValue1==1&& sensorValue2==1 &&sensorValue3==0 &&sensorValue4==0 &&sensorValue5==0 ){
        turnRight();
        delay(200);
        stopMotors();
        updateSensorValues();
      }else if(sensorValue1==1&& sensorValue2==1 &&sensorValue3==1 &&sensorValue4==0 &&sensorValue5==0 ){
        turnRight();
        delay(400);
        stopMotors();
        updateSensorValues();
      }else if(sensorValue1==1&& sensorValue2==1 &&sensorValue3==1 &&sensorValue4==1 &&sensorValue5==0 ){
        turnRight();
        delay(400);
        stopMotors();
        updateSensorValues();
      }else if(sensorValue1==1&& sensorValue2==1 &&sensorValue3==0 &&sensorValue4==1 &&sensorValue5==0 ){
        turnRight();
        delay(400);
        stopMotors();
        updateSensorValues();
      }else if((sensorValue1==1|| sensorValue2==1)&&sensorValue5==0 ){
        turnRight();
        delay(200);
        stopMotors();
        updateSensorValues();
      }else if((sensorValue1==1|| sensorValue2==1)&&sensorValue4==0 ){
        turnRight();
        delay(200);
        stopMotors();
        updateSensorValues();
      } 


    
    
  

  }

  // // เส้นประ
  // if(sensorValue1==1&& sensorValue2==1 &&sensorValue3==1 &&sensorValue4==1 &&sensorValue5==1 ){
  //   timer = millis();
  //   while(millis()- timer<2200 &&sensorValue1==1&& sensorValue2==1 &&sensorValue3==1 &&sensorValue4==1 &&sensorValue5==1 ){
  //     moveMotorForward();
  //     delay(45);
  //     stopMotors();
  //     delay(50);
  //     updateSensorValues();
  //   }
  //   stopMotors();
  // }



  // เจอเส้นดำ 5 ตัว
  // if (sensorValue1 <= 0 && sensorValue2 <= 0 && sensorValue3 <= 0 &&
  //     sensorValue4 <= 0 && sensorValue5 <= 0) {

  //   int count = 0;
  //   unsigned long pmillis = millis();
  //   while (millis() - pmillis <= 8000) {
  //     int a = analogRead(ldrAnalogPin);
  //     if (a < 900) {
  //       count++;
  //       Serial.println("++");
  //       delay(2000);
  //     }
  //   }
  //   if (count == 1) {
  //     delay(200);
  //     turnLeft();
  //     delay(450);
  //     stopMotors();
  //     delay(3000);
  //     Serial.println("Left");
  //   }
  //   else if (count == 2) {
  //     moveMotorForward();
  //     delay(200);
  //     turnRight();
  //     delay(450);
  //     stopMotors();
  //     delay(3000);
  //     //      Serial.println("Right");
  //   }
  //   else if (count == 0) {
  //     moveMotorForward();
  //     delay(100);
  //   }
  //   //    Serial.print("count: ");
  //   //    Serial.println(count);


  // }
  



  // เชคถ้าไม่เจอเส้นดำ หรือ ถ้าเป็นขาวหมด
  // if ((sensorValue1 == 1 && sensorValue2 == 1 && sensorValue3 == 1 && sensorValue4 == 1 && sensorValue5 == 1) ||
  //     sensorValue1 == 0 && sensorValue2 == 0 && sensorValue3 == 0 && sensorValue4 == 0 && sensorValue5 == 0) {
  //   moveMotorForward();
  //   delay(100);
  //   stopMotors();
  //   timer = millis();
  //   // Wait for 2 sec to check again
  //   while (millis() - timer < 500) {
  //     updateSensorValues();
  //   }


  //   // Start turning right
  //   timer = millis();
  //   while (millis() - timer < 5000 && sensorValue1 == 1 && sensorValue2 == 1 && sensorValue3 == 1 && sensorValue4 == 1 && sensorValue5 == 1) {
  //     turnRight();
  //     delay(100);
  //     stopMotors(); // Stop after each small turn
  //     delay(100); // Short delay before next movement
  //     updateSensorValues(); // Check sensor values after the turn
  //     if (sensorValue3 == 0) {
  //       turnRight();
  //       break;
  //     } // If middle sensor finds the line, break out
  //   }

  //   // If no line found on left, try turning left
  //   timer = millis();
  //   while (millis() - timer < 10000 && sensorValue1 == 1 && sensorValue2 == 1 && sensorValue3 == 1 && sensorValue4 == 1 && sensorValue5 == 1) {
  //     turnLeft();
  //     delay(100);
  //     stopMotors(); // Stop after each small turn
  //     delay(100); // Short delay before next movement
  //     updateSensorValues(); // Check sensor values after the turn
  //     if (sensorValue3 == 0) {
  //       turnLeft();
  //       break; // If middle sensor finds the line, break out
  //     }
  //   }

  //   timer = millis();
  //   while (millis() - timer < 5000 && sensorValue1 == 1 && sensorValue2 == 1 && sensorValue3 == 1 && sensorValue4 == 1 && sensorValue5 == 1) {
  //     turnRight();
  //     delay(100);
  //     stopMotors(); // Stop after each small turn
  //     delay(100); // Short delay before next movement
  //     updateSensorValues(); // Check sensor values after the turn
  //     if (sensorValue3 == 0) {
  //       turnRight();
  //       break;
  //     } // If middle sensor finds the line, break out
  //   }
  //   moveMotorForward();
  //   delay(75);
  //   stopMotors(); // Ensure motors stop after turning
  //   updateSensorValues(); // Update sensor values after all turns

  // }





}

void moveMotorForward() {
  digitalWrite(mrb, LOW);
  digitalWrite(mrf, HIGH);
  digitalWrite(mlf, HIGH);
  digitalWrite(mlb, LOW);
  analogWrite(enaRight, 80);//251 //93
  analogWrite(enaLeft, 73);//255 //79
}

void turnRight() {
  digitalWrite(mrb, HIGH);
  digitalWrite(mrf, LOW);
  digitalWrite(mlf, HIGH);
  digitalWrite(mlb, LOW);
  analogWrite(enaRight, 85);//155
  analogWrite(enaLeft, 85);//255
}



void turnLeft() {
  digitalWrite(mrb, LOW);
  digitalWrite(mrf, HIGH);
  digitalWrite(mlf, LOW );
  digitalWrite(mlb, HIGH);
  analogWrite(enaRight, 85);//255
  analogWrite(enaLeft, 85);//155
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
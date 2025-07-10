// table leveling sketch
// 7 July 2025 T-RC

// libraries 
// wire comes as part of Arduino IDE
#include<Wire.h>

// define tags
uint16_t LevelingTimer = 0;   // leveling in progress when greater than zero
const int MPU=0x68;           // I2C address of MPU
int32_t AcX,AcY,AcZ,Tmp;      // raw accelerometer values from MPU
int32_t AverageX, AverageY;   // moving averages of accelerometer reads; to reduce signal noise
int32_t LevelWindow =  75;    // target accuracy of leveling; leveling stops once all legs are in range
double temperature;           // Temperature in Degrees C;
uint32_t counter = 0;         // to slow down serial data amount
int32_t X_Offset =  -400;
int32_t Y_Offset =  200;

// assign IOs
int UpButton    = 10;
int DownButton  = 11;
int LevelButton = 12;
int PwrRelay1   =  2;
int PwrRelay2   =  3;
int PwrRelay3   =  4;
int PwrRelay4   =  5;
int Motor1      =  6;
int Motor2      =  7;
int Motor3      =  8;
int Motor4      =  9;


void setup(){
// communication to MPU
Wire.begin();
Wire.beginTransmission(MPU);
Wire.write(0x6B);
Wire.write(0);
Wire.endTransmission(true);
//
// setup IOs
  // PushButtons
  pinMode(UpButton, INPUT);
  pinMode(DownButton, INPUT);
  pinMode(LevelButton, INPUT);
  // power reversing relays; HIGH means off!
  pinMode(PwrRelay1, OUTPUT);
  digitalWrite(PwrRelay1, HIGH);
  pinMode(PwrRelay2, OUTPUT);
  digitalWrite(PwrRelay2, HIGH);
  pinMode(PwrRelay3, OUTPUT);
  digitalWrite(PwrRelay3, HIGH);
  pinMode(PwrRelay4, OUTPUT);
  digitalWrite(PwrRelay4, HIGH);
  // motor relays; HIGH means power is off!
  pinMode(Motor1, OUTPUT);
  digitalWrite(Motor1, HIGH);
  pinMode(Motor2, OUTPUT);
  digitalWrite(Motor2, HIGH);
  pinMode(Motor3, OUTPUT);
  digitalWrite(Motor3, HIGH);
  pinMode(Motor4, OUTPUT);
  digitalWrite(Motor4, HIGH);
//
// open serial port for troubleshooting 
Serial.begin(115200);
}

void loop(){
  // prepare the MPU, read the data, calculate averages
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,8,true);
  AcX=((Wire.read()<<8|Wire.read())+X_Offset);
  AcY=((Wire.read()<<8|Wire.read())+Y_Offset);
  AcZ=(Wire.read()<<8|Wire.read());
  Tmp=(Wire.read()<<8|Wire.read());
  temperature = (Tmp - 1600)/340 + 36.53;
  AverageX = ((AverageX * 95) + (AcX * 5))/100;
  AverageY = ((AverageY * 95) + (AcY * 5))/100;

  // process IOs
  // move up per up-button
  if (digitalRead(UpButton) == HIGH) {
    digitalWrite(PwrRelay1, LOW);
    digitalWrite(PwrRelay2, HIGH);
    digitalWrite(PwrRelay3, HIGH);
    digitalWrite(PwrRelay4, LOW);
    digitalWrite(Motor1, LOW);
    digitalWrite(Motor2, LOW);
    digitalWrite(Motor3, LOW);
    digitalWrite(Motor4, LOW);
    LevelingTimer = 0;
  }
  // move down per down-button
  else if (digitalRead(DownButton) == HIGH) {
    digitalWrite(PwrRelay1, HIGH);
    digitalWrite(PwrRelay2, LOW);
    digitalWrite(PwrRelay3, LOW);
    digitalWrite(PwrRelay4, HIGH);
    digitalWrite(Motor1, LOW);
    digitalWrite(Motor2, LOW);
    digitalWrite(Motor3, LOW);
    digitalWrite(Motor4, LOW);
    LevelingTimer = 0;
  }
  //intiate leveling per level-button
  else if (digitalRead(LevelButton) == HIGH) {
    digitalWrite(PwrRelay1, LOW);
    digitalWrite(PwrRelay2, HIGH);
    digitalWrite(PwrRelay3, HIGH);
    digitalWrite(PwrRelay4, LOW);
    LevelingTimer = 50;
  }
  // level the table
  else if (LevelingTimer > 0) { 
    if (AverageX >= LevelWindow) {digitalWrite(Motor1, LOW); } else { digitalWrite(Motor1, HIGH); }
    if (AverageY >= LevelWindow) {digitalWrite(Motor2, LOW); } else { digitalWrite(Motor2, HIGH); }
    if (AverageX <= -LevelWindow) {digitalWrite(Motor3, LOW); } else { digitalWrite(Motor3, HIGH); }
    if (AverageY <= -LevelWindow) {digitalWrite(Motor4, LOW); } else { digitalWrite(Motor4, HIGH); }
    LevelingTimer--; 
  }
  else { // turn off power, all motors, and reset all level flags if nothing else is happening
    digitalWrite(PwrRelay1, HIGH);
    digitalWrite(PwrRelay2, HIGH);
    digitalWrite(PwrRelay3, HIGH);
    digitalWrite(PwrRelay4, HIGH);
    digitalWrite(Motor1, HIGH);
    digitalWrite(Motor2, HIGH);
    digitalWrite(Motor3, HIGH);
    digitalWrite(Motor4, HIGH);
  } //end of IO processing

  //send troubleshooting data to the serial port
    if (counter % 10 == 0) {
      Serial.print(counter);   
      Serial.print("\t"); Serial.print(digitalRead(UpButton));  
      Serial.print("\t"); Serial.print(digitalRead(DownButton));  
      Serial.print("\t"); Serial.print(digitalRead(LevelButton));
      Serial.print("\t"); Serial.print(LevelingTimer);
      Serial.print("\tX = \t"); Serial.print(AverageX);
      Serial.print("\t Y = \t"); Serial.print(AverageY);
      Serial.print("\t Temp(C) = "); Serial.println(temperature);
    }

  counter++;
  delay(50); // end of loop - slow down processing to not overload the MPU and relays
} //end of void loop

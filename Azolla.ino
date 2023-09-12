#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <CytronMotorDriver.h>
#define FAN 7
#define WB 2
#define M1pin 10
#define M2pin 9
#define UVpin A0
#define R3V3 A1
#define PUMP_P 5
#define PUMP_D 6
#define TEC_P 3
#define TEC_D 4
Servo M1;
Servo M2;
OneWire oneWire(WB);
DallasTemperature sensors(&oneWire);
CytronMD TEC(PWM_DIR, TEC_P, TEC_D);
CytronMD PUMP(PWM_DIR, PUMP_P, PUMP_D);

void setup() {
  sensors.begin();
  Serial.begin(9600);
  pinMode(UVpin, 0);
  pinMode(R3V3, 0);
  pinMode(FAN, 1);
  M1.write(180);
  M2.write(0);
  M1.attach(M1pin);
  M2.attach(M2pin);
  digitalWrite(FAN, 0);
}

void loop() {
  Serial.print("Temperature: ");
  Serial.print(temp());
  Serial.println(" °C");
  delay(1000);
  * / Serial.print("UV index: ");
  Serial.println(UVindex());
  delay(1000);
  if (temp() < 24) {
    while (temp() < 25) {
      heat();
      Serial.println("Heating in progress ");
      Serial.print("Temperature: ");
      Serial.print(temp());
      Serial.println(" °C");
    }
  } else if (temp() > 26) {
    while (temp() > 25) {
      cool();
      Serial.println("Cooling in progress ");
      Serial.print("Temperature: ");
      Serial.print(temp());
      Serial.println(" °C");
    }
  } else {
    stop();
    Serial.println("Temperature is in range ");
    Serial.print("Temperature: ");
    Serial.print(temp());
    Serial.println(" °C");
    Serial.print("UV index: ");
    Serial.print(UVindex());
  }
  if (UVindex() > 7) {
    Serial.print("UV index: ");
    Serial.print(UVindex());
    delayMicroseconds(3);
    cover();
    Serial.print("Temperature: ");
    Serial.print(temp());
    Serial.println(" °C");
  } else {
    Serial.print("UV index: ");
    Serial.print(UVindex());
    delayMicroseconds(3);
    uncover();
    Serial.print("Temperature: ");
    Serial.print(temp());
    Serial.println(" °C");
  }
  delayMicroseconds(3);
}

float temp() {
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}

void heat() {
  TEC.setSpeed(-255);
  PUMP.setSpeed(255);
  digitalWrite(FAN, 1);
}

void cool() {
  TEC.setSpeed(255);
  PUMP.setSpeed(255);
  digitalWrite(FAN, 1);
}

void stop() {
  TEC.setSpeed(0);
  PUMP.setSpeed(0);
  digitalWrite(FAN, 0);
}

float UVindex() {
  byte numberOfReadings = 8;
  unsigned int runningValue1 = 0;
  for (int x = 0; x < numberOfReadings; x++)
    runningValue1 += analogRead(UVpin);
  runningValue1 /= numberOfReadings;
  unsigned int runningValue2 = 0;
  for (int x = 0; x < numberOfReadings; x++)
    runningValue2 += analogRead(R3V3);
  runningValue2 /= numberOfReadings;
  float outV = 3.3 / runningValue2 * runningValue1;
  float UVindx = (outV - 0.983) * (60 - 0) / (2.8 - 0.983) + 0;
  return UVindx;
}

void cover() {
  for (int x = 0; x < 180; x++) {
    M1.write(180 - x);
    M2.write(x);
    delay(39);
  }
}

void uncover() {
  for (int y = 180; y > 0; y--) {
    M1.write(180 - y);
    M2.write(y);
    delay(39);
  }
}
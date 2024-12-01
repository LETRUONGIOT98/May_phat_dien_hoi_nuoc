#include "HX710B.h"
 
const int DOUT = A0;   //sensor data pin
const int SCLK  = A1;   //sensor clock pin
 
HX710B pressure_sensor; 
 #define van 4
 #define bom 5
 #define nhiet 3
 int nguong = 20;
 long time;
void setup() {
  pinMode(van, OUTPUT);
  pinMode(bom, OUTPUT);
  pinMode(nhiet, INPUT_PULLUP);
  Serial.begin(9600);
  pressure_sensor.begin(DOUT, SCLK);
}
 
void loop() {
 if(millis()- time >= 1000){
  if (pressure_sensor.is_ready()) {
    Serial.print("Pascal: ");
    Serial.println(pressure_sensor.pascal());
    Serial.print("ATM: ");
    Serial.println(pressure_sensor.atm());
    Serial.print("mmHg: ");
    Serial.println(pressure_sensor.mmHg());
    Serial.print("PSI: ");
    Serial.println(pressure_sensor.psi());
  } else {
    Serial.println("Pressure sensor not found.");
  }
  time = millis();
 }

 if(digitalRead(nhiet) ==  1){
  digitalWrite(bom, HIGH);
  delay(10000);
 }
 else digitalWrite(bom, LOW);
int apsuat =pressure_sensor.psi();
 if(apsuat >= nguong){
  digitalWrite(van, HIGH);
  digitalWrite(bom, LOW);
 }
 else digitalWrite(van, LOW);

}

#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include <LiquidCrystal.h>
SoftwareSerial s(8,9);
#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int Contrast = 100;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  s.begin(9600);
  pinMode(A2,INPUT);
  pinMode(A0,INPUT);
  lcd.begin(16, 2);
  analogWrite(6,Contrast);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root=jsonBuffer.createObject();
  int i=0;
    if(i==0){
     int mq_a=analogRead(A0);
    Serial.print("Air quality measured by MQ135: ");
    Serial.print(mq_a);
    Serial.println("PPM");
    lcd.setCursor(0,0);
    lcd.print("Air quality: ");
    lcd.print(mq_a);
    root["data1"]=mq_a;
    delay(1000);
    i=i+1;
    }
    if(i==1){
      int val = analogRead(A2);
      Serial.print("Light intensity:");
      Serial.println(val);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Light_int: ");
      lcd.print(val);
      root["data2"]=val;
      delay(1000);
      i=0;
    }

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  t=t+10;
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    root["data3"]=0;
    root["data4"]=0;
    if(s.available()>0){
    Serial.println("DONE");
    root.printTo(s);
  }
  delay(2000);
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(h);
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  delay(1000);
  root["data3"]=h;
  root["data4"]=t;
  if(s.available()>0){
    Serial.println("DONE");
    root.printTo(s);
  }
}

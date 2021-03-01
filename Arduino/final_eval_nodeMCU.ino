#include <ESP8266WiFi.h>
#include<FirebaseArduino.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(D6,D5);

#define WIFI_SSID "dlink"
#define WIFI_PASSWORD "08242523"

#define FIREBASE_HOST "fir-2-7d97f.firebaseio.com"
#define FIREBASE_AUTH "TA0B6ZfNbWn4VHsMVCAEFXEcxVIDfEi7hKdHxq2P"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s.begin(9600);
  while (!Serial) continue;
  delay(1000);
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

   Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                              // connect to firebase
}

void loop() {
  // put your main code here, to run repeatedly:
  s.write("S");
  //Serial.println("HI");
  if(s.available()>0){
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
  if (root == JsonObject::invalid())
    return;

    Serial.println("JSON received and parsed");
  root.prettyPrintTo(Serial);
  Serial.print("Data 1 ");
  Serial.println("");
  int data1=root["data1"];
  Serial.print(data1);
  Serial.print("Data 2 ");
  Serial.println("");
  int data2=root["data2"];
  Serial.print(data2);
  Serial.print("Data 3 ");
  Serial.println("");
  int data3=root["data3"];
  Serial.print(data3);
  Serial.print("Data 4 ");
  Serial.println("");
  int data4=root["data4"];
  Serial.print(data4);
  Serial.println("");
  Serial.println("---------------------xxxxx--------------------");

  String i = String("Air qulatily: ")+ String(data1) + String(" PPM");  
  String j = String("Light intensity: ")+ String(data2);
  String k = String("Humidity: ")+ String(data3);
  String l = String("Temperature: ")+ String(data4)+ String(" *C"); 
  Serial.println(i);
  Serial.println(j);
  Serial.println(k);
  Serial.println(l);

   Firebase.setString("/KVV/a/", i);                                  //setup path and send readings
  Firebase.setString("/KVV/b/", j); //setup path and send readings
  if(data3!=0&&data4!=0){
    Firebase.setString("/KVV/c/", k);
    Firebase.setString("/KVV/d/", l); 
  }

}
}

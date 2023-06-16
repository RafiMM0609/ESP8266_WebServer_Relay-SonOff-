#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClientSecure.h>
#include <Arduino.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
//=============================================================YANG HARUS DIGANTI============================================================
IPAddress local_IP(0, 0, 0, 0); // Set your Static IP address  
IPAddress gateway(0, 0, 0, 0); // Set your Gateway IP address  
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(0, 0, 0, 0); // usually same as Gateway IP
IPAddress secondaryDNS(8,8, 4, 4);
const char* ssid = "ABCDEFGH"; //WiFi SSID
const char* password = "120321479821694";  //WiFi Password
String GAS_ID = "AafashfklhLHOOjkl_8asdsadnGIKJ_jkbkabfiBBKBKbk8BKBjbn"; // Google Sheet ID Deployment
#include "html.h"
#include "space.h"
//================================================================VOID SETUP=======================================================
void setup() {
 pinMode(gpio13Led, OUTPUT);
 digitalWrite(gpio13Led, LOW);
 pinMode(gpio12Relay, OUTPUT);
 digitalWrite(gpio12Relay, LOW);
 // Configures static IP address to ESP8266
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
  Serial.println("STA Failed to configure");
  }
 //WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 Serial.begin(115200);
 delay(5000);
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  client.setInsecure();
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
    j = 1;
  });
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    if (request->hasParam(PARAM_INPUT_6)) {
          nama = request->getParam(PARAM_INPUT_1)->value();
          nim = request->getParam(PARAM_INPUT_2)->value();
          nohp = request->getParam(PARAM_INPUT_3)->value();
          asal = request->getParam(PARAM_INPUT_4)->value();
          kesibukan = request->getParam(PARAM_INPUT_5)->value();
          linkktm = request->getParam(PARAM_INPUT_6)->value();
    }
    else {
          nama = "No message sent";
          nim = "No message sent";
          nohp = "No message sent";
          asal = "No message sent";
          kesibukan = "No message sent";
          linkktm = "No message sent";
          
    }
    Serial.println(nama);
    Serial.println(nim);
    Serial.println(nohp);
    Serial.println(asal);
    Serial.println(kesibukan);
    Serial.println(linkktm);
   if(nama==""||nim==""||nohp==""||kesibukan==""||linkktm==""||asal==""){
    request->send_P(200, "text/html", index_html);
    }else{request->send(200, "text/html", welcome);
   digitalWrite(gpio13Led, HIGH); //Off
   digitalWrite(gpio12Relay, HIGH); //Open
   }
   });
   server.on("/back", HTTP_GET, [](AsyncWebServerRequest *request){
     request->send_P(200, "text/html", index_html);
   });
   server.onNotFound(notFound);
   server.begin();
   Serial.println("HTTP server started");
}
//================================================================VOID LOOP=======================================================
void loop() {
  digitalWrite(gpio13Led, LOW);
  digitalWrite(gpio12Relay, LOW);
  Serial.println(WiFi.localIP());
  delspace();
  if(nama==""||nim==""||nohp==""||kesibukan==""||linkktm==""||asal==""){
  Serial.println("fail");
  }else{
    sendData1(nama, nim, nohp, asal, kesibukan, linkktm);
  }
  pembersihan();
  delay(1000);
 }

void baru(){

println("siiuù")

}
//TAMPILAN WEB 5 FORM DAN 1 TOMBOL SUBMIT
//Bisa konek ke googlesheet
//Bisa kirim ke gsheet
//ada verifikasi jika kolom 1 tidak diisi led tidak mau mati
//Relay Sudah Bisa
//Bisa pakai spasi
//Desain web v 0.0.1
//Menggunakan IP Static
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClientSecure.h>
#include <Arduino.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
IPAddress local_IP(10, 88, 12, 192); // Set your Static IP address
IPAddress gateway(10, 88, 12, 1); // Set your Gateway IP address
IPAddress subnet(255, 255, 0, 0);

//=============================================================Wifi dan Google Sheet ID============================================================
const char* ssid = "RUANGAN BAGUS"; //Nama WiFi
const char* password = "bagus123";  //Password WiFi
String GAS_ID = ""; // ID Deploymen
#include "html.h"
#include "space.h"
//================================================================VOID SETUP=======================================================
void setup() {
 // Configures static IP address
  if (!WiFi.config(local_IP, gateway, subnet)) {
      Serial.println("STA Failed to configure");
    }
 pinMode(gpio13Led, OUTPUT);
 digitalWrite(gpio13Led, LOW);
 pinMode(gpio12Relay, OUTPUT);
 digitalWrite(gpio12Relay, HIGH);
 WiFi.mode(WIFI_STA);
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
//==========================================================================WEBSERVER===========================================================================
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
    j = 1;
  });
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    if (request->hasParam(PARAM_INPUT_5)) {
          nama = request->getParam(PARAM_INPUT_1)->value();
          mitra = request->getParam(PARAM_INPUT_2)->value();
          nohp = request->getParam(PARAM_INPUT_3)->value();
          keperluan = request->getParam(PARAM_INPUT_4)->value();
          det_keg = request->getParam(PARAM_INPUT_5)->value();
    }
    else {
          nama = "No message sent";
          mitra = "No message sent";
          nohp = "No message sent";
          keperluan = "No message sent";
          det_keg = "No message sent";
          
    }
    Serial.println(nama);
    Serial.println(mitra);
    Serial.println(nohp);
    Serial.println(keperluan);
    Serial.println(det_keg);
   if(nama==""||mitra==""||nohp==""||det_keg==""||keperluan==""){
    request->send_P(200, "text/html", index_html);
    }else{request->send(200, "text/html", welcome);}
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
 digitalWrite(gpio12Relay, HIGH);
 delspace();
 if (j > 1){
 Serial.println(WiFi.localIP());} 
 else {}
 if(nama==""||mitra==""||nohp==""||det_keg==""||keperluan==""){
 Serial.println("fail");
 }else{
    sendData(nama, mitra, nohp, keperluan, det_keg);
    digitalWrite(gpio13Led, HIGH);//Mati
    digitalWrite(gpio12Relay, LOW);//buka
    Serial.print("Berhasil Dikirim");
 }
  pembersihan();
  delay(5000);
 }

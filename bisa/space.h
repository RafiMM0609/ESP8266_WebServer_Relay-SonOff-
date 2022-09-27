//======================================Variabel Global================================================
const char* PARAM_INPUT_1 = "nama";
const char* PARAM_INPUT_2 = "nim"; 
const char* PARAM_INPUT_3 = "nohp";
const char* PARAM_INPUT_4 = "asal";
const char* PARAM_INPUT_5 = "kesibukan";
const char* PARAM_INPUT_6 = "linkktm";
const char* host = "script.google.com";
const int httpsPort = 443;
int i =1;
int j = 2;
int gpio13Led = 13;
int gpio12Relay = 12;
String nama;
String nim;
String nohp;
String asal;
String kesibukan;
String linkktm;
AsyncWebServer server(255);// SERVICE PORT <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
MDNSResponder mdns;
WiFiClientSecure client;
//================================================================VOID sendData=======================================================
void sendData1(String nama, String nim, String nohp, String asal, String kesibukan, String linkktm) {
  Serial.println("==========");
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  //-------------------------deklarasi variabel lokal
  String string_nama =  String(nama);
  String string_nim = String(nim);
  String string_nohp = String(nohp);
  String string_asal = String(asal);
  String string_kesibukan = String(kesibukan);
  String string_linkktm = String(linkktm);
  String url = ("https://script.google.com/macros/s/" + GAS_ID + 
  "/exec?nama=" + string_nama +
  "&nim=" + string_nim +
  "&nohp=" + string_nohp +
  "&asal=" + string_asal +
  "&kesibukan=" + string_kesibukan+ +
  "&linkktm=" + linkktm);
  //-----------------kode pengiriman ke google sheet
  Serial.print("requesting URL: ");
  Serial.println(url);
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" +
         "User-Agent: BuildFailureDetectorESP8266\r\n" +
         "Connection: close\r\n\r\n");
  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  Serial.print("reply was : ");
  Serial.println(line);
  Serial.println("closing connection");
  Serial.println("==========");
  Serial.println();
}
//================================================================VOID notFound=======================================================
void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
  }
//================================================================VOID delspace================================================
 void delspace(){
 int a = nama.length();
 int b = nim.length();
 int c = nohp.length();
 int d = asal.length();
 int e = kesibukan.length();
 int f = linkktm.length();
 for (int i = 0; i <a; i++){
   if(nama[i] == ' '){
     nama.replace(nama[i],'|');
   }else{}}
 for (int i = 0; i <b; i++){
   if(nim[i] == ' '){
    nim.replace(nim[i],'|');
   }else{}}
 for (int i = 0; i <c; i++){
  if(nohp[i] == ' '){
    nohp.replace(nohp[i],'|');
  }else{}}
 for (int i = 0; i <d; i++){
  if(asal[i] == ' '){
     asal.replace(asal[i],'|');
  }else{}}
 for (int i = 0; i <e; i++){
  if(kesibukan[i] == ' '){
     kesibukan.replace(kesibukan[i],'|');
  }else{}}
for (int i = 0; i <f; i++){
  if(linkktm[i] == ' '){
    linkktm.replace(linkktm[i],'|');
  }else{}}
}
//============================================================VOID Pembersihan=============================================================================
void pembersihan(){
 nama = "";
 nim = "";
 nohp = "";
 asal = "";
 kesibukan = "";
 linkktm="";
 }

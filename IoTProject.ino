#include <WiFi.h>
#include <WebServer.h>
#include <ThingSpeak.h>

#include "html.h"
#include "GetData.h"

int CH_ID = 2081084;
const char* APIKEY = "6SJTC8U71JEC0NBJ";

void handleTempFetch();
void handleDistFetch();
void handleFlowFetch();
void handleSlider();
void handleMaxDistFetch();
void handleSetDist();
void handle_OnConnect();
void handle_NotFound();

const char* ssid = "Declan";        // Enter SSID here
const char* password = "Deccy123";  //Enter Password here

//const char* ssid = "Esp32";  // Enter SSID here
//const char* password = "12345678";  //Enter Password here

String htmlPage = MainPage;

WebServer server(80);
WiFiClient  client;
float flow = 0; 

void setup() {
  Serial.begin(115200);
  pinMode(motorPin, OUTPUT);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected..!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.on("/getTemp", handleTempFetch);
  server.on("/getDist", handleDistFetch);
  server.on("/getFlow", handleFlowFetch);
  server.on("/getSlide", handleSlider);
  server.on("/getMaxDist", handleMaxDistFetch);
  server.on("/setMaxDistance", handleSetDist);

  server.onNotFound(handle_NotFound);

  server.begin();
  ThingSpeak.begin(client);
  ConfigPins();
 }

void loop() {
  server.handleClient();
 }

void handle_OnConnect() {
  server.send(200, "text/html", htmlPage);
 }

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
 }

 void handleFlowFetch() {
  flow = GetFlow();
  int flowTS = (int)flow;
  ThingSpeak.writeField(CH_ID, 1, flow, APIKEY);
  server.send(200, "text/plain", String(flow));
 }

void handleDistFetch() {
  String distStr = GetDistance();
  int dist = distStr.toInt();
  ThingSpeak.writeField(CH_ID, 4, dist, APIKEY);
  server.send(200, "text/plain", distStr);
 }

void handleTempFetch() {
  String tempStr = GetTemp();
  int temp = tempStr.toInt();
  ThingSpeak.writeField(CH_ID, 3, temp, APIKEY);
  server.send(200, "text/plain", tempStr);
 }

void handleSlider() {
  String sliderValue = server.arg("value");
  int timeOut = sliderValue.toInt();
  Serial.print(timeOut);
  SetTimeOut(timeOut);
 }

void handleMaxDistFetch() {
  String rangeStr = MaxRange();
  server.send(200, "text/plain", rangeStr);
 }

void handleSetDist() {
  SetMaxRange();
 }



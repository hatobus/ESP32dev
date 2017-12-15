#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <HttpClient.h>
#include <ArduinoOTA.h>

const char ssid[] = "YOUR-SSID";
const char passwd[] = "YOUR-WIFI-PASSWD";

const int read_sw = 12;
const int ledPin = 13;

const String slack_hook_url = "SLACK-WEBHOOK-URL";
const String slack_icon = ":door:";
const String slack_message = "トビラガアイタヨー";
const String slack_username = "Kaihei-Oshiete-Kureru-Kun";
const String slack_channel = "#general";

void setup() {
  pinMode(read_sw, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  delay(100);

  Serial.println("\nTrying to connect");
  //To start Wi-Fi
  WiFi.begin(ssid, passwd);
  
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  ArduinoOTA.onStart([]() {
    Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
ArduinoOTA.begin();

} 


bool postMessageToSlack(String msg)
{
  const char* host = "hooks.slack.com";
  Serial.print("Connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClientSecure client;
  const int httpsPort = 443;
  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection failed :-(");
    return false;
  }

  // We now create a URI for the request

  Serial.print("Posting to URL: ");
  Serial.println(slack_hook_url);

  String postData="payload={\"channel\": \"" + slack_channel + "\",  \"icon_emoji\": \"" + slack_icon + "\", \"username\": \"" + slack_username + "\", \"text\": \"" + msg + "\"}";

  // This will send the request to the server
  client.print(String("POST ") + slack_hook_url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Content-Type: application/x-www-form-urlencoded\r\n" +
               "Connection: close" + "\r\n" +
               "Content-Length:" + postData.length() + "\r\n" +
               "\r\n" + postData);
  Serial.println("Request sent");
  String line = client.readStringUntil('\n');
  Serial.printf("Response code was: ");
  Serial.println(line);
  if (line.startsWith("HTTP/1.1 200 OK")) {
    return true;
  } else {
    return false;
  }
}


void loop()
{
  // Start handling OTA updates
  ArduinoOTA.handle();
  int swVal = digitalRead(read_sw);
  if (!swVal) {
    bool ok = postMessageToSlack(slack_message);
    if (ok) {
      digitalWrite(ledPin, HIGH);
      delay(1000);
    }
    while (!digitalRead(read_sw)) delay(100);
  }
  digitalWrite(ledPin, LOW);
  delay(1000);
}

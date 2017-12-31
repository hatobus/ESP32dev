#include <ESP8266WIFI.h>
#include <HttpClient.h>

const int LED_CORRECT = 13;
const int ASSERT_LED = 12;
const char ssid[] = "";
const char passwd[] = "";

void setup(){ 
    int retries = 0;

    pinMode(LEDPIN, OUTPUT);
    Serial.begin(115200);
    delay(100);

    Serial.println("\n Trying to connect");

    //To start Wi-Fi
    WIFI.begin(ssid, passwd);

    // TODO
    // WIFI.beginの返り値によってBlinkさせるLEDを変更する.
    // Ex)
    // 正しい時 -> pin 13
    // 繋がらない時 -> pin12

    while((WIFI.status() != WL_CONNECTED) && (retries < 5)){
        retries++;
        Serial.println("Connecting ...");
        tikatika(ASSERT_LED);
    }

    if(WIFI.status() == WL_CONNECTED){
        Serial.println(ssid + "Connected");
        tikatika(LED_CORRECT);
        delay(10);
    }

    else{
        Serial.println(ssid + "is not Connected");
        delay(10);
    }

}

void tikatika(int PIN){
    for(int i=0; i < 5; i++){

        digitalWrite(PIN, HIGH);
        delay(1000);

        digitalWrite(PIN, LOW);
        delay(1000);

    }
}

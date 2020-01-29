#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <dht.h>
#define dht_apin A0
dht DHT;
#define WLAN_SSID     ""
#define WLAN_PASSWORD ""
ESP8266WebServer server(80);

float temperature, humidity;
unsigned long previousMillis = 0;
const long interval = 2000;

void setup() {
    Serial.begin(115200);
    DHT.read11(dht_apin);
    delay(10);
    humidity = DHT.humidity;
    temperature = DHT.temperature;
    Serial.println(); Serial.println();
    Serial.print("Connecting to ");
    Serial.println(WLAN_SSID);

    WiFi.mode(WIFI_STA);
    WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();

    Serial.println("WiFi connected");
    Serial.println("IP address: "); Serial.println(WiFi.localIP());

    server.on("/dht11", HTTP_GET, [](){
        unsigned long currentMillis = millis();

        if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;
            DHT.read11(dht_apin);
            humidity = DHT.humidity;
            temperature = DHT.temperature;
            if (isnan(humidity) || isnan(temperature)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
        }

        String webString = "Humiditiy " + String((int)humidity) + "%   Temperature: " + String((int)temperature) + " C";
        Serial.println(webString);
        server.send(200, "text/plain", webString);
    });
    server.on("/dht11.json", [](){
        unsigned long currentMillis = millis();

        if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;
            DHT.read11(dht_apin);
            humidity = DHT.humidity;
            temperature = DHT.temperature;
            if (isnan(humidity) || isnan(temperature)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }

            Serial.println("Reporting " + String((int)temperature) + "C and " + String((int)humidity) + " % humidity");
        }

        StaticJsonDocument<200> doc;
        doc["temperature"] = temperature;
        doc["humidity"] = humidity;
        String content="";
        serializeJsonPretty(doc, Serial);
        serializeJsonPretty(doc, content);
        server.send(200, "application/json", content);
    });

    server.begin();
    Serial.println("HTTP server started! Waiting for clients!");
}

void loop() {
    server.handleClient();
}

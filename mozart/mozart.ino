#include <WiFi.h>

#include <PubSubClient.h>

#include <ArduinoJson.h>

WiFiClient espClient;
PubSubClient client(espClient);

const int N_PORT = 4; // จำนวน port
const int PORTS[] = {
    19,
    18,
    5,
    17
}; // port ต่างๆ

const char * WIFI_SSID = "sulaksana_2.4 GHz"; // ชื่อ wifi
const char * WIFI_PWD = "truetp24"; // รหัส wifi

const char * SUBSCRIBE_CHANNEL = "stream/1*D%KjdYng!r"; // channel ใช้ในการสื่อสารใน mqtt broker

const char * MQTT_SERVER = "broker.mqttdashboard.com"; // mqtt server
const int MQTT_PORT = 1883; // mqtt port

// function สำหรับ reconnect mqtt ใหม่
void reconnectmqttserver() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        String clientId = "ESP32Client-";
        clientId += String(random(0xffff), HEX);
        if (client.connect(clientId.c_str())) {
            Serial.println("connected");
            client.subscribe(SUBSCRIBE_CHANNEL);
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

// function เวลาได้รับข้อมูลจาก mqtt
void callback(char * topic, byte * payload, unsigned int length) {
    String MQTT_DATA = "";
    for (int i = 0; i < length; i++) {
        MQTT_DATA += (char) payload[i];
    }

    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, MQTT_DATA);
    if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
    }

    const String action = doc["action"];
    const int port = doc["port"];

    if ((action == "on") || (action == "off")) {
        Serial.print("get data, action=");
        Serial.print(action);
        Serial.print(" port=");
        Serial.println(PORTS[port]);
        digitalWrite(PORTS[port], action == "off");
    }

}

// function รันทุกครั้งที่เปิด esp32
void setup() {
    Serial.begin(9600);
    for (int i = 0; i < N_PORT; i++) {
        pinMode(PORTS[i], OUTPUT);
        digitalWrite(PORTS[i], HIGH);
    }

    WiFi.disconnect();
    delay(3000);
    Serial.println("START");
    WiFi.begin(WIFI_SSID, WIFI_PWD);
    while ((!(WiFi.status() == WL_CONNECTED))) {
        delay(300);
        Serial.print("..");
    }
    Serial.println("Connected");
    Serial.println("Your IP is");
    Serial.println((WiFi.localIP()));
    client.setServer(MQTT_SERVER, MQTT_PORT);
    client.setCallback(callback);
}

// function วนลูบ
void loop() {

    // เช็ค ว่า mqtt connect อยู่ไหมถ้าไม่ reconnect ใหม่
    if (!client.connected()) {
        reconnectmqttserver();
    }
    // เรียก mqtt loop function
    client.loop();
}

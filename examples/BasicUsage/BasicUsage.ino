#include <Arduino.h>
#include <WiFiClient.h>
#include "ThingBootSDK.h"

thingboot::ThingBootDevice device;

void setup() {
    Serial.begin(115200);
    device.begin("dev_001");
    if (device.connect("192.168.1.100", 8080)) {
        Serial.println("Connected!");
        device.sendData("hello");
    }
}

void loop() {
    // 保持运行
}

<p align="right">
  English | <a href="./README.md">中文</a>
</p>

<h1 align="center">ThingBoot Device SDK</h1>
<p align="center">Precompiled Embedded IoT Development Library</p>

---

> ⚠️ **Commercial License Required**
> This is a **precompiled, closed-source library**. Use requires a valid per-device commercial license from ThingBoot.  
> Unauthorized redistribution, reverse engineering, or use beyond licensed device count is strictly prohibited.

---

## Features

- **Multi-Network**: Built-in WiFi, Ethernet, 4G Cat.1 and WiFi Mesh networking
- **Platform Communication**: Out-of-box MQTT/HTTPS connection to ThingBoot cloud with auto-reconnect and OTA support
- **Local Network Service**: Pure LAN mode with HTTP/TCP server for offline local control
- **Hardware Minimalism**: Developers only write peripheral drivers (LED, relay, sensor, etc.). Platform-side thing model handles the rest.
- **Precompiled & Closed-Source**: Distributed as `.a` static libraries + headers. Source code is not available.

## Supported Platforms

| Platform | MCU | Status |
|----------|-----|--------|
| ESP8266 | ESP8266EX | ✅ |
| ESP8285 | ESP8285 | ✅ |
| ESP32 | ESP32-WROOM / WROVER | ✅ |
| ESP32-S3 | ESP32-S3-WROOM | ✅ |
| ESP32-C6 | ESP32-C6 | ✅ |

## Quick Start

### 1. Add Dependency

In your `platformio.ini`:

```ini
[env:esp8266]
platform = espressif8266
board = esp12e
framework = arduino

; Critical: ABI compatibility flags must match SDK build
build_flags = 
    -fno-rtti
    -fno-exceptions
    -Os

lib_deps = https://github.com/ThingBoot/thingboot-device-sdk.git#v1.0.1
```

### 2. Include Header

```cpp
#include <Arduino.h>
#include <WiFiClient.h>
#include "ThingBootSDK.h"
```

### 3. Write Your Application

```cpp
thingboot::ThingBootDevice device;

void setup() {
    Serial.begin(115200);
    device.begin("your-device-id");
    
    if (device.connect("iot.thingboot.com", 8883)) {
        Serial.println("Connected to ThingBoot");
        device.sendData("{\"status\":\"online\"}");
    }
}

void loop() {
    device.loop();  // Keep SDK alive
    
    // Handle platform commands
    if (device.hasCommand()) {
        auto cmd = device.getCommand();
        if (cmd.type == "switch") {
            digitalWrite(RELAY_PIN, cmd.value == "on" ? HIGH : LOW);
        }
    }
}
```

## Directory Structure

```plain
lib/thingboot-device-sdk/
├── include/
│   └── ThingBootSDK.h          # Public API header
├── lib/
│   ├── libThingBootSDK_esp8266.a
│   ├── libThingBootSDK_esp32.a
│   └── libThingBootSDK_esp32s3.a
├── examples/
│   └── BasicUsage/
│       ├── BasicUsage.ino
│       └── platformio.ini
├── library.json
├── extra_script.py
├── README.md
├── README_EN.md
└── LICENSE.md
```

## ABI Compatibility Warning

The SDK is compiled with `-fno-rtti -fno-exceptions -Os`.
Your `platformio.ini` must include identical flags, or link-time / runtime errors will occur.

## Licensing & Billing

- **Per-Device License**: Each physical device flashed with firmware containing this SDK requires one license
- **Activation**: Devices must be registered on the [ThingBoot Console](https://console.thingboot.com) using the provided License Key
- **Purchase**: Contact `license@thingboot.com` or purchase via the ThingBoot Console

## Support

- Technical Support: `support@thingboot.com`
- Sales & Licensing: `license@thingboot.com`
- Documentation: [docs.thingboot.com](https://docs.thingboot.com)

---

**Copyright © 2026 ThingBoot Technology Co., Ltd. All rights reserved.**

<p align="right">
  <a href="./README_EN.md">English</a> | 中文
</p>

<h1 align="center">芯步设备 SDK</h1>
<p align="center">ThingBoot Device SDK — 预编译嵌入式物联网开发库</p>

---

> ⚠️ **商业授权须知**
> 本 SDK 为**预编译闭源库**，使用需获得芯步（ThingBoot）的按设备商业授权。  
> 严禁未经授权的再分发、逆向工程或超出授权设备数量的使用。

---

## 特性

- **全栈网络接入**：内置 WiFi、以太网、4G Cat.1 及 WiFi Mesh 组网
- **平台直连**：开箱即用的 MQTT/HTTPS 平台连接，支持自动重连与 OTA 升级
- **局域网服务**：纯局域网模式下开放 HTTP/TCP 接口，支持无网本地控制
- **硬件极简**：开发者仅需编写 LED、继电器、传感器等硬件驱动，平台端定义物模型即可完成功能闭环
- **预编译闭源**：以 `.a` 静态库 + 头文件分发，源码不开放

## 支持平台

| 平台 | 芯片 | 状态 |
|------|------|------|
| ESP8266 | ESP8266EX | ✅ |
| ESP8285 | ESP8285 | ✅ |
| ESP32 | ESP32-WROOM / WROVER | ✅ |
| ESP32-S3 | ESP32-S3-WROOM | ✅ |
| ESP32-C6 | ESP32-C6 | ✅ |

## 快速开始

### 1. 添加依赖

在 `platformio.ini` 中：

```ini
[env:esp8266]
platform = espressif8266
board = esp12e
framework = arduino

; 关键：ABI 兼容参数必须与 SDK 打包时一致
build_flags = 
    -fno-rtti
    -fno-exceptions
    -Os

lib_deps = https://github.com/ThingBoot/thingboot-device-sdk.git#v1.0.1
```

### 2. 包含头文件

```cpp
#include <Arduino.h>
#include <WiFiClient.h>
#include "ThingBootSDK.h"
```

### 3. 编写应用

```cpp
thingboot::ThingBootDevice device;

void setup() {
    Serial.begin(115200);
    device.begin("your-device-id");
    
    if (device.connect("iot.thingboot.com", 8883)) {
        Serial.println("已连接芯步平台");
        device.sendData("{\"status\":\"online\"}");
    }
}

void loop() {
    device.loop();  // 维持 SDK 心跳
    
    // 处理平台下发的命令
    if (device.hasCommand()) {
        auto cmd = device.getCommand();
        if (cmd.type == "switch") {
            digitalWrite(RELAY_PIN, cmd.value == "on" ? HIGH : LOW);
        }
    }
}
```

## 目录结构

```plain
lib/thingboot-device-sdk/
├── include/
│   └── ThingBootSDK.h          # 公共 API 头文件
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

## ABI 兼容警告

SDK 编译参数固定为 `-fno-rtti -fno-exceptions -Os`。
使用方 `platformio.ini` 必须包含相同参数，否则将出现链接错误或运行时异常。

## 授权与计费

- **按设备授权**：每台烧录了包含本 SDK 固件的物理设备需占用一个 License
- **激活方式**：设备在 [芯步平台](https://console.thingboot.com) 使用授权码注册激活
- **购买**：联系 `license@thingboot.com` 或通过芯步控制台购买

## 技术支持

- 技术支持：`support@thingboot.com`
- 销售授权：`license@thingboot.com`
- 官方文档：[docs.thingboot.com](https://docs.thingboot.com)

---

**版权所有 © 2026 芯步（ThingBoot）科技有限公司。保留所有权利。**

## Quick Start (ThingBoot SDK)

Basic usage example (in your project's `src/main.cpp`):

```cpp
#include "ThingBootSDK.h"

using namespace thingboot;

// simple LED driver example
void led_init() { /* init hardware */ }
void led_poll() { /* poll/update LED state */ }
void led_cmd(const char* cmd, const char* payload) { /* handle commands */ }

static const TBDriver LED_DRIVER = {"led", led_init, led_poll, led_cmd};

ThingBootDevice tb;

void setup() {
    tb.begin("device-001");
    tb.initWiFi("ssid","pass");
    tb.registerDriver(&LED_DRIVER);
    tb.connectToServer("iot.example.com", 8000);
}

void loop() {
    tb.loop();
}
```

See `include/ThingBootSDK.h` for the full public API.

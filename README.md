&lt;p align="right"&gt;
  &lt;a href="./README_EN.md"&gt;English&lt;/a&gt; | 中文
&lt;/p&gt;

&lt;h1 align="center"&gt;芯步设备 SDK&lt;/h1&gt;
&lt;p align="center"&gt;ThingBoot Device SDK — 预编译嵌入式物联网开发库&lt;/p&gt;

---

&gt; ⚠️ **商业授权须知**
&gt; 本 SDK 为**预编译闭源库**，使用需获得芯步（ThingBoot）的按设备商业授权。  
&gt; 严禁未经授权的再分发、逆向工程或超出授权设备数量的使用。

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
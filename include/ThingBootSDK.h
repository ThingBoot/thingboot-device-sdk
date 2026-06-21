#ifndef THINGBOOT_SDK_H
#define THINGBOOT_SDK_H
#include <Arduino.h>

// 版本号由 pack_lib.py 自动同步 VERSION 文件
#define THINGBOOT_SDK_VERSION "1.0.1"1.0.1""1.0.1""

namespace thingboot {

class ThingBootDevice {
public:
    void begin(const char* deviceId);
    bool connect(const char* host, uint16_t port);
    void sendData(const char* payload);
    void loop();
    bool hasCommand();
    // 根据你的实际 SDK 接口扩展
private:
    void* _impl;
};

} // namespace thingboot

#endif
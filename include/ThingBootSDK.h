#ifndef THINGBOOT_SDK_H
#define THINGBOOT_SDK_H

#include "common/system.h"
#include "driver/led.h"
#include "driver/btn.h"
#include "common/core.h"

// 版本号由 pack_lib.py 自动同步 VERSION 文件
#define THINGBOOT_SDK_VERSION "1.0.1"

#if defined(ESP8266) || defined(ESP32)
#include <functional>
#define TB_CALLBACK_EVENT std::function<void(SYS_STATE, bool)> tb_event_callback
#define TB_CALLBACK_CONFIG std::function<void(const char*, String)> tb_config_callback
#else
#define TB_CALLBACK_EVENT void (*tb_event_callback)(SYS_STATE, bool)
#define TB_CALLBACK_CONFIG void (*tb_config_callback)(const char*, String)
#endif

class ThingBootDevice {
private:
    TB_CALLBACK_EVENT;
    TB_CALLBACK_CONFIG;
public:
    ThingBootDevice();
    ~ThingBootDevice();

    ThingBootDevice& setEventCallback(TB_CALLBACK_EVENT);
    ThingBootDevice& setConfigCallback(TB_CALLBACK_CONFIG);

    String getVersion();

    void setup();
    void restart();

    // Main loop - call from application loop()
    void loop();
};

#endif // THINGBOOT_SDK_H
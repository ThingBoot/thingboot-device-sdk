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
#define TB_CALLBACK_CONFIG std::function<void(char*, uint8_t*, unsigned int)> callback
#else
#define TB_CALLBACK_CONFIG void (*callback)(char*, uint8_t*, unsigned int)
#endif

namespace thingboot {

// Callback types for drivers and commands
typedef void (*tb_driver_init_t)();
typedef void (*tb_driver_poll_t)();
typedef void (*tb_command_handler_t)(const char* command, const char* payload);

// Driver descriptor developers can fill for their hardware (LEDs, relays, sensors)
struct TBDriver {
    const char* name;                 // driver name, e.g. "led", "relay"
    tb_driver_init_t init;            // called once during startup
    tb_driver_poll_t poll;            // called regularly from SDK loop
    tb_command_handler_t onCommand;   // optional per-driver command handler
};

class ThingBootDevice {
private:
    TB_CALLBACK_CONFIG;
public:
    ThingBootDevice();
    ~ThingBootDevice();

    void setup();
    void restart();                          // request device restart

    // Network helpers (convenience wrappers)
    bool initWiFi(const char* ssid, const char* pass);
    bool initEthernet();                     // stub for wired init
    bool initCellular(const char* apn);      // stub for 4G/Cellular

    // Server connection + transport
    bool connectToServer(const char* host, uint16_t port);
    bool sendTelemetry(const char* jsonPayload);

    // Driver registration
    bool registerDriver(const TBDriver* driver);

    // Global command callback (for commands not handled by drivers)
    void registerCommandHandler(tb_command_handler_t handler);

    // Main loop - call from application loop()
    void loop();

    // Introspection
    const char* getDeviceId() const;

private:
    void* _impl;
};

} // namespace thingboot

#endif // THINGBOOT_SDK_H
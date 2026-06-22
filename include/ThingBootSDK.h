#ifndef THINGBOOT_SDK_H
#define THINGBOOT_SDK_H

#include "common/system.h"
#include "driver/led.h"
#include "driver/btn.h"

// 版本号由 pack_lib.py 自动同步 VERSION 文件
#define THINGBOOT_SDK_VERSION "1.0.1"

#include <functional>
#define TB_CALLBACK_EVENT std::function<void(SYS_STATE, bool)> tb_event_callback
#define TB_CALLBACK_CONFIG std::function<void(const char*, String)> tb_config_callback

#define TB_CALLBACK_TIMER10MS std::function<void()> tb_timer_10ms_callback
#define TB_CALLBACK_TIMER100MS std::function<void()> tb_timer_100ms_callback
#define TB_CALLBACK_TIMER1000MS std::function<void()> tb_timer_1000ms_callback

class ThingBootDevice {
private:
    TB_CALLBACK_EVENT;
    TB_CALLBACK_CONFIG;

    TB_CALLBACK_TIMER10MS;
    TB_CALLBACK_TIMER100MS;
    TB_CALLBACK_TIMER1000MS;
public:
    ThingBootDevice();
    ~ThingBootDevice();

    String getVersion();

    // 事件和配置回调
    ThingBootDevice& setEventCallback(TB_CALLBACK_EVENT);
    ThingBootDevice& setConfigCallback(TB_CALLBACK_CONFIG);

    // 定时器回调注册
    ThingBootDevice& setHandle10msCallback(TB_CALLBACK_TIMER10MS);
    ThingBootDevice& setHandle100msCallback(TB_CALLBACK_TIMER100MS);
    ThingBootDevice& setHandle1000msCallback(TB_CALLBACK_TIMER1000MS);

    void setup();
    void loop();
};

#endif // THINGBOOT_SDK_H
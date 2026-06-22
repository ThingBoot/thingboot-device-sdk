#ifndef TIMER_CALLBACK_H
#define TIMER_CALLBACK_H

#include <functional>

using TB_CALLBACK_TIMER = std::function<void()>;

// 全局回调指针，由 ThingBootSDK.cpp 赋值，handle.h 调用
extern TB_CALLBACK_TIMER g_tb_handle_10ms;
extern TB_CALLBACK_TIMER g_tb_handle_100ms;
extern TB_CALLBACK_TIMER g_tb_handle_1000ms;

#endif
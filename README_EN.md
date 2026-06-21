
---

## 3. LICENSE.md

```markdown
# ThingBoot Device SDK — Commercial License Agreement

Copyright (c) 2026 芯步（ThingBoot）科技有限公司 / ThingBoot Technology Co., Ltd.  
All rights reserved.

---

## 1. Definitions

- **"SDK"** means the precompiled static libraries (.a), header files (.h), example code, and documentation provided in this repository.
- **"Licensed Device"** means a single hardware unit that incorporates firmware built with the SDK.
- **"Licensee"** means the individual or entity that has obtained a valid commercial license from ThingBoot.

## 2. Grant of License

Subject to the payment of applicable fees and compliance with this Agreement, ThingBoot grants Licensee a **non-exclusive, non-transferable, revocable license** to:

- Link the SDK into firmware for Licensed Devices.
- Distribute the linked binary firmware to end users.

## 3. Restrictions

Licensee **shall not**:

- Decompile, disassemble, reverse engineer, or attempt to derive the source code of the SDK.
- Redistribute, sublicense, sell, or transfer the SDK (in whole or in part) to any third party.
- Use the SDK on more Licensed Devices than the number of licenses purchased.
- Remove or alter any proprietary notices or labels on the SDK.
- Use the SDK to develop competing platforms or services.

## 4. Device-Based Licensing

Use of the SDK requires a **per-device license** purchased from ThingBoot or its authorized resellers.

- Each Licensed Device must be registered on the ThingBoot platform.
- License fees are billed according to the purchase agreement or platform subscription tier.
- Unlicensed devices may be remotely disabled by the platform.

## 5. Ownership

The SDK and all intellectual property rights therein are and shall remain the exclusive property of ThingBoot. This Agreement does not convey any ownership interest.

## 6. Termination

ThingBoot may terminate this Agreement immediately if Licensee breaches any term. Upon termination, Licensee must cease all use of the SDK and destroy all copies.

## 7. Disclaimer & Limitation of Liability

THE SDK IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND. IN NO EVENT SHALL THINGBOOT BE LIABLE FOR ANY DAMAGES ARISING FROM THE USE OF THE SDK.

## 8. Governing Law

This Agreement shall be governed by the laws of the People's Republic of China.

---

For licensing inquiries, contact: license@thingboot.com

<h3>2. 包含头文件</h3>

<div data-v-e8232542="" data-v-b3358103="" class="segment-code"><header data-v-e8232542="" class="segment-code-header" style="position: sticky; left: 0px; top: 0px;"><div data-v-e8232542="" class="segment-code-header-content"><span data-v-e8232542="" class="segment-code-lang">cpp</span> <!----> <span data-v-868ea423="" data-v-e8232542=""><div data-v-2d045518="" data-v-868ea423="" class="icon-button" style="width: 32px; height: 32px;"><svg data-v-2d045518="" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" role="img" class="iconify" width="20" height="20" viewBox="0 0 1024 1024" name="Copy"><path d="M725.333333 302.933333a166.4 166.4 0 0 1 166.4 166.4v256a166.4 166.4 0 0 1-166.4 166.4h-256A166.4 166.4 0 0 1 302.933333 725.333333v-256A166.4 166.4 0 0 1 469.333333 302.933333h256z m-256 76.8A89.6 89.6 0 0 0 379.733333 469.333333v256c0 49.493333 40.106667 89.6 89.6 89.6h256a89.6 89.6 0 0 0 89.6-89.6v-256A89.6 89.6 0 0 0 725.333333 379.733333h-256z" fill="currentColor"></path><path d="M554.666667 132.266667a166.4 166.4 0 0 1 144.128 83.2 38.4 38.4 0 0 1-66.517334 38.4A89.514667 89.514667 0 0 0 554.666667 209.066667H298.666667A89.6 89.6 0 0 0 209.066667 298.666667v256c0 33.109333 17.92 62.08 44.8 77.653333a38.4 38.4 0 0 1-38.4 66.474667A166.4 166.4 0 0 1 132.266667 554.666667V298.666667A166.4 166.4 0 0 1 298.666667 132.266667h256z" fill="currentColor"></path></svg> <div data-v-8e9e3110="" data-v-2d045518="" class="kimi-tooltip tooltip-bottom icon-button-tooltip bottom">复制</div></div></span></div></header> <div data-v-efb858b9="" data-v-e8232542="" class="syntax-highlighter light segment-code-content"><pre data-v-efb858b9="" class="language-cpp"><code class="language-cpp"><span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">&lt;Arduino.h&gt;</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">&lt;WiFiClient.h&gt;</span></span>
<span class="token macro property"><span class="token directive-hash">#</span><span class="token directive keyword">include</span> <span class="token string">"ThingBootSDK.h"</span></span></code></pre></div></div>

<h3>3. 编写应用</h3>

<div data-v-e8232542="" data-v-b3358103="" class="segment-code"><header data-v-e8232542="" class="segment-code-header" style="position: sticky; left: 0px; top: 0px;"><div data-v-e8232542="" class="segment-code-header-content"><span data-v-e8232542="" class="segment-code-lang">cpp</span> <!----> <span data-v-868ea423="" data-v-e8232542=""><div data-v-2d045518="" data-v-868ea423="" class="icon-button" style="width: 32px; height: 32px;"><svg data-v-2d045518="" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" role="img" class="iconify" width="20" height="20" viewBox="0 0 1024 1024" name="Copy"><path d="M725.333333 302.933333a166.4 166.4 0 0 1 166.4 166.4v256a166.4 166.4 0 0 1-166.4 166.4h-256A166.4 166.4 0 0 1 302.933333 725.333333v-256A166.4 166.4 0 0 1 469.333333 302.933333h256z m-256 76.8A89.6 89.6 0 0 0 379.733333 469.333333v256c0 49.493333 40.106667 89.6 89.6 89.6h256a89.6 89.6 0 0 0 89.6-89.6v-256A89.6 89.6 0 0 0 725.333333 379.733333h-256z" fill="currentColor"></path><path d="M554.666667 132.266667a166.4 166.4 0 0 1 144.128 83.2 38.4 38.4 0 0 1-66.517334 38.4A89.514667 89.514667 0 0 0 554.666667 209.066667H298.666667A89.6 89.6 0 0 0 209.066667 298.666667v256c0 33.109333 17.92 62.08 44.8 77.653333a38.4 38.4 0 0 1-38.4 66.474667A166.4 166.4 0 0 1 132.266667 554.666667V298.666667A166.4 166.4 0 0 1 298.666667 132.266667h256z" fill="currentColor"></path></svg> <div data-v-8e9e3110="" data-v-2d045518="" class="kimi-tooltip tooltip-bottom icon-button-tooltip bottom">复制</div></div></span></div></header> <div data-v-efb858b9="" data-v-e8232542="" class="syntax-highlighter light segment-code-content"><pre data-v-efb858b9="" class="language-cpp"><code class="language-cpp">thingboot<span class="token double-colon punctuation">::</span>ThingBootDevice device<span class="token punctuation">;</span>

<span class="token keyword">void</span> <span class="token function">setup</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
    Serial<span class="token punctuation">.</span><span class="token function">begin</span><span class="token punctuation">(</span><span class="token number">115200</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    device<span class="token punctuation">.</span><span class="token function">begin</span><span class="token punctuation">(</span><span class="token string">"your-device-id"</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    
    <span class="token keyword">if</span> <span class="token punctuation">(</span>device<span class="token punctuation">.</span><span class="token function">connect</span><span class="token punctuation">(</span><span class="token string">"iot.thingboot.com"</span><span class="token punctuation">,</span> <span class="token number">8883</span><span class="token punctuation">)</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
        Serial<span class="token punctuation">.</span><span class="token function">println</span><span class="token punctuation">(</span><span class="token string">"已连接芯步平台"</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
        device<span class="token punctuation">.</span><span class="token function">sendData</span><span class="token punctuation">(</span><span class="token string">"{\"status\":\"online\"}"</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
<span class="token punctuation">}</span>

<span class="token keyword">void</span> <span class="token function">loop</span><span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
    device<span class="token punctuation">.</span><span class="token function">loop</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>  <span class="token comment">// 维持 SDK 心跳</span>
    
    <span class="token comment">// 处理平台下发的命令</span>
    <span class="token keyword">if</span> <span class="token punctuation">(</span>device<span class="token punctuation">.</span><span class="token function">hasCommand</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
        <span class="token keyword">auto</span> cmd <span class="token operator">=</span> device<span class="token punctuation">.</span><span class="token function">getCommand</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span>cmd<span class="token punctuation">.</span>type <span class="token operator">==</span> <span class="token string">"switch"</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
            <span class="token function">digitalWrite</span><span class="token punctuation">(</span>RELAY_PIN<span class="token punctuation">,</span> cmd<span class="token punctuation">.</span>value <span class="token operator">==</span> <span class="token string">"on"</span> <span class="token operator">?</span> HIGH <span class="token operator">:</span> LOW<span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token punctuation">}</span>
    <span class="token punctuation">}</span>
<span class="token punctuation">}</span></code></pre></div></div>

<h2>目录结构</h2>

<div data-v-e8232542="" data-v-b3358103="" class="segment-code"><header data-v-e8232542="" class="segment-code-header" style="position: sticky; left: 0px; top: 0px;"><div data-v-e8232542="" class="segment-code-header-content"><span data-v-e8232542="" class="segment-code-lang">plain</span> <!----> <span data-v-868ea423="" data-v-e8232542=""><div data-v-2d045518="" data-v-868ea423="" class="icon-button" style="width: 32px; height: 32px;"><svg data-v-2d045518="" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" role="img" class="iconify" width="20" height="20" viewBox="0 0 1024 1024" name="Copy"><path d="M725.333333 302.933333a166.4 166.4 0 0 1 166.4 166.4v256a166.4 166.4 0 0 1-166.4 166.4h-256A166.4 166.4 0 0 1 302.933333 725.333333v-256A166.4 166.4 0 0 1 469.333333 302.933333h256z m-256 76.8A89.6 89.6 0 0 0 379.733333 469.333333v256c0 49.493333 40.106667 89.6 89.6 89.6h256a89.6 89.6 0 0 0 89.6-89.6v-256A89.6 89.6 0 0 0 725.333333 379.733333h-256z" fill="currentColor"></path><path d="M554.666667 132.266667a166.4 166.4 0 0 1 144.128 83.2 38.4 38.4 0 0 1-66.517334 38.4A89.514667 89.514667 0 0 0 554.666667 209.066667H298.666667A89.6 89.6 0 0 0 209.066667 298.666667v256c0 33.109333 17.92 62.08 44.8 77.653333a38.4 38.4 0 0 1-38.4 66.474667A166.4 166.4 0 0 1 132.266667 554.666667V298.666667A166.4 166.4 0 0 1 298.666667 132.266667h256z" fill="currentColor"></path></svg> <div data-v-8e9e3110="" data-v-2d045518="" class="kimi-tooltip tooltip-bottom icon-button-tooltip bottom">复制</div></div></span></div></header> <div data-v-efb858b9="" data-v-e8232542="" class="syntax-highlighter light segment-code-content"><pre data-v-efb858b9="" class="language-plain"><code class="language-plain">lib/thingboot-device-sdk/
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
└── LICENSE.md</code></pre></div></div>

<h2>ABI 兼容警告</h2>
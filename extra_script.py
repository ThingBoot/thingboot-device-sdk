import os
Import("env")

PROJECT_DIR = env.subst("$PROJECT_DIR")

platform = env.get("PIOPLATFORM")
arch = env.get("BOARD_MCU", "")
lib_name = None

if platform == "espressif8266":
    if "8285" in arch.lower():
        lib_name = "libThingBootSDK_esp8285.a"
    else:
        lib_name = "libThingBootSDK_esp8266.a"
elif platform == "espressif32":
    if "s3" in arch.lower():
        lib_name = "libThingBootSDK_esp32s3.a"
    elif "c6" in arch.lower():
        lib_name = "libThingBootSDK_esp32c6.a"
    else:
        lib_name = "libThingBootSDK_esp32.a"

if lib_name:
    lib_dir = os.path.join(PROJECT_DIR, "lib", "thingboot-device-sdk", "lib")
    lib_path = os.path.join(lib_dir, lib_name)
    if os.path.exists(lib_path):
        env.Append(LIBPATH=[lib_dir])
        env.Prepend(LIBS=[lib_name[3:-2]])
        print("[ThingBootSDK] Linked: " + lib_name)
    else:
        print("[ThingBootSDK] WARNING: Not found " + lib_path)

# Copyright (C) 2014 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from the proprietary version
-include vendor/nubia/nx511j/BoardConfigVendor.mk

LOCAL_PATH := device/nubia/nx511j

TARGET_SPECIFIC_HEADER_PATH := $(LOCAL_PATH)/include

PRODUCT_COPY_FILES := $(filter-out frameworks/base/data/keyboards/Generic.kl:system/usr/keylayout/Generic.kl \
	, $(PRODUCT_COPY_FILES))

# Platform
TARGET_BOARD_PLATFORM := msm8916
TARGET_BOARD_PLATFORM_GPU := qcom-adreno405

# Bootloader
TARGET_BOOTLOADER_BOARD_NAME := msm8916
TARGET_NO_BOOTLOADER := true

# CPU
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_ABI2 :=
TARGET_CPU_VARIANT := generic

TARGET_2ND_ARCH := arm
TARGET_2ND_ARCH_VARIANT := armv7-a-neon
TARGET_2ND_CPU_ABI := armeabi-v7a
TARGET_2ND_CPU_ABI2 := armeabi
TARGET_2ND_CPU_VARIANT := cortex-a53

TARGET_BOARD_SUFFIX := _64
TARGET_USES_64_BIT_BINDER := true

#
ENABLE_CPUSETS     := true
#ENABLE_SCHED_BOOST := true

# Kernel
TARGET_KERNEL_ARCH := arm64
TARGET_KERNEL_HEADER_ARCH := arm64
TARGET_KERNEL_CROSS_COMPILE_PREFIX := aarch64-linux-android-
BOARD_KERNEL_CMDLINE := console=null androidboot.console=ttyHSL0 androidboot.hardware=qcom msm_rtb.filter=0x237 ehci-hcd.park=3 androidboot.bootdevice=7824900.sdhci lpm_levels.sleep_disabled=1 earlyprintk androidboot.selinux=permissive
BOARD_KERNEL_BASE := 0x80000000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_KERNEL_TAGS_OFFSET := 0x00000100
BOARD_RAMDISK_OFFSET := 0x02000000
BOARD_KERNEL_SEPARATED_DT := true
TARGET_USES_UNCOMPRESSED_KERNEL := true
BOARD_DTBTOOL_ARGS := -2
TARGET_KERNEL_CONFIG := cyanogenmod_nubia_nx511j_defconfig
TARGET_KERNEL_SOURCE := kernel/nubia/nx511j

# Partitions
BOARD_FLASH_BLOCK_SIZE := 131072
BOARD_BOOTIMAGE_PARTITION_SIZE := 33554432
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 33554432
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1610612736
BOARD_USERDATAIMAGE_PARTITION_SIZE := 13258652672
TARGET_USERIMAGES_USE_EXT4 := true
TARGET_USERIMAGES_USE_F2FS := true

# Wifi
BOARD_HAS_QCOM_WLAN := true
BOARD_HAS_QCOM_WLAN_SDK := true
BOARD_HOSTAPD_DRIVER := NL80211
BOARD_HOSTAPD_PRIVATE_LIB := lib_driver_cmd_qcwcn
TARGET_USES_QCOM_WCNSS_QMI := true
TARGET_PROVIDES_WCNSS_QMI := true
BOARD_WLAN_DEVICE := qcwcn
BOARD_WPA_SUPPLICANT_DRIVER := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_qcwcn
TARGET_USES_WCNSS_CTRL := true
WIFI_DRIVER_FW_PATH_AP := "ap"
WIFI_DRIVER_FW_PATH_STA := "sta"
WPA_SUPPLICANT_VERSION := VER_0_8_X
WIFI_DRIVER_MODULE_PATH          := "/system/lib/modules/wlan.ko"
WIFI_DRIVER_MODULE_NAME          := "wlan"

# QCOM
BOARD_USES_QCOM_HARDWARE := true
USE_DEVICE_SPECIFIC_QCOM_PROPRIETARY:= true
TARGET_USES_QCOM_BSP     := true
COMMON_GLOBAL_CFLAGS += -DQCOM_HARDWARE -DQCOM_BSP

# Fonts
EXTENDED_FONT_FOOTPRINT := true

# Charger
BOARD_CHARGER_DISABLE_INIT_BLANK := true

# Graphics
BOARD_EGL_CFG := $(LOCAL_PATH)/configs/egl.cfg
MAX_EGL_CACHE_KEY_SIZE := 12*1024
MAX_EGL_CACHE_SIZE := 2048*1024
NUM_FRAMEBUFFER_SURFACE_BUFFERS := 3
OVERRIDE_RS_DRIVER := libRSDriver_adreno.so
TARGET_CONTINUOUS_SPLASH_ENABLED := true
TARGET_USES_C2D_COMPOSITION := true
TARGET_USES_ION := true
USE_OPENGL_RENDERER := true
#BOARD_USES_OPENSSL_SYMBOLS := true

#Enable HW based full disk encryption
TARGET_HW_DISK_ENCRYPTION := false

# ANT+
BOARD_ANT_WIRELESS_DEVICE := "vfs-prerelease"

# Audio
BOARD_USES_ALSA_AUDIO                      := true
AUDIO_FEATURE_ENABLED_FM                   := true
AUDIO_FEATURE_ENABLED_FLUENCE              := true
AUDIO_FEATURE_LOW_LATENCY_PRIMARY          := true
USE_CUSTOM_AUDIO_POLICY := 1

# Bluetooth
BOARD_HAVE_BLUETOOTH      := true
BOARD_HAVE_BLUETOOTH_QCOM := true
BLUETOOTH_HCI_USE_MCT     := true
QCOM_BT_USE_SMD_TTY       := true
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(LOCAL_PATH)/bluetooth

# Malloc
MALLOC_IMPL := dlmalloc

# Init
TARGET_INIT_VENDOR_LIB := libinit_msm
TARGET_PLATFORM_DEVICE_BASE := /devices/soc.0/

# PowerHAL
TARGET_POWERHAL_VARIANT      := qcom

# GPS
TARGET_NO_RPC := true
USE_DEVICE_SPECIFIC_GPS := true

# LightHAL
TARGET_PROVIDES_LIBLIGHT := true

# QCRIL
TARGET_RIL_VARIANT := caf
SIM_COUNT := 2
TARGET_GLOBAL_CFLAGS += -DANDROID_MULTI_SIM
TARGET_GLOBAL_CPPFLAGS += -DANDROID_MULTI_SIM

# Time services
BOARD_USES_QC_TIME_SERVICES := true

# Added to indicate that protobuf-c is supported in this build
PROTOBUF_SUPPORTED := true

# Flags
COMMON_GLOBAL_CFLAGS += -DNO_SECURE_DISCARD

# Video
TARGET_HAVE_SIGNED_VENUS_FW := true

# SELinux
include device/qcom/sepolicy/sepolicy.mk

# Recovery
TARGET_RECOVERY_FSTAB := device/nubia/nx511j/ramdisk/fstab.qcom
DEVICE_RESOLUTION := 1080x1920
TARGET_RECOVERY_PIXEL_FORMAT := ABGR_8888
BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_15x24.h\"
TARGET_USERIMAGES_USE_EXT4 := true
TARGET_USERIMAGES_USE_F2FS := true

#twrp
#TARGET_RECOVERY_FSTAB := $(LOCAL_PATH)/twrp/twrp.fstab
RECOVERY_GRAPHICS_USE_LINELENGTH := true
RECOVERY_SDCARD_ON_DATA := true
TW_TARGET_USES_QCOM_BSP := true
TW_NEW_ION_HEAP := true
TW_FLASH_FROM_STORAGE := true
TW_INTERNAL_STORAGE_PATH := "/data/media/0"
TW_INTERNAL_STORAGE_MOUNT_POINT := "data"
TW_EXTERNAL_STORAGE_PATH := "/external_sd"
TW_EXTERNAL_STORAGE_MOUNT_POINT := "external_sd"
TW_DEFAULT_EXTERNAL_STORAGE := true
TW_BRIGHTNESS_PATH := /sys/class/leds/lcd-backlight/brightness

BOARD_CANT_BUILD_RECOVERY_FROM_BOOT_PATCH := true

# RIL class
BOARD_RIL_CLASS := ../../../device/nubia/nx511j/ril/

#d2tw
BOARD_HARDWARE_CLASS := hardware/mokee/mkhw
TARGET_TAP_TO_WAKE_NODE := "/data/tp/easy_wakeup_gesture"

# Radio
ADD_RADIO_FILES := true
TARGET_RELEASETOOLS_EXTENSIONS := $(LOCAL_PATH)

WITHOUT_HOST_CLANG := false
WITH_DEXPREOPT := true
WITH_DEXPREOPT_COMP := false

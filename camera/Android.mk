LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_C_INCLUDES := system/media/camera/include

LOCAL_SRC_FILES := \
    CameraWrapper.cpp

LOCAL_SHARED_LIBRARIES := \
    libhardware liblog libcamera_client libutils

#LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)/hw
LOCAL_MODULE := camera.$(TARGET_BOARD_PLATFORM)
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_RELATIVE_PATH    := hw
LOCAL_MULTILIB := 32
include $(BUILD_SHARED_LIBRARY)
#include $(BUILD_HEAPTRACKED_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := liblog libcutils libgui libbinder libutils

LOCAL_SRC_FILES := \
    camera_symbol.c

LOCAL_MODULE := libcamera_symbol
LOCAL_MODULE_CLASS := SHARED_LIBRARIES

LOCAL_32_BIT_ONLY := $(BOARD_QTI_CAMERA_32BIT_ONLY)
include $(BUILD_SHARED_LIBRARY)

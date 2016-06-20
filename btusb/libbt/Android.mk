LOCAL_PATH := $(call my-dir)

ifeq ($(BLUETOOTH_HCI_USE_USB),true)

include $(CLEAR_VARS)

BDROID_DIR := $(TOP_DIR)system/bt

LOCAL_SRC_FILES := \
        src/bt_vendor_usb.c \
        src/hardware.c \
        src/userial_vendor.c \
        src/upio.c \
        src/conf.c

LOCAL_C_INCLUDES += \
        $(LOCAL_PATH)/include \
        $(BDROID_DIR)/include \
        $(BDROID_DIR)/stack/include \
        $(BDROID_DIR)/hci/include

LOCAL_CFLAGS += -DHCI_USE_USB

LOCAL_SHARED_LIBRARIES := \
        libcutils \
        liblog

LOCAL_MODULE := libbt-vendor
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_OWNER := usb
LOCAL_PROPRIETARY_MODULE := true

include $(LOCAL_PATH)/vnd_buildcfg.mk

include $(BUILD_SHARED_LIBRARY)

endif # BOARD_HAVE_BLUETOOTH_USB

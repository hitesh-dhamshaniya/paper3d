LOCAL_PATH:= $(call my-dir)


TECH_ROOT := $(FITECH)
PAPER3D_ROOT := $(FIPAPER3D)
TECH_LIBRARY_PATH := $(TECH_ROOT)/lib/android
PAPER3D_LIBRARY_PATH := $(PAPER3D_ROOT)/lib/android

APP_DEFINES := -DANDROID  -DP_ENABLE_NETWORK=1

ifeq ($(USE_STL), 1) 
APP_DEFINES := $(APP_DEFINES) -DP_USE_STL 
$(info ...Use native STL...)
else
$(info ...No STL support...)
endif

ifeq ($(ENABLE_LOGGING), 1) 
APP_DEFINES := $(APP_DEFINES) -DP_ENABLE_LOGGING=1
$(info ...Enable logging...)
else
$(info ...Disable logging...)
endif

ifeq ($(NDK_DEBUG), 1)
$(info ...Build debug version...)
CONF_FLAGS := -g -DDEBUG -D_DEBUG 
TECH_LIBRARY_PATH := $(TECH_LIBRARY_PATH)/ES20_Debug
PAPER3D_LIBRARY_PATH := $(PAPER3D_LIBRARY_PATH)/Debug
CONFIGURATION := Debug
else
$(info ...Build release version...)
CONF_FLAGS :=
TECH_LIBRARY_PATH := $(TECH_LIBRARY_PATH)/ES20_Release
PAPER3D_LIBRARY_PATH := $(PAPER3D_LIBRARY_PATH)/Release
CONFIGURATION := Release
# CONF_FLAGS := -O2  # not a good idea, -O0 is generated by ndk-build
endif


EXT_LIBRARY_PATH := $(TECH_ROOT)/3rdparty/platforms/android
APP_PATH := ../../..

########################################
# Pre-compiled libraries
########################################
# png
include $(CLEAR_VARS)

LOCAL_MODULE := png # name it whatever
LOCAL_SRC_FILES := $(EXT_LIBRARY_PATH)/libpng/lib/$(CONFIGURATION)/libpng.a  

include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY

# z
include $(CLEAR_VARS)

LOCAL_MODULE := z
LOCAL_SRC_FILES := $(EXT_LIBRARY_PATH)/zlib/lib/$(CONFIGURATION)/libz.a  

include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY

# tinyxml
include $(CLEAR_VARS)

LOCAL_MODULE := tinyxml
LOCAL_SRC_FILES := $(EXT_LIBRARY_PATH)/tinyxml/lib/$(CONFIGURATION)/libtinyxml.a  

include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY

# enet
include $(CLEAR_VARS)

LOCAL_MODULE := enet
LOCAL_SRC_FILES := $(EXT_LIBRARY_PATH)/enet/lib/$(CONFIGURATION)/libenet.a  

include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY

# platform
include $(CLEAR_VARS)

LOCAL_MODULE := platform
LOCAL_SRC_FILES := $(TECH_LIBRARY_PATH)/libplatform.a  

include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY

# foundation
include $(CLEAR_VARS)

LOCAL_MODULE := foundation
LOCAL_SRC_FILES := $(TECH_LIBRARY_PATH)/libfoundation.a  

include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY

# paper3d
include $(CLEAR_VARS)

LOCAL_MODULE := paper3d
LOCAL_SRC_FILES := $(PAPER3D_LIBRARY_PATH)/libpaper3d.a  

include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY

########################################
# Build the main module
########################################

include $(CLEAR_VARS)

LOCAL_MODULE := fi 
LOCAL_CFLAGS := -O2 $(APP_DEFINES) $(CONF_FLAGS) -fexceptions -frtti

APP_LIBRARY_INCLUDE_PATHS := \
$(APP_PATH)/src \
$(TECH_ROOT)/include \
$(TECH_ROOT)/include/PPlatform \
$(TECH_ROOT)/include/PFoundation \
$(PAPER3D_ROOT)/include

EXT_LIBRARY_INCLUDE_PATHS := \
$(TECH_ROOT)/3rdparty/platforms/android/libpng/include/ \
$(TECH_ROOT)/3rdparty/common/libpng/include \
$(TECH_ROOT)/3rdparty/common/zlib/include \
$(TECH_ROOT)/3rdparty/common/tinyxml/include 

LOCAL_C_INCLUDES := \
	$(APP_LIBRARY_INCLUDE_PATHS) \
	$(EXT_LIBRARY_INCLUDE_PATHS)

LOCAL_SRC_FILES := \
$(TECH_ROOT)/src/platform/android/main.cpp \
$(APP_PATH)/src/pmain.cpp \
$(APP_PATH)/src/mycontext.cpp \
$(APP_PATH)/src/myserver.cpp \
$(APP_PATH)/src/myclient.cpp \
$(APP_PATH)/src/myscene.cpp 

LOCAL_LDLIBS := -llog -lgcc -lGLESv2 -ldl -landroid 

LOCAL_STATIC_LIBRARIES := paper3d platform foundation png z tinyxml enet

#-L$(EXT_LIBRARY_PATH)/freetype/lib -lfreetype 

include $(BUILD_SHARED_LIBRARY)


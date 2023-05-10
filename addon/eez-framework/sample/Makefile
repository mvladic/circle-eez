CIRCLEHOME = ../../..
NEWLIBDIR = $(CIRCLEHOME)/../../install/$(NEWLIB_ARCH)

include $(CIRCLEHOME)/../../Config.mk

CSRCS += $(shell find -L ./ui -name "*.c")
OBJS	= main.o kernel.o $(CSRCS:.c=.o)
EXTRACLEAN += $(CSRCS:.c=.o) $(CSRCS:.c=.d)

include $(CIRCLEHOME)/Rules.mk

VPATH += :../eez-framework/src
VPATH += :../../lvgl
CFLAGS += -DEEZ_FOR_LVGL -DEEZ_PLATFORM_RASPBERRY -I"../eez-framework/src" -I"../../lvgl"
CPPFLAGS += -DEEZ_FOR_LVGL -DEEZ_PLATFORM_RASPBERRY -I"../eez-framework/src" -I"../../lvgl"
DEFINE += -DNO_CALIBRATE_DELAY

LIBS	= ../eez-framework.a \
        $(NEWLIBDIR)/lib/libm.a \
        $(NEWLIBDIR)/lib/libc.a \
        $(NEWLIBDIR)/lib/libcirclenewlib.a \
        $(CIRCLEHOME)/addon/SDCard/libsdcard.a \
        $(CIRCLEHOME)/addon/lvgl/liblvgl.a \
        $(CIRCLEHOME)/lib/usb/libusb.a \
        $(CIRCLEHOME)/lib/input/libinput.a \
        $(CIRCLEHOME)/addon/fatfs/libfatfs.a \
        $(CIRCLEHOME)/lib/fs/libfs.a \
        $(CIRCLEHOME)/lib/net/libnet.a \
        $(CIRCLEHOME)/lib/sched/libsched.a \
        $(CIRCLEHOME)/lib/libcircle.a

-include $(DEPS)

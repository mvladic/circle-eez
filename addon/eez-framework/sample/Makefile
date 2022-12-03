CIRCLEHOME = ../../..
NEWLIBDIR = $(CIRCLEHOME)/../../install/$(NEWLIB_ARCH)

include $(CIRCLEHOME)/../../Config.mk

OBJS	= main.o kernel.o ui/flow_def.o ui/images.o ui/screens.o ui/styles.o ui/ui.o

VPATH += :../eez-framework/src
VPATH += :../../lvgl
CFLAGS += -DEEZ_FOR_LVGL "-I../eez-framework/src"
CPPFLAGS += -DEEZ_FOR_LVGL "-I../eez-framework/src" "-I../eez-framework/src"

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

include $(CIRCLEHOME)/Rules.mk

-include $(DEPS)

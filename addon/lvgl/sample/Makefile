#
# Makefile
#

CIRCLEHOME = ../../..
NEWLIBDIR = $(CIRCLEHOME)/../../install/$(NEWLIB_ARCH)

include $(CIRCLEHOME)/../../Config.mk

OBJS	= main.o kernel.o

LIBS	= ../liblvgl.a \
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


#
# Makefile
#

CIRCLEHOME = ../..

all: eez-framework.a

include $(CIRCLEHOME)/Rules.mk

# eez-framework
VPATH += :./eez-framework/src
VPATH += :../lvgl
CSRCS += $(shell find -L ./eez-framework/src -name "*.c")
CPPSRCS += $(shell find -L ./eez-framework/src -name "*.cpp")
CFLAGS += -DEEZ_FOR_LVGL -DEEZ_PLATFORM_RASPBERRY "-I./eez-framework/src" -I"../lvgl"
CPPFLAGS += -DEEZ_FOR_LVGL -DEEZ_PLATFORM_RASPBERRY "-I./eez-framework/src" -I"../lvgl"

OBJS = $(CSRCS:.c=.o) $(CPPSRCS:.cpp=.o)

EXTRACLEAN += $(CSRCS:.c=.o) $(CSRCS:.c=.d) $(CPPSRCS:.cpp=.o) $(CPPSRCS:.cpp=.d)

eez-framework.a: $(OBJS)
	@echo "  AR    $@"
	@rm -f $@
	@$(AR) cr $@ $(OBJS)

-include $(DEPS)

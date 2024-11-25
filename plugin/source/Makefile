NAME = Untitled
FILES_DSP = $(wildcard *.cpp)
FILES_DSP += $(wildcard *.c)

DPF_TARGET_DIR = ../../bin
DPF_BUILD_DIR = ../../build
DPF_PATH = ../../dpf

include ../../dpf/Makefile.plugins.mk

BUILD_C_FLAGS += -Wno-unused-parameter -std=c11 -fno-strict-aliasing -pthread
BUILD_CXX_FLAGS += -Wno-unused-parameter -fno-strict-aliasing -pthread
LINK_FLAGS += -pthread


TARGETS += jack


all: $(TARGETS)
CXX = $(shell root-config --cxx)
LD = $(shell root-config --ld)

INC = $(shell pwd)

OS_NAME:=$(shell uname -s | tr A-Z a-z)
ifeq ($(OS_NAME),darwin)
STDINCDIR := -I/opt/local/include
STDLIBDIR := -L/opt/local/lib
else
STDINCDIR :=-I/media/data/cmorgoth/git/DarkMatterAna/
STDLIBDIR := 
endif

CPPFLAGS := -Wl,--no-as-needed -std=c++0x $(shell root-config --cflags) -I$(INC)/include
LDFLAGS := $(shell root-config --glibs) $(STDLIBDIR)

CPPFLAGS += -g

TARGET = ControlSamples
TARGET2 = NormalizeMC
TARGET3 = Plotting

SRC = app/test.cc src/BoxStructure.cc src/BkgData.cc include/ControlSampleEvents.hh src/PlotCosmetics.cc
SRC2 = app/Normalize_SMbkgs.cc src/NormalizeMC.cc
SRC3 = app/plotting.cc src/PlotCosmetics.cc

OBJ = $(SRC:.cc=.o)
OBJ2 = $(SRC2:.cc=.o)
OBJ3 = $(SRC3:.cc=.o)

all : $(TARGET) $(TARGET2) $(TARGET3)

$(TARGET) : $(OBJ)
	$(LD) $(CPPFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)
	@echo $@
	@echo $<
	@echo $^

$(TARGET2) : $(OBJ2)
	$(LD) $(CPPFLAGS) -o $(TARGET2) $(OBJ2) $(LDFLAGS)
	@echo $@
	@echo $<
	@echo $^

$(TARGET3) : $(OBJ3)
	$(LD) $(CPPFLAGS) -o $(TARGET3) $(OBJ3) $(LDFLAGS)
	@echo $@
	@echo $<
	@echo $^

%.o : %.cc	
	$(CXX) $(CPPFLAGS) -o $@ -c $<
	@echo $@	
	@echo $<
clean :
	rm -f *.o src/*.o $(TARGET)  $(TARGET2) $(TARGET3) *~


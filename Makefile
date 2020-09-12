MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
ifndef BUILDDIR
	BUILDDIR_ABSOLUTE = $(patsubst %/,%,$(dir $(MAKEFILE_PATH)))
else
	BUILDDIR_ABSOLUTE = $(abspath $(BUILDDIR))
endif

CXX = g++
TOPDIR= $(BUILDDIR_ABSOLUTE)/../

CPPFLAGS += -std=c++11

INCLUDEDIRS += -I$(TOPDIR) 

LDFLAGS += -L/usr/local/lib \
		  -Wl,--no-as-needed -Wl,--as-needed\

BUILD?=DEBUG

ifeq ($(BUILD), release)
	CPPFLAGS += -s -O3 
	CFLAG += -s -O3 -pipe -Wno-deprecated 
else
	CPPFLAGS += -g -Wall -O0 
	CFLAG += -g -pg -Wall -Wno-deprecated 
endif


SRC := $(BUILDDIR_ABSOLUTE)/
OBJ := $(BUILDDIR_ABSOLUTE)/Bins/

SOURCES := $(wildcard $(SRC)/*.cc)
OBJECTS := $(patsubst $(SRC)/%.cc, $(OBJ)/%.o, $(SOURCES))
TARGET_EXEC := $(patsubst $(SRC)/%.cc, $(OBJ)/%, $(SOURCES))

all: $(TARGET_EXEC)
	$(info "*********************************")                                                                             
	$(info "Building [$(BUILD)] version.")                                                                                  
	$(info "*********************************")    

$(OBJECTS): $(SOURCES)
	$(info "[Compile] Generate objects.")                                                                                   
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(TARGET_EXEC): $(OBJECTS)
	$(info "[CXX] Make CPP files.")
	$(CXX) $(CPPFLAGS) $(INCLUDEDIRS) -o $@ $< $(LDFLAGS)

.PHONE : clean
clean:
	$(info "BUILDDIR_ABSOLUTE: $(BUILDDIR_ABSOLUTE)")
	$(info "SOURCES: $(SOURCES)")
	$(info "OBJECTS: $(OBJECTS)")
	-rm $(OBJECTS) $(TARGET_EXEC)


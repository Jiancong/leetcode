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

all: Binary_Tree_Traversal Recursive MaxConsecutiveOnes
	$(info "*********************************")                                                                             
	$(info "Building [$(BUILD)] version.")                                                                                  
	$(info "*********************************")    

SRC := $(BUILDDIR_ABSOLUTE)/
OBJ := $(BUILDDIR_ABSOLUTE)/Bins/

SOURCES := $(wildcard $(SRC)/*.cc)
OBJECTS := $(patsubst $(SRC)/%.cc, $(SRC)/%.o, $(SOURCES))

$(SRC)/$(OBJECTS): $(SOURCES)
	$(info "[Compile] Generate objects.")                                                                                   
	$(CXX) $(CPPFLAGS) -c $< 

Binary_Tree_Traversal: Binary_Tree_Traversal.o
	$(info "[CXX] Make CPP files.")
	$(CXX) $(CPPFLAGS) $(INCLUDEDIRS) -o $(OBJ)/$@ $^ $(LDFLAGS)

Recursive: Recursive.o
	$(info "[CXX] Make CPP files.")
	$(CXX) $(CPPFLAGS) $(INCLUDEDIRS) -o $(OBJ)/$@ $^ $(LDFLAGS)

MaxConsecutiveOnes: MaxConsecutiveOnes.o
	$(info "[CXX] Make CPP files.")
	$(CXX) $(CPPFLAGS) $(INCLUDEDIRS) -o $(OBJ)/$@ $^ $(LDFLAGS)

.PHONE : clean
clean:
	$(info "BUILDDIR_ABSOLUTE: $(BUILDDIR_ABSOLUTE)")
	$(info "SOURCES: $(SOURCES)")
	$(info "OBJECTS: $(OBJECTS)")
	-rm $(OBJECTS)


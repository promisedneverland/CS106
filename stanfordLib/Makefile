CS106_HOME = ~/cs/cs106X
STANFORD_LIB := $(CS106_HOME)/stanfordLib/StanfordCPPLib
STANFORD_LIB_DIRS := $(shell find $(STANFORD_LIB) -type d)
INCFLAGS += $(addprefix -I, $(STANFORD_LIB_DIRS))
SRCS := $(shell find . -maxdepth 3 -name "*.cpp")

all:
	@echo $(SRCS)

lib.so: $(DEPS) 
	@g++ -fPIC -shared $(INCFLAGS) $(SRCS) -o $@ $(LDFLAGS)
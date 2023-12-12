CS106_HOME = ~/cs/cs106X
WORK_DIR  = $(shell pwd)
DST_DIR   = $(WORK_DIR)/build
$(shell mkdir -p $(DST_DIR))
STANFORD_LIB := $(CS106_HOME)/stanfordLib/StanfordCPPLib
STANFORD_LIB_DIRS := $(shell find $(STANFORD_LIB) -type d)
INCFLAGS += $(addprefix -I, $(STANFORD_LIB_DIRS))
OBJS      = $(addprefix $(DST_DIR)/, $(addsuffix .o, $(basename $(SRCS))))
ARCHIVE   = $(WORK_DIR)/build/stanfordLib.a

$(DST_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@) && echo + CXX $<
	@g++ $(CXXFLAGS) -c -o $@ $(realpath $<)

### Rule (archive): objects (`*.o`) -> `ARCHIVE.a` (ar)
$(ARCHIVE): $(OBJS)
#@echo + AR "->" $(shell realpath $@ --relative-to .)
	@ar rcs $(ARCHIVE) $(OBJS)
	
git:
	@git add . -A 
	@(uname -a && uptime) | git commit -F - -q --allow-empty
	@sync

all:
	@echo $(INCFLAGS)
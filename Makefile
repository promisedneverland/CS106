CS106_HOME = ~/cs/cs106X
WORK_DIR  = $(shell pwd)
DST_DIR   = $(WORK_DIR)/build
$(shell mkdir -p $(DST_DIR))
# STANFORD_LIB := $(CS106_HOME)/stanfordLib/StanfordCPPLib
# STANFORD_LIB_DIRS := $(shell find $(STANFORD_LIB) -type d)

# INC_PATH += $(shell find ~/Qt/6.6.1/gcc_64/include -type d)
# INC_PATH += $(STANFORD_LIB_DIRS)

# INCFLAGS += $(addprefix -I, $(INC_PATH))
# CFLAGS   += $(INCFLAGS)
# OBJS      = $(addprefix $(DST_DIR)/, $(addsuffix .o, $(basename $(SRCS))))
# ARCHIVE   = $(WORK_DIR)/build/stanfordLib.a

CFLAGS += -std=c++11 -I /home/lcx/stanford/ -I /home/lcx/stanford/collections -I /home/lcx/stanford/graphics -I /home/lcx/stanford/io -I /home/lcx/stanford/private -I /home/lcx/stanford/system -I /home/lcx/stanford/util -L /home/lcx/stanford
LDFLAGS += -lstanford -ldl -lpthread
$(DST_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@) && echo + CXX $<
	@g++ $(CFLAGS) -c -o $@ $(realpath $<)

# ### Rule (archive): objects (`*.o`) -> `ARCHIVE.a` (ar)
# $(ARCHIVE): $(OBJS)
# #@echo + AR "->" $(shell realpath $@ --relative-to .)
# 	@ar rcs $(ARCHIVE) $(OBJS)
	
git:
	@git add . -A 
	@(uname -a && uptime) | git commit -F - -q --allow-empty
	@sync
# archive: $(ARCHIVE)
all:
	@echo $(INCFLAGS)
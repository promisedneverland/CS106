include ../Makefile
ID = 3.3
BUILD := ./build
HEADERS := $(wildcard $(ID)/*.h)
SRCS := $(wildcard $(ID)/*.cpp)
# OBJS      = $(addprefix $(BUILD)/$(ID), $(addsuffix .out, $(basename $(SRCS))))
OBJS := $(BUILD)/$(ID)/$(ID).out
$(shell mkdir -p $(BUILD)/$(ID))

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CFLAGS) $(SRCS) $(LDFLAGS) -o $@

build: $(OBJS)

run: build
	@$(OBJS)

clean:
	@rm -rf ./build
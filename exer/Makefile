include ../Makefile
ID = 3.3
BUILD := ./build
SRCS := $(ID).cpp
OBJS      = $(addprefix $(BUILD)/, $(addsuffix .out, $(basename $(SRCS))))
$(shell mkdir -p $(BUILD))

$(BUILD)/%: %.cpp
	g++ $(CFLAGS) $< $(LDFLAGS) -o $@

build: $(OBJS)
run: build
	@$(BUILD)/$(ID).out

clean:
	@rm -rf ./build
include ../Makefile
BUILD := ./build
SRCS := hello.cpp
OBJS      = $(addprefix $(BUILD)/, $(addsuffix .out, $(basename $(SRCS))))
$(shell mkdir -p $(BUILD))

$(BUILD)/%: %.cpp
	g++ $(CFLAGS) $< $(LDFLAGS) -o $@

build: $(OBJS)
run: build
	@$(OBJS)

clean:
	@rm -rf ./build
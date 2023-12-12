include ../Makefile
BUILD := ./build
SRCS := data.cpp std.cpp test.cpp
OBJS      = $(addprefix $(BUILD)/, $(basename $(SRCS)))
$(shell mkdir -p $(BUILD))

$(BUILD)/%: %.cpp
	@g++ $(CFLAGS) $< $(LDFLAGS) -o $@

build: $(OBJS)

test: build
	@while true; do \
		./$(BUILD)/data > $(BUILD)/data.in ; \
		./$(BUILD)/std < $(BUILD)/data.in > $(BUILD)/std.out ; \
		./$(BUILD)/test < $(BUILD)/data.in > $(BUILD)/test.out ; \
		if diff $(BUILD)/std.out $(BUILD)/test.out ; then \
			printf "AC\n" ; \
		else  \
			echo "WA" ; \
			exit 1 ; \
		fi ; \
	done
clean:
	@rm -rf ./build
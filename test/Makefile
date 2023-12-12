include ../Makefile
BUILD := ./build
SRCS := data.cpp std.cpp test.cpp
$(shell mkdir -p $(BUILD))

$(BUILD)/%: %.cpp
	@g++ $(CFLAGS) $< $(LDFLAGS) -o $@


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
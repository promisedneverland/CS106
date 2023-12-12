include ../Makefile
BUILD := build

all:
	@mkdir -p $(BUILD)
	@g++ $(CFLAGS) ./data.cpp $(LDFLAGS) -o $(BUILD)/data
	@g++ $(CFLAGS) ./std.cpp $(LDFLAGS) -o $(BUILD)/std
	@g++ $(CFLAGS) ./test.cpp $(LDFLAGS) -o $(BUILD)/test
test: all
	@while true; do \
		./$(BUILD)/data > $(BUILD)/data.in; \
		./$(BUILD)/std < $(BUILD)/data.in > $(BUILD)/std.out; \
		./$(BUILD)/test < $(BUILD)/data.in > $(BUILD)/test.out; \
		if diff $(BUILD)/std.out $(BUILD)/test.out ; then \
			printf AC; \
		else  \
			echo WA; \
			exit 0; \
		fi; \
	done 
include ../Makefile
BUILD := build

CFLAGS := $(INCFLAGS)
test:
	mkdir -p $(BUILD)
	g++ $(CFLAGS) ./data.cpp -o $(BUILD)/data
	g++ $(CFLAGS) ./std.cpp -o $(BUILD)/std
	g++ $(CFLAGS) ./test.cpp -o $(BUILD)/test
	while true; do
		./$(BUILD)/data > $(BUILD)/data.in
		./$(BUILD)/std < data.in > std.out
		./$(BUILD)/test < data.in > test.out
	if diff std.out test.out ; then
		printf AC
	else 
		echo WA
		exit 0
	fi
	done
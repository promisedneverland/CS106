include ../Makefile
BUILD := build

build:
	@mkdir -p $(BUILD)
	@g++ $(CFLAGS) ./data.cpp $(LDFLAGS) -o $(BUILD)/data
	@g++ $(CFLAGS) ./std.cpp $(LDFLAGS) -o $(BUILD)/std
	@g++ $(CFLAGS) ./test.cpp $(LDFLAGS) -o $(BUILD)/test
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
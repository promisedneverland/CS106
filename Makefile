git:
	@git add . -A 
	@(uname -a && uptime) | git commit -F - --allow-empty
	@sync

all:
	echo all

test:
	g++ ./data.cpp -o data
	g++ ./std.cpp -o std
	while true; do
		./data > data.in
		../multimod-32 < data.in > main.out
		./std < data.in > std.out
	if diff std.out main.out ; then
		printf AC
	else 
		echo WA
		exit 0
	fi
	done
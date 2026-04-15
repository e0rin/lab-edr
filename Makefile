CC = gcc
CFLAGS = -Wall -Wextra -Isrc

SRC = $(shell find src -name "*.c")
OUT = build/edr

all: $(OUT)

$(OUT): $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf build

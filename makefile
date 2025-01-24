CC = gcc
CFLAGS = -Wall -g
SRC = src/file/file.c src/turing-machine/turing-machine.c src/transition/transition.c src/main.c
OBJ = $(SRC:.c=.o)
OUT = main

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)

run: $(OUT)
	./$(OUT)

.PHONY: clean run
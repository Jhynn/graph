FILES = src/*.c display.c
OUT = display
include_dirs = -Ilib
CFLAGS = $(include_dirs) -O2 -Wall

all: $(FILES)
	$(CC) $(CFLAGS) -o $(OUT) $(FILES)
	./$(OUT)
clean:
	find . -iname '*~' -delete
	-rm $(OUT)

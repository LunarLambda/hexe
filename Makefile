include config.mk

hexe: main.c
	$(CC) $(CFLAGS) -o hexe main.c

install: hexe
	cp ./hexe $(PREFIX)/bin/hexe

clean:
	rm -f ./hexe

.PHONY: install clean

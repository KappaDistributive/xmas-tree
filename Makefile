CC=gcc

xmastree: xmastree.c strrep.c
	$(CC) -o xmastree xmastree.c strrep.c -I.

run: xmastree
	./xmastree

clean:
	rm xmastree

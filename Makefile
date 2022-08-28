CC=gcc
CFLAGS=-Wall
AR=ar
RANLIB=ranlib
LD=ld
all: liblfsr.a

liblfsr.a: lfsr.o
	$(AR) rsv $@ $?
	$(RANLIB) $@

.c .o:	*.h
	$(CC) $(CFLAGS) -o $@ $<
	
clean:
	rm -rf *.o
	rm -rf *.a

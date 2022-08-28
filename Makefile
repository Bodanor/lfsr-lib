CC=gcc
CFLAGS=-Wall
AR=ar
RANLIB=ranlib
LD=ld
all: liblfsr.a

liblfsr.a: lfsr.o
	@echo "[+] Archiving liblfsr.a"
	$(AR) rsv $@ $?
	$(RANLIB) $@

%.o: %.c
	@echo "[+] Building objects file for libfsr"
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -rf *.o
	rm -rf *.a

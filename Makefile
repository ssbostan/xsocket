# XSocket is a cross-platform socket library.
# Copyright (c) 2018 Saeid Bostandoust <ssbostan@gmail.com>

LIBDIR=/usr/lib
LIB64DIR=/usr/lib64
INCLUDEDIR=/usr/include
CC=gcc
CFLAGS=-Wall
CXXFLAGS=-fPIC -c
LDFLAGS=-shared
SONAME=libxsocket.so

$(SONAME): xsocket.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $?

xsocket.o: xsocket.c
	$(CC) $(CFLAGS) $(CXXFLAGS) -o $@ $?

.PHONY: install
install:
	cp $(SONAME) $(LIBDIR)
	ln -s $(LIBDIR)/$(SONAME) $(LIB64DIR)/$(SONAME)
	cp xsocket.h $(INCLUDEDIR)

.PHONY: uninstall
uninstall:
	rm -f $(LIB64DIR)/$(SONAME)
	rm -f $(LIBDIR)/$(SONAME)
	rm -f $(INCLUDEDIR)/xsocket.h

.PHONY: clean
clean:
	rm -f $(SONAME) xsocket.o

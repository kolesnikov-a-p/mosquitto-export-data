MOSQUITTO_SRC ?= ./

CFLAGS = -std=gnu99 -fPIC -I../lib -I../src -I../include -Wall -Wextra -O2

ifdef DEBUG
CFLAGS += -DPYAUTH_DEBUG -O0 -ggdb3
endif

LIBS = -lmosquitto
DESTDIR = /usr

ifdef USE_CARES
LIBS += -lcares
endif

CFLAGS += -I$(MOSQUITTO_SRC)/src/
CFLAGS += -I$(MOSQUITTO_SRC)/lib/
CFLAGS += -I$(MOSQUITTO_SRC)/include/

#LDFLAGS =-lmosquitto
LDFLAGS += -L$(MOSQUITTO_SRC)/lib/

all : export_data_plugin.so

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

export_data_plugin.so : export_data_plugin.o
	$(CC) $(CFLAGS) -shared -o $@ $^  $(LIBS)  $(LDFLAGS)

install: export_data_plugin.so
	install -s -m 755 export_data_plugin.so /etc/mosquitto/conf.d/export-data-plugin

clean :
	rm -f export_data_plugin.so *.o

.PHONY: all clean

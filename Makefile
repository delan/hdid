CFLAGS=-ansi -Wall -g
hdid: hdid.o util.o core.o man.o \
	maxtor.o quantum.o seagate.o samsung.o \
	conner.o toshiba.o hitachi.o wd.o
hdid.o: hdid.c hdid.h
util.o: util.c util.h
core.o: core.c core.h
man.o: man.c man.h
maxtor.o: maxtor.c maxtor.h
quantum.o: quantum.c quantum.h
seagate.o: seagate.c seagate.h
samsung.o: samsung.c samsung.h
conner.o: conner.c conner.h
toshiba.o: toshiba.c toshiba.h
hitachi.o: hitachi.c hitachi.h
wd.o: wd.c wd.h
clean:
	rm -fv hdid *.o *.stackdump

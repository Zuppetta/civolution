CC = g++
DEBUG = -g
CFLAGS = -O0 -Wall $(DEBUG) -c
LFLAGS = -O0 -Wall $(DEBUG)
OBJS =unit.o units/settler.o army.o
UNITS = units

.PHONY: units

units: unit.o
	$(MAKE) -C $(UNITS)

army.o: army.hpp army.cpp
	$(CC) $(CFLAGS) army.cpp

unit.o:	unit.hpp unit.cpp
	$(CC) $(UNITS) $(CFLAGS) unit.cpp

civolution: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o test

all: $(OBJS)
	make check_style
	make civolution

check_style:
	cpplint --recursive --extensions=hpp,cpp --linelength=78 \
	--filter=-legal/copyright --repository=./ ./

clean:
	rm ./*.o ./civolution
	$(MAKE) -C $(UNITS) clean

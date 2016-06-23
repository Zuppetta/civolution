CC = g++
DEBUG = -g
CFLAGS = -O0 -Wall $(DEBUG) -c
LFLAGS = -O0 -Wall $(DEBUG)
OBJS = civolution.o unit.o units/settler.o army.o
UNITS = units

.PHONY: units

units: unit.o
	$(MAKE) -C $(UNITS)

army.o: army.hpp army.cpp
	$(CC) $(CFLAGS) army.cpp

civolution.o: civolution.cpp
	$(CC) $(CFLAGS) civolution.cpp

unit.o:	unit.hpp unit.cpp
	$(CC) $(UNITS) $(CFLAGS) unit.cpp

civolution: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o civolution

all: $(OBJS)
	make check_style
	make civolution

check_style:
	cpplint --recursive --extensions=hpp,cpp --linelength=78 \
	--filter=-legal/copyright --repository=./ ./

clean:
	rm ./*.o ./civolution
	$(MAKE) -C $(UNITS) clean

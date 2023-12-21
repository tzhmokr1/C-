
# Makefile für Übung "Klasse Person"                          31.10.2019

BIN    = appl.exe
OBJS   = Person.o PersonTest.o 

CC     = g++
CFLAGS = -g -std=c++11 

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

clean:
	rm -f $(OBJS) $(BIN)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<


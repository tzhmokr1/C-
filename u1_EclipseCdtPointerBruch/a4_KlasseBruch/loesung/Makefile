
# Makefile für Übung "Klasse Bruch"                           30.10.2019

BIN    = appl.exe
OBJS   = Bruch.o BruchAppl.o

CC     = g++
CFLAGS = -g

all: $(BIN)


$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

clean:
	rm -f $(OBJS) $(BIN)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<


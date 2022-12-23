CC = g++
CFLAGS = -c
OFLAGS= -o
OBJFILES = Animation.o Player.o main.o
TARGET = main
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) $(TARGET).cpp
	$(CC) $(CFLAGS) source/Animation.cpp
	$(CC) $(CFLAGS) source/Player.cpp
	$(CC) $(OBJFILES) $(OFLAGS) bin/$(TARGET) $(LDFLAGS)
	chmod +x bin/$(TARGET)

clean: 
	rm bin/$(TARGET) $(OBJFILES)
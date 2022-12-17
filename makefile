CC = g++
CFLAGS = -c
OFLAGS= -o
TARGET = Map
CLINKERS = -lsfml-graphics -lsfml-window -lsfml-system


$(TARGET): $(TARGET).cpp
	rm $(TARGET) $(TARGET).o
	$(CC) $(CFLAGS) $(TARGET).cpp
	$(CC) $(TARGET).o $(OFLAGS) $(TARGET) $(CLINKERS)
	chmod +x $(TARGET)
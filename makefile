CC = g++
CFLAGS = -c
OFLAGS= -o
TARGET = Map
CLINKERS = -lsfml-graphics -lsfml-window -lsfml-system


$(TARGET): $(TARGET).cpp
	#rm bin/$(TARGET) $(TARGET).o
	$(CC) $(CFLAGS) $(TARGET).cpp 
	$(CC) $(TARGET).o $(OFLAGS) bin/$(TARGET) $(CLINKERS)
	chmod +x bin/$(TARGET)
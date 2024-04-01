CC = g++
TARGET = main

all:
	$(CC) -o $(TARGET) src/main.cpp src/game/*.cpp src/Player/*.cpp src/Shop/*.cpp src/Tax/*.cpp src/Item/*.cpp src/Item/Animal/*.cpp src/Item/Building/*.cpp src/Item/Plant/*.cpp src/Item/Products/*.cpp src/Command/AllCommand/*.cpp  src/Command/PetaniCommand/*.cpp src/Command/PeternakCommand/*.cpp src/Command/WalikotaCommand/*.cpp

clean:
	rm $(TARGET)
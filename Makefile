CC = g++
TARGET = main

all:
	$(CC) -std=c++11 -o $(TARGET) src/main.cpp src/game/*.cpp src/Player/*.cpp src/Shop/*.cpp src/Tax/*.cpp src/Item/*.cpp src/Item/Animal/*.cpp src/Item/Building/*.cpp src/Item/Plant/*.cpp src/Item/Products/*.cpp src/Command/AllCommand/*.cpp  src/Command/PetaniCommand/*.cpp src/Command/PeternakCommand/*.cpp src/Command/WalikotaCommand/*.cpp src/Storage/Storage.cpp src/FileIO/Loader.cpp src/misc/Misc.cpp src/Exception/FileException.cpp

clean:
	rm $(TARGET)
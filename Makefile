CC = g++
TARGET = main

all:
	$(CC) -std=c++17 -o $(TARGET) src/main.cpp src/Game/*.cpp src/Player/*.cpp src/Shop/*.cpp src/Tax/*.cpp src/Item/*.cpp src/Item/Animal/*.cpp src/Item/Building/*.cpp src/Item/Plant/*.cpp src/Item/Product/*.cpp src/Command/AllCommand/*.cpp  src/Command/PetaniCommand/*.cpp src/Command/PeternakCommand/*.cpp src/Command/WalikotaCommand/*.cpp src/Storage/Storage.cpp src/FileIO/Loader.cpp src/FileIO/Saver.cpp src/Misc/Misc.cpp

clean:
	rm $(TARGET)
CC = g++
TARGET = main

all:
	$(CC) -o $(TARGET) src/main.cpp src/game/game.cpp src/Player/Player.cpp src/Player/Mayor.cpp src/Player/PlantFarmer.cpp  src/Player/AnimalFarmer.cpp src/Command/AllCommand/Beli.cpp src/Command/AllCommand/CetakStorage.cpp src/Command/AllCommand/Jual.cpp src/Command/AllCommand/Makan.cpp src/Command/AllCommand/Next.cpp src/Command/AllCommand/Panen.cpp src/Command/PetaniCommand/Tanam.cpp src/Command/PeternakCommand/Ternak.cpp src/Command/PeternakCommand/KasihMakan.cpp src/Command/WalikotaCommand/Bangun.cpp src/Command/WalikotaCommand/PungutPajak.cpp

clean:
	rm $(TARGET)
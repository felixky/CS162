CC = g++
exe_file = Pokegame
$(exe_file): World.o driver.o Trainer.o Location.o Pokemon.o Cave.o Pokestop.o Rock.o Psychic.o Flying.o
	$(CC) World.o driver.o Trainer.o Location.o Pokemon.o Cave.o Pokestop.o Rock.o Psychic.o Flying.o -o $(exe_file)
alt: 
	g++ World.cpp driver.cpp Trainer.cpp Location.cpp Pokemon.cpp Cave.cpp Pokestop.cpp Rock.cpp Psychic.cpp Flying.cpp -D DEBUG -o Debugfile
World.o: World.cpp
	$(CC) -c World.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
Trainer.o: Trainer.cpp
	$(CC) -c Trainer.cpp
Location.o: Location.cpp	
	$(CC) -c Location.cpp
Cave.o: Cave.cpp	
	$(CC) -c Cave.cpp
Pokestop.o: Pokestop.cpp	
	$(CC) -c Pokestop.cpp
Rock.o: Rock.cpp	
	$(CC) -c Rock.cpp
Psychic.o: Psychic.cpp	
	$(CC) -c Psychic.cpp
Flying.o: Flying.cpp	
	$(CC) -c Flying.cpp
clean:
	rm -f *.o $(exe_file)


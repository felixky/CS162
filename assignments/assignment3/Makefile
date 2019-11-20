CC=g++
exe_file=a.out
$(exe_file): driver.o World.o Creature.o Demon.o Human.o Elf.o Balrog.o Cyberdemon.o Witch.o
	$(CC) driver.o World.o Creature.o Demon.o Human.o Elf.o Balrog.o Cyberdemon.o Witch.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
World.o: World.cpp
	$(CC) -c World.cpp
Creature.o: Creature.cpp
	$(CC) -c Creature.cpp
Demon.o: Demon.cpp
	$(CC) -c Demon.cpp
Human.o: Human.cpp
	$(CC) -c Human.cpp
Elf.o: Elf.cpp
	$(CC) -c Elf.cpp
Cyberdemon.o: Cyberdemon.cpp
	$(CC) -c Cyberdemon.cpp
Balrog.o: Balrog.cpp
	$(CC) -c Balrog.cpp
Witch.o: Witch.cpp	
	$(CC) -c Witch.cpp
alt:
	g++ *.cpp -o a.out
clean:
	rm -f *.o $(exe_file)

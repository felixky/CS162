CC=g++
exe_file=Library
$(exe_file): driver.cpp library.o librarian.o cart.o patron.o
	$(CC) driver.cpp library.o librarian.o cart.o patron.o -o $(exe_file)
driver.o:driver.cpp
	$(CC) -c driver.cpp
library.o:library.cpp	
	$(CC) -c library.cpp
librarian.o:librarian.cpp	
	$(CC) -c librarian.cpp
cart.o:cart.cpp	
	$(CC) -c cart.cpp
patron.o:patron.cpp	
	$(CC) -c patron.cpp
clean:
	rm -f *.o $(exe_file)	

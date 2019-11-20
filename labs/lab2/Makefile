CC = g++
exe_file = out_exe
$(exe_file):driver.o webpage.o
	$(CC) driver.o webpage.o -o $(exe_file)
driver.o: driver.cpp	
	$(CC) -c driver.cpp
webpage.o: webpage.cpp
	$(CC) -c webpage.cpp

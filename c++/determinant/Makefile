all: clean determinant.exe

determinant.exe: Main.o Matrix.o
	$(CC) -g -o $@ $^ -lstdc++

Main.o:
	$(CC) -g -c -o $@ Main.cpp

Matrix.o:
	$(CC) -g -c -o $@ Matrix.cpp 


.PHONY: clean
clean:
	rm -f *.o determinant.exe
	
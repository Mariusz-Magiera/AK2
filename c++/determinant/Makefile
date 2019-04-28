all: clean determinant.exe

determinant.exe: Main.o Matrix.o
	$(CC) -o $@ $^ 

Main.o:
	$(CC) -c -o $@ Main.cpp

Matrix.o:
	$(CC) -c -o $@ Matrix.cpp 


.PHONY: clean
clean:
	rm -f *.o determinant.exe
	
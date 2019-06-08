OUTPUT=determinant_cpp.exe
all: clean $(OUTPUT)

$(OUTPUT): Main.o Matrix.o
	$(CC) -g -o $@ $^ -lstdc++

Main.o:
	$(CC) -g -c -o $@ Main.cpp

Matrix.o:
	$(CC) -g -c -o $@ Matrix.cpp 


.PHONY: clean
clean:
	rm -f *.o $(OUTPUT)
	
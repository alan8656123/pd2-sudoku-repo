Sudoku: Sudoku.o main.o
	g++ -o Sudoku main.o Sudoku.o

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp

main6.o: main6.cpp Sudoku.h
	g++ -c main.cpp

clean:
	rm Sudoku *.o

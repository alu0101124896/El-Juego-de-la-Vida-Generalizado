CC = g++
CXXFLAGS = -g

OBJS = ../src/cell.o ../src/cell1.o ../src/cell2.o ../src/cell3.o ../src/board.o ../src/main.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o game_of_life ${OBJS}

run:
	./game_of_life

clean:
	rm -rf ../*/*.o ./game_of_life
adventure: main.o emptySpace.o trap.o treasure.o opponent.o player.o game.o gridElement.o
	g++ -o adventure main.o emptySpace.o trap.o treasure.o opponent.o player.o game.o gridElement.o

main.o: main.cpp
	g++ -c main.cpp  -g

emptySpace.o: emptySpace.cpp emptySpace.h gridElement.h
	g++ -c emptySpace.cpp -g

gridElement.o: gridElement.cpp gridElement.h
	g++ -c gridElement.cpp -g

trap.o: trap.cpp trap.h player.h
	g++ -c trap.cpp -g

treasure.o: treasure.cpp treasure.h player.h
	g++ -c treasure.cpp -g

opponent.o: opponent.cpp opponent.h player.h game.h emptySpace.h gridElement.h
	g++ -c opponent.cpp -g

player.o: player.cpp player.h game.h emptySpace.h trap.h treasure.h
	g++ -c player.cpp -g

game.o: game.cpp game.h player.h dynamicArray.h emptySpace.h trap.h treasure.h opponent.h
	g++ -c game.cpp -g

clean:
	rm *.o adventure

cleano:
	rm *.o
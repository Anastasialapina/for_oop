all: main.o cell.o square.o game.o player.o squareiterator.o element.o element_factory.o logfile.o logplayer.o observer.o observer_act.o observer_killed.o
	g++ main.o cell.o square.o game.o player.o squareiterator.o element.o logfile.o element_factory.o logplayer.o observer.o observer_act.o observer_killed.o -o game  -L/home/white_lilac/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp game.h
	g++ -c main.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics

cell.o: cell.cpp cell.h
	g++ -c cell.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics 

element_factory.o: element_factory.cpp element_factory.h element.h
	g++ -c element_factory.cpp

square.o: square.cpp square.h cell.h
	g++ -c square.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics
	
element.o: element.cpp element.h
	g++ -c element.cpp

game.o: game.cpp game.h squareiterator.h player.h
	g++ -c game.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics

player.o: player.cpp player.h 
	g++ -c player.cpp

	
squareiterator.o: squareiterator.cpp squareiterator.h square.h
	g++ -c squareiterator.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics
	
logfile.o: logfile.cpp logfile.h
	g++ -c logfile.cpp

logplayer.o: logplayer.cpp logplayer.h logfile.o 
	g++ -c logplayer.cpp
	
observer.o: observer.cpp observer.h 
	g++ -c observer.cpp
	
observer_act: observer_act.cpp observer_act.h observer.h
	g++ -c observer_act.cpp
	
observer_killed: observer_killed.cpp observer_killed.h obeserver.h
	g++ -c observer_killed.cpp

clean:
	rm -rf *.o


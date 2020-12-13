all: main.o cell.o square.o game.o player.o squareiterator.o element.o element_factory.o logfile.o logplayer.o observer.o observer_act.o observer_killed.o command.o command_move.o command_info.o command_createsquare.o command_drawplayer.o command_gameend.o command_clearcell.o facade.o enemy.o behavior.o safe.o

	g++ main.o cell.o square.o game.o player.o squareiterator.o element.o logfile.o element_factory.o logplayer.o observer.o observer_act.o observer_killed.o command.o command_gameend.o command_info.o command_move.o command_createsquare.o command_clearcell.o facade.o command_drawplayer.o enemy.o behavior.o safe.o -o game  -L/home/white_lilac/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system

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

game.o: game.cpp game.h squareiterator.h enemy.h
	g++ -c game.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics

player.o: player.cpp player.h 
	g++ -c player.cpp

	
squareiterator.o: squareiterator.cpp squareiterator.h square.h
	g++ -c squareiterator.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics
	
logfile.o: logfile.cpp logfile.h
	g++ -c logfile.cpp

logplayer.o: logplayer.cpp logplayer.h logfile.o 
	g++ -c logplayer.cpp
	

observer_act.o: observer_act.cpp observer_act.h observer.h
	g++ -c observer_act.cpp
	
observer_killed.o: observer_killed.cpp observer_killed.h observer.h
	g++ -c observer_killed.cpp
	
observer.o: observer.cpp observer.h 
	g++ -c observer.cpp
	
command.o: command.cpp command.h game.h
	g++ -c command.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics
	
command_move.o: command_move.cpp command_move.h command.h 
	g++ -c command_move.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics
	
command_info.o: command_info.cpp command_info.h command.h 
	g++ -c command_info.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics

command_createsquare.o: command_createsquare.cpp command_createsquare.h command.h
	g++ -c command_createsquare.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics

command_drawplayer.o: command_drawplayer.cpp command_drawplayer.h command.h
	g++ -c command_drawplayer.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics
	
command_gameend.o: command_gameend.cpp command_gameend.h command.h
	g++ -c command_gameend.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics
	
command_clearcell.o: command_clearcell.cpp command_clearcell.h command.h
	g++ -c command_clearcell.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics
	
facade.o: facade.cpp facade.h 
	g++ -c facade.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics
	
enemy.o: enemy.cpp enemy.h behavior.h
	g++ -c enemy.cpp -I/home/white_lilac/SFML-2.5.1/include -lsfml-graphics

behavior.o: behavior.cpp behavior.h player.h
	g++ -c behavior.cpp
	
safe.o: safe.cpp safe.h
	g++ -c safe.cpp

clean:
	rm -rf *.o


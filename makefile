# FIXME: These files may be recompiled even if there are no changes.

main: main.o entity.o bin
	g++ -o bin/main bin/main.o bin/entity.o -L lib/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: bin
	g++ -c src/main.cpp -o bin/main.o -I lib/SFML-2.5.1/include

event.o: bin
	g++ -c src/event.cpp -o bin/event.o

entity.o: bin
	g++ -c src/entity.cpp -o bin/entity.o

bin:
	mkdir -p bin

# FIXME: These files may be recompiled even if there are no changes.

main: main.o bin
	g++ -o bin/main bin/main.o

main.o: bin
	g++ -c src/main.cpp -o bin/main.o

event.o: bin
	g++ -c src/event.cpp -o bin/event.o

entity.o: bin
	g++ -c src/entity.cpp -o bin/entity.o

bin:
	mkdir -p bin

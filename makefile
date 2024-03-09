SRCD=src
HDRD=headers
OBJD=obj

PROJET_O= iBlock.o shape.o tetris.o main.o

COMPILE_OPTIONS=-Wall -g -I"../SFML-2.5.1/include"
LINKER_OPTIONS=-L"../SFML-2.5.1/lib" -lsfml-graphics -lsfml-window -lsfml-system

tetris: $(addprefix $(OBJD)/, $(PROJET_O))
	g++ -o tetris $^ $(LINKER_OPTIONS)

obj/iBlock.o: src/iBlock.cpp headers/iBlock.hpp headers/shape.hpp
	g++  -o $@ $(COMPILE_OPTIONS) -c src/iBlock.cpp 

obj/shape.o: src/shape.cpp headers/shape.hpp  headers/iBlock.hpp
	g++ -o $@ $(COMPILE_OPTIONS) -c src/shape.cpp 

obj/tetris.o: src/tetris.cpp headers/tetris.hpp headers/iBlock.hpp headers/shape.hpp
	g++ -o $@ $(COMPILE_OPTIONS) -c src/tetris.cpp

obj/main.o: src/main.cpp headers/tetris.hpp headers/iBlock.hpp headers/shape.hpp
	g++ -o $@ $(COMPILE_OPTIONS) -c src/main.cpp
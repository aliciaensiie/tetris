SRCD=src
HDRD=headers
OBJD=obj

PROJET_O= zBlock.o sBlock.o tBlock.o jBlock.o lBlock.o oBlock.o iBlock.o shape.o tetris.o main.o

COMPILE_OPTIONS=-Wall -g -I"../SFML-2.5.1/include"
LINKER_OPTIONS=-L"../SFML-2.5.1/lib" -lsfml-graphics -lsfml-window -lsfml-system

tetris: $(addprefix $(OBJD)/, $(PROJET_O))
	g++ -o tetris $^ $(LINKER_OPTIONS)

obj/zBlock.o: src/zBlock.cpp headers/zBlock.hpp headers/shape.hpp
	g++  -o $@ $(COMPILE_OPTIONS) -c src/zBlock.cpp

obj/sBlock.o: src/sBlock.cpp headers/sBlock.hpp headers/shape.hpp
	g++  -o $@ $(COMPILE_OPTIONS) -c src/sBlock.cpp

obj/tBlock.o: src/tBlock.cpp headers/tBlock.hpp headers/shape.hpp
	g++  -o $@ $(COMPILE_OPTIONS) -c src/tBlock.cpp

obj/jBlock.o: src/jBlock.cpp headers/jBlock.hpp headers/shape.hpp
	g++  -o $@ $(COMPILE_OPTIONS) -c src/jBlock.cpp

obj/lBlock.o: src/lBlock.cpp headers/lBlock.hpp headers/shape.hpp
	g++  -o $@ $(COMPILE_OPTIONS) -c src/lBlock.cpp

obj/oBlock.o: src/oBlock.cpp headers/oBlock.hpp headers/shape.hpp
	g++  -o $@ $(COMPILE_OPTIONS) -c src/oBlock.cpp

obj/iBlock.o: src/iBlock.cpp headers/iBlock.hpp headers/shape.hpp
	g++  -o $@ $(COMPILE_OPTIONS) -c src/iBlock.cpp 

obj/shape.o: src/shape.cpp headers/shape.hpp  headers/iBlock.hpp
	g++ -o $@ $(COMPILE_OPTIONS) -c src/shape.cpp 

obj/tetris.o: src/tetris.cpp headers/tetris.hpp headers/iBlock.hpp headers/shape.hpp
	g++ -o $@ $(COMPILE_OPTIONS) -c src/tetris.cpp

obj/main.o: src/main.cpp headers/tetris.hpp headers/iBlock.hpp headers/shape.hpp
	g++ -o $@ $(COMPILE_OPTIONS) -c src/main.cpp
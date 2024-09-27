all:
	clang++ src/*.cpp -o bin/Tetris -lsfml-graphics -lsfml-window -lsfml-system

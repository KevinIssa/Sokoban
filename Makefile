FLAGS=-std=c++20 -Wall -lfltk -lfltk_images
COMPILER=g++

main: main.cpp sokoban.o controller.o 
	${COMPILER} -o soko main.cpp sokoban.o controller.o ${FLAGS}

run:
	make main && ./soko

sokoban.o: sokoban.cpp sokoban.h controller.o
	${COMPILER} -c sokoban.cpp ${FLAGS}

controller.o: controller.cpp controller.h
	${COMPILER} -c controller.cpp ${FLAGS}

clean:
	rm *.o





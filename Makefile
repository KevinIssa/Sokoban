FLAGS=-std=c++20 -Wall
COMPILER=g++
FLAGS += $(shell fltk-config --cxxflags | sed 's/-I/-isystem/g')
LDFLAGS  += $(shell fltk-config --ldflags)

main: main.cpp sokoban.o controller.o displayer.o button.o 
	${COMPILER} -o soko main.cpp sokoban.o controller.o displayer.o button.o ${FLAGS} ${LDFLAGS} -lfltk -lfltk_images

run:
	make main && ./soko

sokoban.o: sokoban.cpp sokoban.hpp controller.o
	${COMPILER} -c sokoban.cpp ${FLAGS} ${LDFLAGS}

controller.o: controller.cpp controller.hpp
	${COMPILER} -c controller.cpp ${FLAGS} ${LDFLAGS}

displayer.o: displayer.cpp displayer.hpp
	${COMPILER} -c displayer.cpp ${FLAGS} ${LDFLAGS}

button.o: button.cpp button.hpp
	${COMPILER} -c button.cpp ${FLAGS} ${LDFLAGS}



.PHONY: clean
clean:
	-rm *.o






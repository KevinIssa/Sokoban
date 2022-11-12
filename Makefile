CXXFLAGS += $(shell fltk-config --cxxflags | sed 's/-I/-isystem/g')
LDFLAGS  += $(shell fltk-config --ldflags)

CXXFLAGS += -std='c++20' -Wall -Wextra -Wsign-compare -pedantic
LDFLAGS  += -lfltk

BINS = $(patsubst %.cpp, %, $(wildcard *.cpp))

# Première recette = recette par défaut.
.PHONY: default
default: main

# Recette magique
%: %.cpp
	${CXX} ${CXXFLAGS} $< -o $@ ${LDFLAGS}

# make clean supprime les fichiers objets
.PHONY: clean
clean:
	-rm *.o

# make mrclean supprime les fichiers objets et les exécutables
.PHONY: mrclean
mrclean: clean
	-rm ${BINS}


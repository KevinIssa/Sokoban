

main:main.cpp sokoban.cpp
	g++ -std=c++20 main.cpp -o soko -lfltk -lfltk_images && ./soko


	# g++ -std=c++20 main.cpp sokoban.cpp -o soko -lfltk -lfltk_images && ./soko
	# g++ -std=c++20 -Wall -Wpedantic -Werror main.cpp sokoban.cpp -o soko -lfltk -lfltk_images && ./soko



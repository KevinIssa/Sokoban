# all:ex12 ex12_2 test ex12_2.1 ex16 ex17

main:main.cpp sokoban.cpp
	g++ -std=c++11 main.cpp sokoban.cpp -o soko -lfltk -lfltk_images



# ex12_2:ex12_2.cpp
# 	g++ ex12_2.cpp -o ex12_2 -Wall -Wextra
# test:test.cpp
# 	g++ test.cpp -o test -Wall -Wextra
# ex12_2.1:ex12_2.1.cpp
# 	g++ ex12_2.1.cpp -o ex12_2.1 -Wall -Wextra
# ex16:ex16.cpp
# 	g++ ex16.cpp -o ex16 -Wall -Wextra
# ex17:ex17.cpp
# 	g++ ex17.cpp -o ex17 -Wall -Wextra
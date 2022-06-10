 snake.exe:
	g++ -c src/main.cc 
	g++ main.o -o snake -lsfml-graphics -lsfml-window -lsfml-system
	./snake
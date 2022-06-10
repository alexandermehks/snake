 CC = g++
 BINARY = snake
 all:
	$(CC) -c src/main.cc 
	$(CC) main.o -o $(BINARY) -lsfml-graphics -lsfml-window -lsfml-system
	./$(BINARY)

clean:
	rm -rf $(BINARY) *.o
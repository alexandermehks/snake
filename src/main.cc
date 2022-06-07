#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/snake.h"

int main()
{
     uint32_t width = 1200;
     uint32_t height = 750;
     sf::RenderWindow window(sf::VideoMode(width, height), "Annoying Disco");

     Snake snake;
     Food food;

     while (window.isOpen())
     {
          sf::Event event;
          while (window.pollEvent(event))
          {
               if (event.type == sf::Event::Closed)
                    window.close();
          }

          window.clear();
          
          renderSnake(window, snake);
          spawnFood(window, food);
          eat(snake, food);
          moveSnake(window, snake);
          window.display();
     }

     return 0;
}
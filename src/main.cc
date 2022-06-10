#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/snake.h"
#include <sstream>

int main()
{
     uint32_t width = 1200;
     uint32_t height = 750;
     sf::RenderWindow window(sf::VideoMode(width, height), "You are bored");
     window.setFramerateLimit(30);

     sf::Texture texture;
     texture.loadFromFile("res/board.png");
     sf::Sprite sprite;
     sprite.setTexture(texture);
     sprite.setScale(20,20);

     sf::Font font;
     if(!font.loadFromFile("res/font.ttf")){
          std::cout << "error";
     }

     Snake snake;
     Food food;
     
     sf::Text score; 
     score.setFont(font);
     score.setFillColor(sf::Color(0,0,0));
     score.setPosition(1160, 0);

     while (window.isOpen())
     {
          sf::Event event;
          while (window.pollEvent(event))
          {
               if (event.type == sf::Event::Closed)
                    window.close();
          }
          window.clear();
          window.draw(sprite);
          update(window, snake, food);
          score.setString(std::to_string(snake.length));
          window.draw(score);
          window.display();
     }
     return 0;
}

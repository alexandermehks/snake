#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "food.h"

struct Snake{
     //Parameters
     int length = 1;
     int speed = 20;
     float x_pos = 350;
     float y_pos = 350;
     int eat_cooldown = 0;
};

//Implemented this not working collision detection system, hehe.
void eat(Snake &snake, Food &food){
          //distance formula
          if(food.hasFoodOnMap && snake.eat_cooldown == 0){
               int v1 = (food.x_pos - snake.x_pos)*2;
               int v2 = (food.y_pos - snake.y_pos)*2;
               int v3 = v1 + v2; 
               v3 = abs(v3);
               int distance = sqrt(v3);
               std::cout << distance << std::endl;
               if(distance <= 5){
                    food.hasFoodOnMap = false;
                    snake.length++;
                    snake.eat_cooldown = 5;
          }
          }
          if(snake.eat_cooldown != 0){
               snake.eat_cooldown -= 1;
          }
     }

void renderSnake(sf::RenderWindow &window, Snake &snake){
     sf::RectangleShape rectshape;
     rectshape.setSize(sf::Vector2f(20,20));
     rectshape.setPosition(snake.x_pos, snake.y_pos);
     window.draw(rectshape);
}

bool isInsideMap(sf::RenderWindow &window, Snake &snake, int action){
     //left
     if (action == 1 && snake.x_pos > 0){
          return true;
     }
     //right
     if (action == 2 && snake.x_pos < window.getSize().x - 20){
          return true;
     }
     //up
     if (action == 3 && snake.y_pos > 0){
          return true;
     }
     //down
     if (action == 4 && snake.y_pos < window.getSize().y - 20){
          return true;
     }
     return false;
}

void moveSnake(sf::RenderWindow &window, Snake &snake){
     //left
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
          if(isInsideMap(window, snake, 1)){
               snake.x_pos -=  snake.speed;
          }
     }
     //right
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
          if(isInsideMap(window, snake, 2)){
               snake.x_pos += snake.speed; 
          }
     }
     //up
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
          if(isInsideMap(window, snake, 3)){
               snake.y_pos -= snake.speed; 
          }
     }//down
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
          if(isInsideMap(window,snake,4)){
               snake.y_pos += snake.speed; 
          }
     }
}

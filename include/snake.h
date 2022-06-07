#include <iostream>
#include <SFML/Graphics.hpp>
#include "food.h"

struct Snake{

     //Parameters
     int length = 1;
     float x_pos = 350;
     float y_pos = 350;



};

//Implemented this not working collision detection system, hehe.
void eat(Snake &snake, Food &food){
     if( food.x_pos + 20== int(snake.x_pos)) {
          if(food.y_pos + 20 == int(snake.y_pos)){
               std::cout << "HIT" << std::endl;
          }
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
               snake.x_pos -=  0.1;
          }
     }
     //right
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
          if(isInsideMap(window, snake, 2)){
               snake.x_pos +=  0.1;
          }
     }
     //up
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
          if(isInsideMap(window, snake, 3)){
               snake.y_pos -=  0.1;
          }
     }//down
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
          if(isInsideMap(window,snake,4)){
               snake.y_pos +=  0.1;
          }
     }
}




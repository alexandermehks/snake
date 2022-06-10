#include <math.h>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "food.h"

struct Snake{
     //Parameters
     int length = 1;
     int speed = 20;
     float x_pos ;
     float y_pos ;
     int eat_cooldown = 0;
   


     Snake() = default;
     
};


void eat(sf::RectangleShape &rectshape, sf::CircleShape &shape, Snake &snake, Food &food){
     if(snake.eat_cooldown != 0){
          snake.eat_cooldown -= 1;
     }
     if(rectshape.getGlobalBounds().intersects(shape.getGlobalBounds()) && snake.eat_cooldown == 0){
          food.hasFoodOnMap = false;
          snake.length++;
          snake.eat_cooldown = 10;
     }

}

void renderSnake(sf::RenderWindow &window, Snake &snake, Food &food){
     //Rendering snake
     sf::RectangleShape rectshape;
     rectshape.setSize(sf::Vector2f(10,10));
     rectshape.setPosition(snake.x_pos, snake.y_pos);

     //Render food
     sf::CircleShape shape(20);
     shape.setPosition(food.x_pos, food.y_pos);
     shape.setFillColor(sf::Color::Red);


     eat(rectshape, shape, snake, food);
     //Drawing to game window
     
     window.draw(rectshape);
     window.draw(shape);

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


void update(sf::RenderWindow &window, Snake &snake, Food &food){
          spawnFood(window, food);
          moveSnake(window, snake);
          renderSnake(window, snake, food);
}

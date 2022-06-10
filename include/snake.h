#include <math.h>
#include <vector>
#include <deque>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "food.h"

struct Snake{
     //Parameters
     int length = 0;
     int speed = 20;
     float x_pos ;
     float y_pos ;
     int eat_cooldown = 0;
     int direction;
     std::deque<sf::Vector2f> trail;
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
     if(snake.trail.size() > 50){
          snake.trail.pop_back();
     }
     snake.trail.push_front(sf::Vector2f(snake.x_pos, snake.y_pos));

     sf::RectangleShape snake_shape;
     snake_shape.setSize(sf::Vector2f(10,10));
     //snake_shape.setPosition(snake.x_pos ,snake.y_pos);

     for (int i = 0; i < snake.length; i++){
               snake_shape.setPosition(snake.trail[i]);
               snake_shape.setFillColor(sf::Color(0,0,0));
               window.draw(snake_shape);
     }
     snake_shape.setPosition(snake.x_pos, snake.y_pos);

     //Render food
     sf::CircleShape shape(20);
     shape.setPosition(food.x_pos, food.y_pos);
     shape.setFillColor(sf::Color::Red);

     eat(snake_shape, shape, snake, food);
     //Drawing to game window
     
     window.draw(snake_shape);
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
               snake.direction = 1;
          }
     }
     //right
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
          if(isInsideMap(window, snake, 2)){
               snake.x_pos += snake.speed; 
               snake.direction = 2;
          }
     }
     //up
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
          if(isInsideMap(window, snake, 3)){
               snake.y_pos -= snake.speed; 
               snake.direction = 3;
          }
     }//down
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
          if(isInsideMap(window,snake,4)){
               snake.y_pos += snake.speed; 
               snake.direction = 4;
          }
     }
}

void update(sf::RenderWindow &window, Snake &snake, Food &food){
          spawnFood(window, food);
          moveSnake(window, snake);
          renderSnake(window, snake, food);
}
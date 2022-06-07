struct Food{
     float x_pos = 0;
     float y_pos = 0;
     bool hasFoodOnMap = false;



};


void renderFood(sf::RenderWindow & window, Food &food){
     sf::CircleShape shape(20);
     shape.setPosition(food.x_pos, food.y_pos);
     window.draw(shape);
}

void spawnFood(sf::RenderWindow &window, Food &food){
     if(!food.hasFoodOnMap){
          srand(time(0));
          int random_x = rand() % window.getSize().x;
          int random_y = rand() % window.getSize().y;
          food.x_pos = random_x;
          food.y_pos = random_y;
          food.hasFoodOnMap = true;
     }
     
          sf::CircleShape shape(20);
          shape.setPosition(food.x_pos, food.y_pos);
          window.draw(shape);
}


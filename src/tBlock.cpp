#include "../headers/tBlock.hpp"
#include <iostream>

//PRIVATE
void TBlock::createShape(sf::Color color){ //vector sshpe sert à rien
    for (int i=0; i<4; i++){
        sf::RectangleShape square(sf::Vector2f(SIZE_SQUARE, SIZE_SQUARE));
        square.setFillColor(color);
        vector_square.push_back(square);
    }
    vector_square[0].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE, 0));
    vector_square[1].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE - SIZE_SQUARE, 0));
    vector_square[2].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE + SIZE_SQUARE, 0));
    vector_square[3].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE , SIZE_SQUARE));
     
}

//PUBLIC
TBlock::TBlock(): Shape(){
    sf::Color color=colorShape();
    createShape(color);
    
}

void TBlock::turn(std::vector<std::vector<int>> completed_square){
    sf::Vector2f vector = vector_square[0].getPosition();
    sf::Vector2f vector_unit_square = getPositionSquare(vector_square[0]);
    if (way == Way::South){
        if (vector_unit_square.x -1 >= 0 && vector_unit_square.y -1 >=0 && vector_unit_square.y +1 < NUMBER_SQUARE_HEIGHT){

            if (completed_square[vector_unit_square.x - 1][vector_unit_square.y]==0 
                && completed_square[vector_unit_square.x ][vector_unit_square.y-1]==0
                && completed_square[vector_unit_square.x][vector_unit_square.y +1]==0){

                    vector_square[1].setPosition(vector.x , vector.y - SIZE_SQUARE);
                    vector_square[2].setPosition(vector.x - SIZE_SQUARE, vector.y );
                    vector_square[3].setPosition(vector.x , vector.y + SIZE_SQUARE);
                }
        }
        
    }
    else if (way == Way::West){
        if (vector_unit_square.x -1 >= 0 && vector_unit_square.x +1 < NUMBER_SQUARE_LENGTH && vector_unit_square.y -1 >=0){

            if (completed_square[vector_unit_square.x - 1][vector_unit_square.y]==0 
                && completed_square[vector_unit_square.x +1][vector_unit_square.y ]==0
                && completed_square[vector_unit_square.x][vector_unit_square.y -1]==0){

                    vector_square[1].setPosition(vector.x + SIZE_SQUARE , vector.y );
                    vector_square[2].setPosition(vector.x, vector.y - SIZE_SQUARE);
                    vector_square[3].setPosition(vector.x - SIZE_SQUARE, vector.y );
                }
        }
        
    }
    else if (way == Way::North){
        if (vector_unit_square.x +1 <NUMBER_SQUARE_LENGTH && vector_unit_square.y -1 >=0 && vector_unit_square.y +1 <NUMBER_SQUARE_HEIGHT){

            if (completed_square[vector_unit_square.x][vector_unit_square.y+1]==0 
                && completed_square[vector_unit_square.x +1 ][vector_unit_square.y]==0
                && completed_square[vector_unit_square.x][vector_unit_square.y -1]==0){

                    vector_square[1].setPosition(vector.x , vector.y + SIZE_SQUARE);
                    vector_square[2].setPosition(vector.x + SIZE_SQUARE, vector.y );
                    vector_square[3].setPosition(vector.x, vector.y - SIZE_SQUARE);
                }
        }
        
    }
    else{
        if (vector_unit_square.x +1 < NUMBER_SQUARE_LENGTH && vector_unit_square.x -1 >=0 && vector_unit_square.y +1 < NUMBER_SQUARE_HEIGHT){

            if (completed_square[vector_unit_square.x-1][vector_unit_square.y]==0 
                && completed_square[vector_unit_square.x +1 ][vector_unit_square.y]==0
                && completed_square[vector_unit_square.x][vector_unit_square.y +1]==0){

                    vector_square[1].setPosition(vector.x - SIZE_SQUARE , vector.y );
                    vector_square[2].setPosition(vector.x, vector.y + SIZE_SQUARE);
                    vector_square[3].setPosition(vector.x + SIZE_SQUARE, vector.y);
                }
        }
    }
    way=static_cast<Way>( (static_cast<int>(way) + 1) %4) ;
}
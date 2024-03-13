#include "../headers/iBlock.hpp"
#include <iostream>

//PRIVATE
void IBlock::createShape(sf::Color color){
    for (int i=0; i<4; i++){
        sf::RectangleShape square(sf::Vector2f(SIZE_SQUARE, SIZE_SQUARE));
        square.setFillColor(color);
        square.setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE ,  i*SIZE_SQUARE));
        vector_square.push_back(square);
    }
     
}

//PUBLIC
IBlock::IBlock(): Shape(){
    sf::Color color=colorShape();
    createShape(color);
    
}

void IBlock::turn(std::vector<std::vector<int>> completed_square){
    sf::Vector2f vector = vector_square[2].getPosition();
    sf::Vector2f vector_unit_square = getPositionSquare(vector_square[2]);
    if (way == Way::South || way == Way::North){
        if (vector_unit_square.x -2 >= 0 && vector_unit_square.x +1 < NUMBER_SQUARE_LENGTH){

            if (completed_square[vector_unit_square.x - 1][vector_unit_square.y]==0 
                && completed_square[vector_unit_square.x -2 ][vector_unit_square.y]==0
                && completed_square[vector_unit_square.x + 1][vector_unit_square.y]==0){

                    vector_square[0].setPosition(vector.x - 2*SIZE_SQUARE , vector.y);
                    vector_square[1].setPosition(vector.x - SIZE_SQUARE, vector.y );
                    vector_square[3].setPosition(vector.x + SIZE_SQUARE, vector.y);
                }
        }
        
    }

    else{
        if (vector_unit_square.y -1 >= 0 && vector_unit_square.y +2 < NUMBER_SQUARE_HEIGHT){
            
            if (completed_square[vector_unit_square.x][vector_unit_square.y-1]==0 
                && completed_square[vector_unit_square.x ][vector_unit_square.y +1]==0
                && completed_square[vector_unit_square.x ][vector_unit_square.y +2]==0){

                    vector_square[0].setPosition(vector.x , vector.y + 2*SIZE_SQUARE);
                    vector_square[1].setPosition(vector.x , vector.y + SIZE_SQUARE);
                    vector_square[3].setPosition(vector.x , vector.y - SIZE_SQUARE);
                }
        }
    }
    way=static_cast<Way>( (static_cast<int>(way) + 1) %4) ;
}
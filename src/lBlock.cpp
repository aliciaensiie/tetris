#include "../headers/lBlock.hpp"
#include <iostream>

//PRIVATE
std::vector<sf::RectangleShape> LBlock::createShape(std::vector<sf::RectangleShape> vector_shape, sf::Color color){
    for (int i=0; i<4; i++){
        sf::RectangleShape square(sf::Vector2f(SIZE_SQUARE, SIZE_SQUARE));
        square.setFillColor(color);
        
        vector_shape.push_back(square);
    }
    vector_shape[0].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE + SIZE_SQUARE , 2*SIZE_SQUARE));
    vector_shape[1].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE , 2*SIZE_SQUARE));
    vector_shape[2].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE, SIZE_SQUARE));
    vector_shape[3].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE , 0));
    return vector_shape;
     
}

//PUBLIC
LBlock::LBlock(): Shape(){
    sf::Color color=colorShape();
    vector_square = createShape(vector_square, color);
    
}

void LBlock::turn(std::vector<std::vector<int>> completed_square){
    sf::Vector2f vector = vector_square[2].getPosition();
    sf::Vector2f vector_unit_square = getPositionSquare(vector_square[2]);
    if (way == 0){
        if (vector_unit_square.x -1 >= 0 && vector_unit_square.x +1 < NUMBER_SQUARE_LENGTH && vector_unit_square.y +1 < NUMBER_SQUARE_HEIGHT){

            if (completed_square[vector_unit_square.x - 1][vector_unit_square.y]==0 
                && completed_square[vector_unit_square.x +1 ][vector_unit_square.y]==0
                && completed_square[vector_unit_square.x - 1][vector_unit_square.y +1]==0){

                    vector_square[0].setPosition(vector.x - SIZE_SQUARE , vector.y + SIZE_SQUARE);
                    vector_square[1].setPosition(vector.x - SIZE_SQUARE, vector.y );
                    vector_square[3].setPosition(vector.x + SIZE_SQUARE, vector.y);
                }
        }
        
    }
    else if (way == 1){
        if (vector_unit_square.x -1 >= 0 && vector_unit_square.y -1 >=0 && vector_unit_square.y +1 < NUMBER_SQUARE_HEIGHT){

            if (completed_square[vector_unit_square.x - 1][vector_unit_square.y -1]==0 
                && completed_square[vector_unit_square.x ][vector_unit_square.y -1]==0
                && completed_square[vector_unit_square.x][vector_unit_square.y +1]==0){

                    vector_square[0].setPosition(vector.x - SIZE_SQUARE , vector.y - SIZE_SQUARE);
                    vector_square[1].setPosition(vector.x, vector.y - SIZE_SQUARE);
                    vector_square[3].setPosition(vector.x, vector.y + SIZE_SQUARE);
                }
        }
        
    }
    else if (way == 2){
        if (vector_unit_square.x -1 >= 0 && vector_unit_square.x +1 < NUMBER_SQUARE_LENGTH && vector_unit_square.y -1 >=0){

            if (completed_square[vector_unit_square.x - 1][vector_unit_square.y]==0 
                && completed_square[vector_unit_square.x +1 ][vector_unit_square.y]==0
                && completed_square[vector_unit_square.x +1][vector_unit_square.y -1]==0){

                    vector_square[0].setPosition(vector.x + SIZE_SQUARE , vector.y - SIZE_SQUARE);
                    vector_square[1].setPosition(vector.x + SIZE_SQUARE, vector.y );
                    vector_square[3].setPosition(vector.x - SIZE_SQUARE, vector.y);
                }
        }
        
    }
    else{
        if (vector_unit_square.x +1 < NUMBER_SQUARE_LENGTH && vector_unit_square.y -1 >=0 && vector_unit_square.y +1 < NUMBER_SQUARE_HEIGHT){

            if (completed_square[vector_unit_square.x][vector_unit_square.y -1]==0 
                && completed_square[vector_unit_square.x ][vector_unit_square.y +1]==0
                && completed_square[vector_unit_square.x+1][vector_unit_square.y +1]==0){

                    vector_square[0].setPosition(vector.x + SIZE_SQUARE , vector.y + SIZE_SQUARE);
                    vector_square[1].setPosition(vector.x, vector.y + SIZE_SQUARE);
                    vector_square[3].setPosition(vector.x, vector.y - SIZE_SQUARE);
                }
        }
    }
    if (isCollision(completed_square)){
        state=State::stopped;
    }
    way=(way+1)%4;
}
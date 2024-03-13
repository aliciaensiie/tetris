#include "../headers/oBlock.hpp"
#include <iostream>

//PRIVATE
void OBlock::createShape(sf::Color color){
    for (int i=0; i<4; i++){
        sf::RectangleShape square(sf::Vector2f(SIZE_SQUARE, SIZE_SQUARE));
        square.setFillColor(color);
        square.setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE + (i/2)*SIZE_SQUARE ,  (i/2)*SIZE_SQUARE));
        vector_square.push_back(square);
    }
    vector_square[0].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE,  0));
    vector_square[1].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE  + SIZE_SQUARE,  0));
    vector_square[2].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE  + SIZE_SQUARE,  SIZE_SQUARE));
    vector_square[3].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE,  SIZE_SQUARE));  
}

//PUBLIC
OBlock::OBlock(): Shape(){
    sf::Color color=colorShape();
    createShape(color);
    
}

void OBlock::turn(std::vector<std::vector<int>> completed_square){
}
#include "../headers/oBlock.hpp"
#include <iostream>

//PRIVATE
std::vector<sf::RectangleShape> OBlock::createShape(std::vector<sf::RectangleShape> vector_shape, sf::Color color){
    for (int i=0; i<4; i++){
        sf::RectangleShape square(sf::Vector2f(SIZE_SQUARE, SIZE_SQUARE));
        square.setFillColor(color);
        square.setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE + (i/2)*SIZE_SQUARE ,  (i/2)*SIZE_SQUARE));
        vector_shape.push_back(square);
    }
    vector_shape[0].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE,  0));
    vector_shape[1].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE  + SIZE_SQUARE,  0));
    vector_shape[2].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE  + SIZE_SQUARE,  SIZE_SQUARE));
    vector_shape[3].setPosition(sf::Vector2f((NUMBER_SQUARE_LENGTH/2) * SIZE_SQUARE,  SIZE_SQUARE));
    return vector_shape;
     
}

//PUBLIC
OBlock::OBlock(): Shape(){
    sf::Color color=colorShape();
    vector_square = createShape(vector_square, color);
    
}

void OBlock::turn(std::vector<std::vector<int>> completed_square){
}
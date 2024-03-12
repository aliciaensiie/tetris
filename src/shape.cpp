#include "../headers/shape.hpp"
#include <random> 
#include <iostream>
#include <chrono>

//PRIVATE
std::default_random_engine createRandomEngine1(){
    unsigned long seed=static_cast<unsigned long> (std::time(nullptr));
    return std::default_random_engine(seed);
}

std::default_random_engine RandomEngine1=createRandomEngine1();

int Shape::random(int number) const{
    std::uniform_int_distribution<> distr(1, number);
    return distr(RandomEngine1);
}

sf::Color Shape::colorShape()const{
    int number=random(5);
    switch (number){
        case 1: 
            return sf::Color::Red;
        case 2:
            return sf::Color::Green;
        case 3:
            return sf::Color::Blue;
        case 4:
            return sf::Color::Cyan;
        case 5:
            return sf::Color::Magenta;
    }
    return sf::Color::Black;
}

bool Shape::isCollision(std::vector<std::vector<int>> completed_square) const{
    for (sf::RectangleShape rect : vector_square){
        if (completed_square[getPositionSquare(rect).x][getPositionSquare(rect).y+1] == 1){
            return true;
        }
    }
    return false;
}

bool Shape::isOnCompleteLine(sf::RectangleShape rect, std::vector<int> complete_line) const{
    for (int line : complete_line){
        if (getPositionSquare(rect).y==line){
            return true;
        }    
    }
    return false;
}


//PUBLIC
Shape::Shape(): vector_square(), way(0), state(State::in_movement){}

std::vector<sf::RectangleShape> Shape::getVectorSquare()const{
    return vector_square;
}

sf::Vector2f Shape::getPositionSquare(sf::RectangleShape rect) const{
    return sf::Vector2f(rect.getPosition().x/SIZE_SQUARE, rect.getPosition().y/SIZE_SQUARE);
}

State Shape::getState() const{
    return state;
}

void Shape::setState(State new_state){
    state= new_state;
}

void Shape::setColorTransparent(){
    for (sf::RectangleShape& element : vector_square){
        element.setFillColor(sf::Color::Transparent);
    }
}
void Shape::goDown(std::vector<std::vector<int>> completed_square){
    for(sf::RectangleShape& square : vector_square){
        square.setPosition(square.getPosition() + sf::Vector2f(0,SIZE_SQUARE));
    }
    if (isCollision(completed_square) ){
        state=State::pending;
    }
    for (sf::RectangleShape square : vector_square){
        if (square.getPosition().y<0 || square.getPosition().y > HEIGHT_TETRIS-2*SIZE_SQUARE){
            state=State::pending;
        }
    } 
}

void Shape::goRight(std::vector<std::vector<int>> completed_square){
    for(sf::RectangleShape& square : vector_square){
        square.setPosition(square.getPosition() + sf::Vector2f(SIZE_SQUARE,0));
    } 
    if (isCollision(completed_square)){
        state=State::stopped;
    }  
}


void Shape::goLeft(std::vector<std::vector<int>> completed_square){
    for(sf::RectangleShape& square : vector_square){
        square.setPosition(square.getPosition() - sf::Vector2f(SIZE_SQUARE,0));
    }
    if (isCollision(completed_square)){
        state=State::stopped;
    }  
}

void Shape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(sf::RectangleShape element: vector_square){
        target.draw(element, states);
    }
    
}
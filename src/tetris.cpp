#include "../headers/tetris.hpp"
#include "../headers/iBlock.hpp"
#include <iostream>
#include <random> 
#include <chrono>

//PRIVATE
std::default_random_engine createRandomEngine2(){
    unsigned long seed=static_cast<unsigned long> (std::time(nullptr));
    return std::default_random_engine(seed);
}

std::default_random_engine RandomEngine2=createRandomEngine2();

Type_Shape Tetris::whichTypeShape(){
    std::uniform_int_distribution<> distr(0, NUMBER_ELEMENT_TYPE_SHAPE-1);
    int number =distr(RandomEngine2);
    return static_cast<Type_Shape>(number);
}

void Tetris::addShape(){
    Type_Shape type=whichTypeShape();
    //std::cout << static_cast<int>(type) << std::endl;
    switch (type){
        case Type_Shape::I :
            IBlock new_iblock;
            iblock=new_iblock;
            break;
    }
}

void Tetris::addIBlockToCompletedSquare(IBlock iblock){
    for(sf::RectangleShape element: iblock.getVectorSquare() ){
        sf::Vector2f pos= iblock.getPositionSquare(element);
        completed_square[pos.x][pos.y] = 1;
        square_grill[pos.x][pos.y] = element;
    }
}
 

//PUBLIC

Tetris::Tetris():square_grill(NUMBER_SQUARE_LENGTH, std::vector<sf::RectangleShape>(NUMBER_SQUARE_HEIGHT)), completed_square(NUMBER_SQUARE_LENGTH, std::vector<int>(NUMBER_SQUARE_LENGTH, 0)){
    addShape();
    for (int i=0; i< NUMBER_SQUARE_LENGTH; i++){
        for (int j=0; j<NUMBER_SQUARE_HEIGHT; j++){
            square_grill[i][j].setPosition(sf::Vector2f(i*SIZE_SQUARE, j*SIZE_SQUARE));
            square_grill[i][j].setFillColor(sf::Color::Transparent);
        }
    }
}

std::vector<int> Tetris::completeLines(){
    std::vector<int> complete_line;
    for (int i=NUMBER_SQUARE_HEIGHT-1; i>=0 ; i--){
        bool completed=true;
        for (int j=0; j<NUMBER_SQUARE_LENGTH; j++){
            if (completed_square[j][i]==0){
                completed=false;
            }
        }
        if (completed == true){
            complete_line.push_back(i);
        }
    }
    return complete_line;
}

void Tetris::removeLines(std::vector<int> complete_line){
   for (int i=0; i< NUMBER_SQUARE_LENGTH ; i++){
        for (int line : complete_line){
            for (int j=line; j>0; j--){
                square_grill[i][j]=square_grill[i][j-1];
                completed_square[i][j]=completed_square[i][j-1];
                square_grill[i][j].setPosition(square_grill[i][j].getPosition() + sf::Vector2f(0, SIZE_SQUARE));
                
            }
            square_grill[i][0].setFillColor(sf::Color::Transparent);
            completed_square[i][0]=0;
        }
    }
}

void Tetris::changementLines(){
    std::vector<int> complete_line = completeLines();
    if (complete_line.size() != 0){
        removeLines(complete_line);
    }
}

void Tetris::goRight(){
    if (iblock.getState()== State::in_movement){
        iblock.goRight(completed_square);
        if (iblock.getState() == State::stopped){
            addIBlockToCompletedSquare(iblock);
            addShape();
        }
    }
}
void Tetris::goLeft(){
    if (iblock.getState()== State::in_movement){
        iblock.goLeft(completed_square);
        if (iblock.getState() == State::stopped){
            addIBlockToCompletedSquare(iblock);
            addShape();
        }
    } 
}

void Tetris::goDown(){
    if (iblock.getState() == State::in_movement){
        //std::cout << "ok" << std::endl;
        iblock.goDown(completed_square);
        /*for (sf::RectangleShape element : i_shape.back().getVectorSquare()){
            std::cout << "position x= " << element.getPosition().x << ", position y= " << element.getPosition().y << std::endl;
        }*/
        
        //std::cout << "ok" << std::endl;
        if (iblock.getState() == State::stopped){
            //std::cout << "ok" << std::endl;
            addIBlockToCompletedSquare(iblock);
            addShape();
        }
    }
}

void Tetris::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    iblock.draw(target, states);
    for (std::vector<sf::RectangleShape> column: square_grill){
        for (sf::RectangleShape rect : column){
            target.draw(rect, states);
        }
    }
}

bool Tetris::isPossibleGoRight(){
    for(sf::RectangleShape square : iblock.getVectorSquare()){
        //std::cout << "max = " << NUMBER_SQUARE_LENGTH << ", NB = " << shape.getPositionSquare(square).x << std::endl;
        if (iblock.getPositionSquare(square).x>= NUMBER_SQUARE_LENGTH-1){
            return false;
        }
        else if (completed_square[iblock.getPositionSquare(square).x +1][iblock.getPositionSquare(square).y] == 1){
            return false;
        }
    }
    return true;
}
    
bool Tetris::isPossibleGoLeft(){
    for(sf::RectangleShape square : iblock.getVectorSquare()){
        if (iblock.getPositionSquare(square).x<= 0){
            return false;
        }
        else if (completed_square[iblock.getPositionSquare(square).x -1][iblock.getPositionSquare(square).y] == 1){
            return false;
        }
    }
    return true;
}

void Tetris::turn(){
    if (iblock.getState()== State::in_movement){
        iblock.turn(completed_square);
        if (iblock.getState() == State::stopped){
            addIBlockToCompletedSquare(iblock);
            addShape();
        }
    }
}

bool Tetris::isPossibleGoDown(){
    for(sf::RectangleShape square : iblock.getVectorSquare()){
        if (iblock.getPositionSquare(square).y>= NUMBER_SQUARE_HEIGHT-1){
            return false;
        }
        else if (completed_square[iblock.getPositionSquare(square).x][iblock.getPositionSquare(square).y +1] == 1){
            return false;
        }
    }
    return true;
}
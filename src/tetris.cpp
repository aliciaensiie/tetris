#include "../headers/tetris.hpp"
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
    int middle_square = NUMBER_SQUARE_LENGTH /2;
    switch (type){
        case Type_Shape::I :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square][2] == 0 && completed_square[middle_square][3]==0){
                IBlock new_iblock;
                iblock=new_iblock;
                if (completed_square[middle_square][4]==1){
                    iblock.setState(State::stopped);
                }
            }  
            break; 
        } 
        case Type_Shape::O:{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square+1][0] == 0 && completed_square[middle_square+1][1]==0){
                OBlock new_oblock;
                oblock=new_oblock;
                if (completed_square[middle_square][2]==1 || completed_square[middle_square +1][2]==1){
                    oblock.setState(State::stopped);
                }
            }  
            break; 
        }
        case Type_Shape::L :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square][2] == 0 && completed_square[middle_square+1][2]==0){
                LBlock new_lblock;
                lblock=new_lblock;
                if (completed_square[middle_square][3]==1 || completed_square[middle_square +1][3]==1){
                    oblock.setState(State::stopped);
                }
            }  
            break; 
        }
        case Type_Shape::J :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square][2] == 0 && completed_square[middle_square-1][2]==0){
                JBlock new_jblock;
                jblock=new_jblock;
                if (completed_square[middle_square][3]==1 || completed_square[middle_square -1][3]==1){
                    jblock.setState(State::stopped);
                }
            }  
            break; 
        }
        case Type_Shape::T :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square-1][0] == 0 && completed_square[middle_square+1][0]==0){
                TBlock new_tblock;
                tblock=new_tblock;
                if (completed_square[middle_square][2]==1 || completed_square[middle_square -1][1]==1 || completed_square[middle_square +1][1]==1){
                    tblock.setState(State::stopped);
                }
            }  
            break; 
        }
        case Type_Shape::S :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square+1][0] == 0 && completed_square[middle_square-1][1]==0){
                SBlock new_sblock;
                sblock=new_sblock;
                if (completed_square[middle_square][2]==1 || completed_square[middle_square -1][2]==1 || completed_square[middle_square +1][1]==1){
                    sblock.setState(State::stopped);
                }
            }  
            break; 
        }
        case Type_Shape::Z :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square-1][0] == 0 && completed_square[middle_square+1][1]==0){
                ZBlock new_zblock;
                zblock=new_zblock;
                if (completed_square[middle_square][2]==1 || completed_square[middle_square +1][2]==1 || completed_square[middle_square -1][1]==1){
                    zblock.setState(State::stopped);
                }
            }  
            break; 
        }
    }

            
}

void Tetris::addBlockToCompletedSquare(Shape* shape){
    for(sf::RectangleShape element: shape->getVectorSquare() ){
        sf::Vector2f pos= shape->getPositionSquare(element);
        completed_square[pos.x][pos.y] = 1;
        square_grill[pos.x][pos.y] = element;
    }
}
 
//HERE
void Tetris::addFirstShapes(){
    Type_Shape type=whichTypeShape();
    
    if(type != Type_Shape::I){
        iblock.setState(State::stopped);
        iblock.setColorTransparent();
    }
    if(type != Type_Shape::O){
        oblock.setState(State::stopped);
        oblock.setColorTransparent();
    }
    if(type != Type_Shape::L){
        lblock.setState(State::stopped);
        lblock.setColorTransparent();
    }
    if(type != Type_Shape::J){
        jblock.setState(State::stopped);
        jblock.setColorTransparent();
    }
    if(type != Type_Shape::T){
        tblock.setState(State::stopped);
        tblock.setColorTransparent();
    }
    if(type != Type_Shape::S){
        sblock.setState(State::stopped);
        sblock.setColorTransparent();
    }
    if(type != Type_Shape::Z){
        zblock.setState(State::stopped);
        zblock.setColorTransparent();
    }
}

//PUBLIC

//HERE
Tetris::Tetris():iblock(), oblock(), lblock(), jblock(), tblock(), sblock(),zblock(), square_grill(NUMBER_SQUARE_LENGTH, std::vector<sf::RectangleShape>(NUMBER_SQUARE_HEIGHT)), completed_square(NUMBER_SQUARE_LENGTH, std::vector<int>(NUMBER_SQUARE_LENGTH, 0)){
    addFirstShapes();
    for (int i=0; i< NUMBER_SQUARE_LENGTH; i++){
        for (int j=0; j<NUMBER_SQUARE_HEIGHT; j++){
            square_grill[i][j].setPosition(sf::Vector2f(i*SIZE_SQUARE, j*SIZE_SQUARE));
            square_grill[i][j].setFillColor(sf::Color::Transparent);
        }
    }
}

Shape* Tetris::findShapeInMovement(){

    if (iblock.getState() != State::stopped){
        return static_cast<Shape*>(&iblock);
    }
    else if (oblock.getState() != State::stopped){
        return static_cast<Shape*>(&oblock);
    }
    else if (lblock.getState() != State::stopped){
        return static_cast<Shape*>(&lblock);
    }
    else if (jblock.getState() != State::stopped){
        return static_cast<Shape*>(&jblock);
    }
    else if (tblock.getState() != State::stopped){
        return static_cast<Shape*>(&tblock);
    }
    else if (sblock.getState() != State::stopped){
        return static_cast<Shape*>(&sblock);
    }
    else if (zblock.getState() != State::stopped){
        return static_cast<Shape*>(&zblock);
    }
    return nullptr;
}

std::vector<int> Tetris::completeLines(){
    std::vector<int> complete_line;
    for (int i=0; i< NUMBER_SQUARE_LENGTH ; i++){
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
            //std::cout << "i=" << i << " line=" << line << std::endl;
            for (int j=line; j>0; j--){
                square_grill[i][j].setFillColor(square_grill[i][j-1].getFillColor());
                completed_square[i][j]=completed_square[i][j-1];
                if (line == 18 && j > 13){
                    //std::cout << " i=" << i << " j=" << j << " coloralpha=" << square_grill[i][j].getFillColor().a << std::endl; 
                }
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
    Shape* shape= findShapeInMovement();
    shape->goRight(completed_square);
    if (shape->getState() == State::stopped){
            addBlockToCompletedSquare(shape);
            addShape();
    }
}


void Tetris::goLeft(){
    Shape* shape=findShapeInMovement();
    shape->goLeft(completed_square);
    if (shape->getState() == State::stopped){
        addBlockToCompletedSquare(shape);
        addShape();
    }
}

void Tetris::goDown(){
    Shape* shape=findShapeInMovement();
    shape->goDown(completed_square);
    if (shape->getState() == State::stopped){
        addBlockToCompletedSquare(shape);
        addShape();
    }
}

void Tetris::turn(){
    Shape* shape= findShapeInMovement();
    if (shape->getState() == State::in_movement){
        shape->turn(completed_square);
        if (shape->getState() == State::stopped){
            addBlockToCompletedSquare(shape);
            addShape();
        }
    }
}




bool Tetris::isPossibleGoRight(){
    Shape* shape = findShapeInMovement();
    if (shape == 0){
        return false;
    }
    for(sf::RectangleShape square : shape->getVectorSquare()){
        if (shape->getPositionSquare(square).x>= NUMBER_SQUARE_LENGTH-1){
            return false;
        }
        else if (completed_square[shape->getPositionSquare(square).x +1][shape->getPositionSquare(square).y] == 1){
            return false;
        } 
    }
    return true;  
}

  
bool Tetris::isPossibleGoLeft(){
    Shape* shape=findShapeInMovement();
    if (shape ==0){
        return false;
    }
    for(sf::RectangleShape square : shape->getVectorSquare()){
        if (shape->getPositionSquare(square).x<= 0){
            return false;
        }
        else if (completed_square[shape->getPositionSquare(square).x -1][shape->getPositionSquare(square).y] == 1){
            return false;
        }
    }
    return true;
}

bool Tetris::isPossibleGoDown(){
    Shape* shape= findShapeInMovement();
    if (shape->getState() == State::in_movement){
        for(sf::RectangleShape square : shape->getVectorSquare()){
            if (shape->getPositionSquare(square).y>= NUMBER_SQUARE_HEIGHT-1){
                return false;
            }
            else if (completed_square[shape->getPositionSquare(square).x][shape->getPositionSquare(square).y +1] == 1){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

bool Tetris::DoNeedWaiting(){
    if (iblock.getState()==State::pending || jblock.getState()==State::pending || lblock.getState()==State::pending || oblock.getState()==State::pending || sblock.getState()==State::pending || tblock.getState()==State::pending || zblock.getState()==State::pending){
        return true;
    }
    return false;
}

void Tetris::endPendingTime(){
    Shape* shape = findShapeInMovement();
    if (shape->getState() == State::pending){
        shape->setState(State::in_movement);
        if (!isPossibleGoDown()){
            shape->setState(State::stopped);
            addBlockToCompletedSquare(shape);
            addShape();
        }
    }
}

bool Tetris::endgame(){
    if (iblock.getState() == State::stopped && oblock.getState() == State::stopped && lblock.getState()== State::stopped && jblock.getState()== State::stopped && tblock.getState()==State::stopped  && sblock.getState()==State::stopped  && zblock.getState()==State::stopped){
        return true;
    }
    return false;
}

void Tetris::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    if (iblock.getState() != State::stopped){
        iblock.draw(target, states);
    }
    else if (oblock.getState() != State::stopped){
        oblock.draw(target, states);
    }
    if (lblock.getState() != State::stopped){
        lblock.draw(target, states);
    }
    if (jblock.getState() != State::stopped){
        jblock.draw(target, states);
    }
    if (tblock.getState() != State::stopped){
        tblock.draw(target, states);
    }
    if (sblock.getState() != State::stopped){
        sblock.draw(target, states);
    }
    if (zblock.getState() != State::stopped){
        zblock.draw(target, states);
    }
    
    for (std::vector<sf::RectangleShape> column: square_grill){
        for (sf::RectangleShape rect : column){
            target.draw(rect, states);
        }
    }
}
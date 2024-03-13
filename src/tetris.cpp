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

Type_Shape Tetris::randomTypeShape(){
    std::uniform_int_distribution<> distr(0, NUMBER_ELEMENT_TYPE_SHAPE-1);
    int number =distr(RandomEngine2);
    return static_cast<Type_Shape>(number);
}


void Tetris::addShape(){
    type_next_shape=randomTypeShape();
    int middle_square = NUMBER_SQUARE_LENGTH /2;
    switch (type_next_shape){
        case Type_Shape::I :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square][2] == 0 && completed_square[middle_square][3]==0){
                IBlock* new_iblock= new IBlock();
                nextshape=static_cast<Shape*>(new_iblock);
                if (completed_square[middle_square][4]==1){
                    nextshape->setState(State::stopped);
                }
            }  
            break; 
        } 
        case Type_Shape::O:{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square+1][0] == 0 && completed_square[middle_square+1][1]==0){
                OBlock* new_oblock = new OBlock();
                nextshape=static_cast<Shape*>(new_oblock);
                if (completed_square[middle_square][2]==1 || completed_square[middle_square +1][2]==1){
                    nextshape->setState(State::stopped);
                }
            }  
            break; 
        }
        case Type_Shape::L :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square][2] == 0 && completed_square[middle_square+1][2]==0){
                LBlock* new_lblock= new LBlock();
                nextshape=static_cast<Shape*>(new_lblock);
                if (completed_square[middle_square][3]==1 || completed_square[middle_square +1][3]==1){
                    nextshape->setState(State::stopped);
                }
            }  
            break; 
        }
        case Type_Shape::J :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square][2] == 0 && completed_square[middle_square-1][2]==0){
                JBlock* new_jblock = new JBlock();
                nextshape=static_cast<Shape*>(new_jblock);
                if (completed_square[middle_square][3]==1 || completed_square[middle_square -1][3]==1){
                    nextshape->setState(State::stopped);
                }
            }  
            break; 
        }
        case Type_Shape::T :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square-1][0] == 0 && completed_square[middle_square+1][0]==0){
                TBlock* new_tblock = new TBlock();
                nextshape=static_cast<Shape*>(new_tblock);
                if (completed_square[middle_square][2]==1 || completed_square[middle_square -1][1]==1 || completed_square[middle_square +1][1]==1){
                    nextshape->setState(State::stopped);
                }
            }  
            break; 
        }
        case Type_Shape::S :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square+1][0] == 0 && completed_square[middle_square-1][1]==0){
                SBlock* new_sblock = new SBlock();
                nextshape=static_cast<Shape*>(new_sblock);
                if (completed_square[middle_square][2]==1 || completed_square[middle_square -1][2]==1 || completed_square[middle_square +1][1]==1){
                    nextshape->setState(State::stopped);
                }
            }  
            break; 
        }
        case Type_Shape::Z :{
            if (completed_square[middle_square][0] == 0 && completed_square[middle_square][1] == 0 && completed_square[middle_square-1][0] == 0 && completed_square[middle_square+1][1]==0){
                ZBlock* new_zblock= new ZBlock();
                nextshape=static_cast<Shape*>(new_zblock);
                if (completed_square[middle_square][2]==1 || completed_square[middle_square +1][2]==1 || completed_square[middle_square -1][1]==1){
                    nextshape->setState(State::stopped);
                }
            }  
            break; 
        }
    }       
}

void Tetris::addTextures(){
    sf::Texture texture_I;
    texture_I.loadFromFile(std::string(PATH_RESSOURCES) + "/textures/i.png");
    vector_texture.push_back(texture_I);

    sf::Texture texture_O;
    texture_O.loadFromFile(std::string(PATH_RESSOURCES) + "/textures/o.png");
    vector_texture.push_back(texture_O);

    sf::Texture texture_L;
    texture_L.loadFromFile(std::string(PATH_RESSOURCES) + "/textures/l.png");
    vector_texture.push_back(texture_L);

    sf::Texture texture_J;
    texture_J.loadFromFile(std::string(PATH_RESSOURCES) + "/textures/j.png");
    vector_texture.push_back(texture_J);
    
    sf::Texture texture_T;
    texture_T.loadFromFile(std::string(PATH_RESSOURCES) + "/textures/t.png");
    vector_texture.push_back(texture_T);

    sf::Texture texture_S;
    texture_S.loadFromFile(std::string(PATH_RESSOURCES) + "/textures/s.png");
    vector_texture.push_back(texture_S);

    sf::Texture texture_Z;
    texture_Z.loadFromFile(std::string(PATH_RESSOURCES) + "/textures/z.png");
    vector_texture.push_back(texture_Z);
}

void Tetris::addBlockToCompletedSquare(Shape* shape){
    for(sf::RectangleShape element: shape->getVectorSquare() ){
        sf::Vector2f pos= shape->getPositionSquare(element);
        completed_square[pos.x][pos.y] = 1;
        square_grid[pos.x][pos.y] = element;
    }
}

//PUBLIC

//HERE
Tetris::Tetris():
shape(), nextshape(), 
square_grid(NUMBER_SQUARE_LENGTH, std::vector<sf::RectangleShape>(NUMBER_SQUARE_HEIGHT)), 
completed_square(NUMBER_SQUARE_LENGTH, std::vector<int>(NUMBER_SQUARE_LENGTH, 0)), 
type_next_shape(), vector_texture() {

    addShape();
    shape = nextshape;
    addShape();
    addTextures();
    for (int i=0; i< NUMBER_SQUARE_LENGTH; i++){
        for (int j=0; j<NUMBER_SQUARE_HEIGHT; j++){
            square_grid[i][j].setPosition(sf::Vector2f(i*SIZE_SQUARE, j*SIZE_SQUARE));
            square_grid[i][j].setFillColor(sf::Color::Transparent);
        }
    }
}

std::vector<int> Tetris::completeLines(){
    std::vector<int> complete_line;
    for (int i=0; i< NUMBER_SQUARE_HEIGHT ; i++){
        bool completed=true;
        for (int j=0; j<NUMBER_SQUARE_LENGTH; j++){
            if (completed_square[j][i]==0){
                completed=false;
                break;
            }
        }
        if (completed == true){
            complete_line.push_back(i);
        }
    }
    return complete_line;
}

void Tetris::removeLines(std::vector<int> complete_line){ //constructor
   for (int i=0; i< NUMBER_SQUARE_LENGTH ; i++){
        for (int line : complete_line){
            //std::cout << "i=" << i << " line=" << line << std::endl;
            for (int j=line; j>0; j--){
                square_grid[i][j].setFillColor(square_grid[i][j-1].getFillColor());
                completed_square[i][j]=completed_square[i][j-1];
            }
            square_grid[i][0].setFillColor(sf::Color::Transparent);
            completed_square[i][0]=0;
        }
    }
}

void Tetris::changeLines(){
    std::vector<int> complete_line = completeLines();
    if (complete_line.size() != 0){
        removeLines(complete_line);
    }
}


void Tetris::goRight(){
    if(isPossibleGoRight()){
        shape->goRight(completed_square);
    }
}


void Tetris::goLeft(){
    if (isPossibleGoLeft()){
         shape->goLeft(completed_square);
    }
}

void Tetris::goDown(){
    if (!isPossibleGoDown()){
            shape->setState(State::stopped);
            addBlockToCompletedSquare(shape);
            shape = nextshape;
            addShape();
        }
    if(isPossibleGoDown()){
        shape->goDown(completed_square);
    }
}

void Tetris::turn(){
    shape->turn(completed_square);
}




bool Tetris::isPossibleGoRight(){
    if (shape->getState() == State::stopped){
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
    if (shape->getState() == State::stopped){
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

bool Tetris::endgame(){
    if (shape->getState() == State::stopped){
        return true;
    }
    return false;
}

void Tetris::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    for (std::vector<sf::RectangleShape> column: square_grid){
        for (sf::RectangleShape rect : column){
            target.draw(rect, states);
        }
    }
    shape->draw(target, states);
    sf::Sprite sprite(vector_texture[static_cast<int>(type_next_shape)]);
    sprite.setPosition(SIZE_SQUARE, SIZE_SQUARE);
    target.draw(sprite, states);
}
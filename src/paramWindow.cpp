#include "../headers/paramWindow.hpp"
#include <iostream>



//PUBLIC

ParamWindow::ParamWindow():
font_instructions(), 
param_square(sf::Vector2f(LENGTH_TETRIS, HEIGHT_TETRIS)), 
instructions("", font_instructions ),
font_tetris(),
return_texture(),
return_sprite(),
return_text("PRESS ENTER", font_tetris ),
score_max(),
score_max_text("", font_instructions)
{
    font_instructions.loadFromFile(std::string(PATH_RESSOURCES) + "/fonts/typewrite.ttf");
    param_square.setFillColor(sf::Color(0, 0, 0));
    instructions.setString(R"(
        Tetris Game

    To go right :             Press the RIGHT ARROW

    To go left  :             Press the LEFT ARROW

    To go down quickly  :   Press the DOWN ARROW

    To turn the shape   :   Press the RIGHT SHIFT


    Every time the score changes, the movements will be quicker)");
    instructions.setPosition(SIZE_SQUARE, 3*SIZE_SQUARE);
    instructions.setCharacterSize(25);


    font_tetris.loadFromFile(std::string(PATH_RESSOURCES) + "/fonts/Tetris.ttf");

    return_texture.loadFromFile(std::string(PATH_RESSOURCES) + "/textures/return.jpg");

    return_sprite.setTexture(return_texture);
    return_sprite.setPosition(LENGTH_TETRIS - 4*SIZE_SQUARE, SIZE_SQUARE/3);
    return_sprite.setScale(sf::Vector2f(0.04, 0.04));
    
    return_text.setFillColor(sf::Color::White);
    return_text.setCharacterSize(15);
    return_text.setPosition(LENGTH_TETRIS - 3*SIZE_SQUARE , SIZE_SQUARE/2);
    toHaveScoreMax();
    score_max_text.setCharacterSize(25);
    score_max_text.setPosition(2*SIZE_SQUARE, HEIGHT_TETRIS - 2*SIZE_SQUARE);
    
}

void ParamWindow::toHaveScoreMax(){
//score from file
    const std::string score_file = std::string(PATH_RESSOURCES) + "/files/score.txt";
    std::ifstream score_file_reading(score_file);
    if (!score_file_reading.is_open()) {
        std::cerr << "Impossible to read the score file" << std::endl;
    }
    std::getline(score_file_reading, score_max);
    score_file_reading.close();

    score_max_text.setString("The maximam score is " + score_max);
    
}

void ParamWindow::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    target.draw(param_square, states);
    target.draw(return_text, states);
    target.draw(instructions, states);
    target.draw(return_sprite, states);
    target.draw(score_max_text, states);
    
}


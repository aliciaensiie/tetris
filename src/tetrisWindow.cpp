#include "../headers/tetrisWindow.hpp"

///PUBLIC 

TetrisWindow::TetrisWindow(): 
font(), 
text_param("PRESS ENTER", font),
parameter_texture(),
sprite_param()
{
    font.loadFromFile(std::string(PATH_RESSOURCES) + "/fonts/Tetris.ttf");

    text_param.setFillColor(sf::Color::Black);
    text_param.setCharacterSize(15);
    text_param.setPosition(LENGTH_TETRIS - 3*SIZE_SQUARE , SIZE_SQUARE/2);

    parameter_texture.loadFromFile(std::string(PATH_RESSOURCES) + "/textures/parameter.png");
    
    sprite_param.setTexture(parameter_texture);
    sprite_param.setScale(sf::Vector2f(0.2,0.2));
    sprite_param.setPosition(LENGTH_TETRIS - 3.8*SIZE_SQUARE, SIZE_SQUARE/3);

}

void TetrisWindow::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    target.draw(text_param, states);
    target.draw(sprite_param, states);
}

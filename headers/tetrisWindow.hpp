#ifndef TETRISWINDOW_H
#define TETRISWINDOW_H
#include "tetris.hpp"

class  TetrisWindow: public sf::Drawable{   
    public:
        sf::Font font;
        sf::Text text_param;

        sf::Texture parameter_texture;

        sf::Sprite sprite_param;

        TetrisWindow();
        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};

#endif //TETRISWINDOW_H
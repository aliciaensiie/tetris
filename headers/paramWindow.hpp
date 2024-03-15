#ifndef PARAMWINDOW_H
#define PARAMWINDOW_H
#include "tetris.hpp"

#include <fstream>

class  ParamWindow: public sf::Drawable{   
    public:
        sf::Font font_instructions;
        sf::RectangleShape param_square;
        sf::Text instructions;
        
        sf::Font font_tetris;
        sf::Texture return_texture;
        sf::Sprite return_sprite;
        sf::Text return_text;

        std::string score_max;
        sf::Text score_max_text;
        
        ParamWindow();
        void toHaveScoreMax();
        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};

#endif //PARAMWINDOW_H
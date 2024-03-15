#ifndef ENDWINDOW_H
#define ENDWINDOW_H
#include "tetris.hpp"
#include <fstream>

#define TIME_BLINK sf::seconds(0.4f)

class  EndWindow: public sf::Drawable{   
    public:
        mutable sf::Time time_blink;

        sf::Font font;
        sf::Text text_game_over;
        sf::Text text_play_again;

        sf::RectangleShape end_square;

        bool is_file_changed;

        EndWindow();
        void changeScoreFile(int score, std::string score_max_line);
        void reset();
        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};

#endif //ENDWINDOW_H
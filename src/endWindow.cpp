#include "../headers/endWindow.hpp"

#include <iostream>

///PUBLIC 
EndWindow::EndWindow(): 
time_blink(sf::Time::Zero),
font(), 
text_game_over("GAME OVER", font ),
text_play_again("Push ENTER to play again", font ),
end_square(sf::Vector2f(LENGTH_TETRIS, HEIGHT_TETRIS)), 
is_file_changed(false){

    font.loadFromFile(std::string(PATH_RESSOURCES) + "/fonts/Tetris.ttf");

    text_game_over.setFillColor(sf::Color::Black);
    text_game_over.setPosition(LENGTH_TETRIS/3, HEIGHT_TETRIS/4);
    text_game_over.setCharacterSize(50);

    text_play_again.setFillColor(sf::Color::Black);
    text_play_again.setPosition(LENGTH_TETRIS/5, HEIGHT_TETRIS/2.5);
    text_play_again.setCharacterSize(50);

    end_square.setFillColor(sf::Color(255, 255, 255, 230));


}

void EndWindow::changeScoreFile(int score, std::string score_max_line){
    int score_max = std::stoi(score_max_line);
    if (score_max<score){
        text_game_over.setString("NEW  RECORD");
        std::string score_line = std::to_string(score);
        const std::string score_file = std::string(PATH_RESSOURCES) + "/files/score.txt";
        std::ofstream file_writing(score_file);
        if (!file_writing.is_open()) {
            std::cerr << "Impossible to write in the score file" << std::endl;
        }
        file_writing << score_line << std::endl;
        file_writing.close();
        is_file_changed = true;
    }
}

void EndWindow::reset(){
    text_game_over.setString("GAME OVER");
    is_file_changed = false;
}

void EndWindow::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    target.draw(end_square, states);
    target.draw(text_game_over, states);

    if (time_blink> TIME_BLINK){
        target.draw(text_play_again, states);
        if (time_blink > 2.0f*TIME_BLINK){
            time_blink = sf::Time::Zero;
        }
    }
}
               

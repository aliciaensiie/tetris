#include "../headers/tetris.hpp"
#include "../headers/endWindow.hpp"
#include "../headers/tetrisWindow.hpp"
#include "../headers/paramWindow.hpp"
#include <iostream>

#define TIME_UPDATE_BLOCK sf::seconds(0.4f)
#define QUICK_TIME_UPDATE_BLOCK sf::seconds(0.1f)

    
Tetris reset(Tetris tetris, EndWindow* end_window, ParamWindow* param_window){
    Tetris tetris2;
    end_window->reset();
    param_window->toHaveScoreMax();
    return tetris2;
}

int main()
{
    //WINDOW
    sf::RenderWindow window(sf::VideoMode(LENGTH_TETRIS, HEIGHT_TETRIS), "Tetris!", sf::Style::Close);

    TetrisWindow tetris_window;
    ParamWindow param_window;
    EndWindow end_window;
    

    //clock
    sf::Clock game_clock;

    //TIME
    sf::Time accu = sf::Time::Zero, realDeltaTime = sf::Time::Zero;
    sf::Time time_to_move_block = sf::Time::Zero;
    sf::Time time_special_movement = sf::Time::Zero;

    //SPEED
    sf::Time speed = TIME_UPDATE_BLOCK;
    sf::Time quick_speed = QUICK_TIME_UPDATE_BLOCK;


    //element of the game
    Tetris tetris;

    //boolean
    bool press_left = false;
    bool press_right = false;
    bool press_down = false; 
    bool press_turn = false;
    bool press_enter = false;
    bool end_game = false;
    bool need_param = false;

    int previous_score = tetris.getScore();

    while (window.isOpen())
    {
        //TIME
        if(!need_param){
            realDeltaTime = game_clock.restart();
            accu += realDeltaTime;
            time_to_move_block += realDeltaTime;
            time_special_movement += realDeltaTime;
            end_window.time_blink += realDeltaTime;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }

            else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right)) {
                press_right = true;
            }
            else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left)) {
                press_left = true;
            }
            else if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::RShift)){
                press_turn = true;
            }
            else if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down)){
                press_down = true;
            }  
            else if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter)){
                press_enter = true;
            }  
        }

        //turn 
        if (time_special_movement> quick_speed && !end_game ){
            time_special_movement = sf::Time::Zero;
            if (press_turn){
                tetris.turn();
                press_turn = false;
            }
            if (press_right){
                tetris.goRight();
                press_right=false;
            }
            else if (press_left){
                tetris.goLeft();
                press_left=false;
            }
        }

        // go down quickly
        if (time_to_move_block > quick_speed && press_down && !end_game ){
            time_to_move_block = sf::Time::Zero;
            press_down = false;
            tetris.goDown();
        }

        //move
        if(time_to_move_block > speed && !end_game){
            time_to_move_block = sf::Time::Zero;
            tetris.goDown();
            
        }

        if (press_enter){
            press_enter = false;
            if( end_game){
                tetris=reset(tetris, &end_window, &param_window);
                end_game=false;
                game_clock.restart();
            }
            else{
                need_param = !need_param;
            }
        }

        //complete line
        tetris.changeLines();
        end_game= tetris.endgame();

        if (tetris.getScore() > previous_score && speed > sf::seconds(0.15f)){
            previous_score = tetris.getScore();
            speed -= sf::seconds(0.01f);
            quick_speed -= sf::seconds(0.01f);
        }

        
        window.clear(sf::Color::White);
        if (need_param == true){
            window.draw(param_window);
        }
        else{
            window.draw(tetris);
            window.draw(tetris_window);
            if (end_game){
                end_window.changeScoreFile(tetris.getScore(), param_window.score_max);
                window.draw(end_window);  
            }
        }
        window.display();
    }

    return 0;
}
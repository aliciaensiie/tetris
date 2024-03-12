#include "../headers/tetris.hpp"
#include <iostream>
#include <fstream>

#define TIME_UPDATE_BLOCK sf::seconds(0.4f)
#define QUICK_TIME_UPDATE_BLOCK sf::seconds(0.1f)
#define TIME_UPDATE_SPECIAL_MOVEMENT sf::seconds(0.1f)
#define TIME_TO_WAIT sf::seconds(0.1f)

int main()
{
    sf::RenderWindow window(sf::VideoMode(LENGTH_TETRIS, HEIGHT_TETRIS), "Tetris!", sf::Style::Close);

    //clock
    sf::Clock clock_to_move_block;
    sf::Clock clock_special_movement;

    //shape end
    sf::RectangleShape transparent(sf::Vector2f(window.getSize().x, window.getSize().y));
    transparent.setFillColor(sf::Color(255, 255, 255, 200));

    //element of the game
    Tetris tetris;

    //boolean
    bool press_left = false;
    bool press_right = false;
    bool press_down = false; 
    bool press_turn = false;
    bool end_game = false;
    bool do_need_waiting =false;

    while (window.isOpen())
    {
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
        }

        //turn 
        if ((clock_special_movement.getElapsedTime()> TIME_UPDATE_SPECIAL_MOVEMENT && end_game == false && do_need_waiting == false) ||(clock_to_move_block.getElapsedTime() > TIME_TO_WAIT && do_need_waiting==true)){
            
            if (press_turn == true){
                tetris.turn();
                press_turn = false;
            }
            if (press_right==true && tetris.isPossibleGoRight()==true){
                tetris.goRight();
                press_right=false;
            }
            else if (press_left == true && tetris.isPossibleGoLeft()==true){
                tetris.goLeft();
                press_left=false;
            }

            if (do_need_waiting == false){
                clock_special_movement.restart();
            }
            else {
                do_need_waiting =false;
                clock_to_move_block.restart();
                tetris.endPendingTime();
            }
        }

        // go down quickly
        if (clock_to_move_block.getElapsedTime() > QUICK_TIME_UPDATE_BLOCK && press_down == true && end_game == false && do_need_waiting ==false){
            clock_to_move_block.restart();
            press_down = false;
            if (tetris.isPossibleGoDown()){
                tetris.goDown();
                do_need_waiting=tetris.DoNeedWaiting();
            }
        }

        //move
        if(clock_to_move_block.getElapsedTime() > TIME_UPDATE_BLOCK && end_game == false && do_need_waiting == false){
            clock_to_move_block.restart();
            if (tetris.isPossibleGoDown()){
                tetris.goDown();
                do_need_waiting=tetris.DoNeedWaiting();
            }   
            
        }

        //complete line
        tetris.changementLines();
        end_game= tetris.endgame();


        window.clear(sf::Color::White);
        window.draw(tetris);
        if (end_game == true){
            window.draw(transparent);
        }
        
        window.display();
    }

    return 0;
}

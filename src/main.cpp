#include "../headers/tetris.hpp"
#include <iostream>
#include <fstream>

#define TIME_UPDATE_BLOCK sf::seconds(0.3f)

int main()
{
    sf::RenderWindow window(sf::VideoMode(LENGTH_TETRIS, HEIGHT_TETRIS), "Tetris!", sf::Style::Close);

    //clock
    sf::Clock clock_to_move_block;

    //element of the game
    Tetris tetris;

    //boolean
    bool press_left = false;
    bool press_right = false;
    bool press_down = false; 

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
            else if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down)){
                press_down = true;
            }
                
        }

        //move
        if(clock_to_move_block.getElapsedTime() > TIME_UPDATE_BLOCK ){
            clock_to_move_block.restart();

            if (press_down == true){
                tetris.turn();
                press_down = false;
            }

            if (press_right==true && tetris.isPossibleGoRight()==true){
                tetris.goRight();
                press_right=false;
            }
            else if (press_left == true && tetris.isPossibleGoLeft()==true){
                tetris.goLeft();
                press_left=false;
            }

            if (tetris.isPossibleGoDown()){
                tetris.goDown();
            }

            //complete line
            tetris.changementLines();
            
        }

        

        

        window.clear(sf::Color::White);
        window.draw(tetris);
        window.display();
    }

    return 0;
}

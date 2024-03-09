#ifndef FORM_H
#define FORM_H
#include "SFML/Graphics.hpp"

#define LENGTH_TETRIS 1000
#define HEIGHT_TETRIS 1000
#define SIZE_SQUARE 50
#define NUMBER_SQUARE_LENGTH LENGTH_TETRIS/SIZE_SQUARE
#define NUMBER_SQUARE_HEIGHT HEIGHT_TETRIS/SIZE_SQUARE

enum class State{in_movement, stopped};

class Shape : public sf::Drawable{
    protected: 
       std::vector<sf::RectangleShape> vector_square;
       int way;
       State state;

       int random(int number);
       sf::Color colorShape();
       virtual std::vector<sf::RectangleShape> createShape(std::vector<sf::RectangleShape> vector_shape, sf::Color color)=0;
       virtual void turn(std::vector<std::vector<int>> completed_square)=0;
       bool isCollision(std::vector<std::vector<int>> completed_square);
       bool isOnCompleteLine(sf::RectangleShape rect, std::vector<int> complete_line);

    public: 
        Shape();
        void goDown(std::vector<std::vector<int>> completed_square);
        void goRight(std::vector<std::vector<int>> completed_square);
        void goLeft(std::vector<std::vector<int>> completed_square);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        State getState();
        std::vector<sf::RectangleShape> getVectorSquare();
        sf::Vector2f getPositionSquare(sf::RectangleShape rect);
        

};



#endif //FORM_H
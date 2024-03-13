#ifndef FORM_H
#define FORM_H
#include "SFML/Graphics.hpp"

#define LENGTH_TETRIS 1000
#define HEIGHT_TETRIS 1000
#define SIZE_SQUARE 50
#define NUMBER_SQUARE_LENGTH LENGTH_TETRIS/SIZE_SQUARE
#define NUMBER_SQUARE_HEIGHT HEIGHT_TETRIS/SIZE_SQUARE

enum class State{in_movement, stopped, pending};
enum class Way{South, West, North, East};

class Shape : public sf::Drawable{
    protected: 
       std::vector<sf::RectangleShape> vector_square;
       Way way;
       State state;

       int random(int number) const;
       sf::Color colorShape() const;
       virtual void createShape(sf::Color color)=0;
       

       bool isCollision(std::vector<std::vector<int>> completed_square) const;
       bool isOnCompleteLine(sf::RectangleShape rect, std::vector<int> complete_line) const;

    public: 
        Shape();

        virtual void turn(std::vector<std::vector<int>> completed_square)=0;
        
        std::vector<sf::RectangleShape> getVectorSquare() const;
        sf::Vector2f getPositionSquare(sf::RectangleShape rect) const;
        State getState() const;
        void setState(State new_state);
        void setColorTransparent();

        void goDown(std::vector<std::vector<int>> completed_square);
        void goRight(std::vector<std::vector<int>> completed_square);
        void goLeft(std::vector<std::vector<int>> completed_square);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};



#endif //FORM_H
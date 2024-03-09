#ifndef TETRIS_H
#define TETRIS_H

#include "shape.hpp"
#include "iBlock.hpp"
#include <list>

#define NUMBER_ELEMENT_TYPE_SHAPE 1

enum class Type_Shape{I};

class Tetris : public sf::Drawable{
    private: 
        IBlock iblock;
        std::vector<std::vector<sf::RectangleShape>> square_grill;
        std::vector<std::vector<int>> completed_square;

        Type_Shape whichTypeShape();
        void addShape();
        void addIBlockToCompletedSquare(IBlock iblock);

    public: 
        Tetris();
        std::vector<int> completeLines();
        void removeLines(std::vector<int> complete_line);
        void changementLines();
        void goRight();
        void goLeft();
        void goDown();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        bool isPossibleGoRight();
        bool isPossibleGoLeft();
        void turn();
        bool isPossibleGoDown();


};



#endif //TETRIS_H
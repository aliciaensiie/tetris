#ifndef TETRIS_H
#define TETRIS_H

#include "shape.hpp"
#include "iBlock.hpp"
#include "oBlock.hpp"
#include "lBlock.hpp"
#include "jBlock.hpp"
#include "tBlock.hpp"
#include "sBlock.hpp"
#include "zBlock.hpp"
#include <list>

#define NUMBER_ELEMENT_TYPE_SHAPE 7

enum class Type_Shape{I, O, L, J, T, S, Z};

class Tetris : public sf::Drawable{
    private: 
        IBlock iblock;
        OBlock oblock;
        LBlock lblock;
        JBlock jblock;
        TBlock tblock;
        SBlock sblock;
        ZBlock zblock;
        std::vector<std::vector<sf::RectangleShape>> square_grill;
        std::vector<std::vector<int>> completed_square;

        Type_Shape whichTypeShape();
        void addShape();
        void addBlockToCompletedSquare(Shape* shape);
        void addFirstShapes();

    public: 
        Tetris(); 
        Shape* findShapeInMovement();

        std::vector<int> completeLines();
        void removeLines(std::vector<int> complete_line);
        void changementLines();

        void goRight();
        void goLeft();
        void goDown();
        void turn();

        bool isPossibleGoRight();
        bool isPossibleGoLeft();
        bool isPossibleGoDown();

        bool DoNeedWaiting();
        void endPendingTime();

        bool endgame();

        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};



#endif //TETRIS_H
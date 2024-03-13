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

#ifdef PATH_RESSOURCES
    
#else
    #define PATH_RESSOURCES "ressources"
#endif

#define NUMBER_ELEMENT_TYPE_SHAPE 7

enum class Type_Shape{I, O, L, J, T, S, Z};

class Tetris : public sf::Drawable{
    private: 
        Shape* shape;
        Shape* nextshape;
        std::vector<std::vector<sf::RectangleShape>> square_grid; 
        std::vector<std::vector<int>> completed_square;
        Type_Shape type_next_shape;
        std::vector<sf::Texture> vector_texture;

        Type_Shape randomTypeShape();
        void addShape();
        void addTextures();
        void addBlockToCompletedSquare(Shape* shape);

    public: 
        Tetris(); 

        std::vector<int> completeLines();
        void removeLines(std::vector<int> complete_line);
        void changeLines();

        void goRight();
        void goLeft();
        void goDown();
        void turn();

        bool isPossibleGoRight();
        bool isPossibleGoLeft();
        bool isPossibleGoDown();

        bool endgame();

        void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};



#endif //TETRIS_H
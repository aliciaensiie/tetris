#ifndef SBLOCK_H
#define SBLOCK_H
#include "shape.hpp"

class SBlock : public Shape{
    private: 
        std::vector<sf::RectangleShape> createShape(std::vector<sf::RectangleShape> vector_shape, sf::Color color) override;
        
        
    public:
        SBlock();
        void turn(std::vector<std::vector<int>> completed_square) override;
};

#endif //SBLOCK_H
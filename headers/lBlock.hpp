#ifndef LBLOCK_H
#define LBLOCK_H
#include "shape.hpp"

class LBlock : public Shape{
    private: 
        std::vector<sf::RectangleShape> createShape(std::vector<sf::RectangleShape> vector_shape, sf::Color color) override;
        
        
    public:
        LBlock();
        void turn(std::vector<std::vector<int>> completed_square) override;
};

#endif //LBLOCK_H
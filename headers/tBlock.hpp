#ifndef TBLOCK_H
#define TBLOCK_H
#include "shape.hpp"

class TBlock : public Shape{
    private: 
        std::vector<sf::RectangleShape> createShape(std::vector<sf::RectangleShape> vector_shape, sf::Color color) override;
        
        
    public:
        TBlock();
        void turn(std::vector<std::vector<int>> completed_square) override;
};

#endif //TBLOCK_H
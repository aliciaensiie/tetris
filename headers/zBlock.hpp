#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "shape.hpp"

class ZBlock : public Shape{
    private: 
        std::vector<sf::RectangleShape> createShape(std::vector<sf::RectangleShape> vector_shape, sf::Color color) override;
        
        
    public:
        ZBlock();
        void turn(std::vector<std::vector<int>> completed_square) override;
};

#endif //ZBLOCK_H
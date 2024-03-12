#ifndef OBLOCK_H
#define OBLOCK_H
#include "shape.hpp"

class OBlock : public Shape{
    private: 
        std::vector<sf::RectangleShape> createShape(std::vector<sf::RectangleShape> vector_shape, sf::Color color) override;
        
        
    public:
        OBlock();
        void turn(std::vector<std::vector<int>> completed_square) override;
};

#endif //OBLOCK_H
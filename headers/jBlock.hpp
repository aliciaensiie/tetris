#ifndef JBLOCK_H
#define JBLOCK_H
#include "shape.hpp"

class JBlock : public Shape{
    private: 
        std::vector<sf::RectangleShape> createShape(std::vector<sf::RectangleShape> vector_shape, sf::Color color) override;
        
        
    public:
        JBlock();
        void turn(std::vector<std::vector<int>> completed_square) override;
};

#endif //JBLOCK_H
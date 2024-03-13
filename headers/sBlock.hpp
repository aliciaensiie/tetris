#ifndef SBLOCK_H
#define SBLOCK_H
#include "shape.hpp"

class SBlock : public Shape{
    private: 
        void createShape(sf::Color color) override;
        
        
    public:
        SBlock();
        void turn(std::vector<std::vector<int>> completed_square) override;
};

#endif //SBLOCK_H
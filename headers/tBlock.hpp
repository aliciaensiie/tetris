#ifndef TBLOCK_H
#define TBLOCK_H
#include "shape.hpp"

class TBlock : public Shape{
    private: 
        void createShape(sf::Color color) override;
        
        
    public:
        TBlock();
        void turn(std::vector<std::vector<int>> completed_square) override;
};

#endif //TBLOCK_H
#ifndef LBLOCK_H
#define LBLOCK_H
#include "shape.hpp"

class LBlock : public Shape{
    private: 
        void createShape(sf::Color color) override;
        
        
    public:
        LBlock();
        void turn(std::vector<std::vector<int>> completed_square) override;
};

#endif //LBLOCK_H
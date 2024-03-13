#ifndef OBLOCK_H
#define OBLOCK_H
#include "shape.hpp"

class OBlock : public Shape{
    private: 
        void createShape(sf::Color color) override;
        
        
    public:
        OBlock();
        void turn(std::vector<std::vector<int>> completed_square) override;
};

#endif //OBLOCK_H
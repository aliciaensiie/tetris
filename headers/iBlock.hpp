#ifndef IBLOCK_H
#define IBLOCK_H
#include "shape.hpp"

class IBlock : public Shape{
    private: 
        void createShape(sf::Color color) override;
        
        
    public:
        IBlock();
        void turn(std::vector<std::vector<int>> completed_square) override;
};

#endif //IBLOCK_H
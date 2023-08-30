#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile
{
    public:

    protected:
        int m_PosX;
        int m_PosY;
        sf::Sprite* m_Sprite;
        unsigned int m_Health;
        bool m_IsSolid;
};

#endif // TILE_H

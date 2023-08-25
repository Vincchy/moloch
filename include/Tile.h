#ifndef TILE_H
#define TILE_H


class Tile
{
    public:


    private:
        int m_PosX;
        int m_PosY;
        sf::Sprite* m_Sprite;
        unsigned int m_Health;
        bool isSolid;
};

#endif // TILE_H

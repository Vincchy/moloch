#include "TileStone.h"
#include <iostream>

TileStone::TileStone()
{
    sf::Texture texture;
    try
    {
        if (!texture.loadFromFile("../res/textures/tile_stone.png"))
            throw 10;
    }
    catch (int e)
    {
        printf("Failed to load texture.");
    }

    m_Sprite = new sf::Sprite(texture);
    m_IsSolid = true;
    //ctor
}

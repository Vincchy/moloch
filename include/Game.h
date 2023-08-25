#ifndef GAME_H
#define GAME_H
#include "Entity.h"
#include "Tile.h"
// moloch

class Game
{
public:
    void Init(sf::Window& window);

private:
    Entity* m_Entities;
    Tile* m_Tiles;
};

#endif // GAME_H

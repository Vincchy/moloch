#ifndef GAME_H
#define GAME_H
#include "Entity.h"
#include "Tile.h"
#include "MapGenerator.h"
// moloch

class Game
{
public:
    void init();
    void update();
    void render();

private:

    MapGenerator m_mapGen;
    //Entity* m_entities;
    //Tile* m_tiles;
    sf::Window* m_window;
    sf::VideoMode* m_videoMode;
    float deltaTime;
};

#endif // GAME_H

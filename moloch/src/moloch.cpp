#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MapGenerator.h"
#include "Player.h"

#include <iostream>
#include <stdlib.h>

int main()
{
    // Map generation
    MapGenerator mapGen(150, 50, 50);
    mapGen.GenerateMap();
    mapGen.PrintMap();
    int** map = mapGen.GetMap();

    sf::RenderWindow window(sf::VideoMode(512, 512), "Game", sf::Style::None);

    Player player;
    window.setView(player.GetView());

    sf::Sprite** sprites;

    sprites = new sf::Sprite*[mapGen.GetWidth()];
    for (int i=0; i<mapGen.GetWidth(); i++)
        sprites[i] = new sf::Sprite[mapGen.GetHeight()];

    // Load textures
    sf::Texture wall;
    if (!wall.loadFromFile("res/textures/tile_stone.png"))
    {
        std::cout << "Failed to load stone tile texture.\n";
        return -1;
    }

    sf::Texture path;
    if (!path.loadFromFile("res/textures/tile_ground.png"))
    {
        std::cout << "Failed to load stone tile texture.\n";
        return -1;
    }

    // Game loop
    while (window.isOpen())
    {
        // Event polling
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == e.Closed)
            {
                window.close();
            }
        }

        // Camera movement
        player.ProcessInput();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
        {
            system("clear");
            mapGen.GenerateMap();
            mapGen.PrintMap();
            map = mapGen.GetMap();

            for (int x=0; x<mapGen.GetWidth(); x++)
            {
                for (int y=0; y<mapGen.GetHeight(); y++)
                {
                    if (map[x][y] == 1)
                    {
                        sprites[x][y].setTexture(wall);
                        sprites[x][y].setPosition(x*10, y*10);
                    }
                    else
                    {
                        sprites[x][y].setTexture(path);
                        sprites[x][y].setPosition(x*10, y*10);
                    }
                }
            }
        }
        window.setView(player.GetView());

        window.clear();

        // Drawing
        for (int x=0; x<mapGen.GetWidth(); x++)
        {
            for (int y=0; y<mapGen.GetHeight(); y++)
            {
                window.draw(sprites[x][y]);
            }
        }

        window.draw(player.GetSprite());
        window.display();
    }

    return 0;
}

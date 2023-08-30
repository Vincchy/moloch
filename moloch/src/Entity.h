#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>

class Entity
{
    public:
        sf::Sprite GetSprite();

    protected:
        float m_PosX;
        float m_PosY;
        // ?
        sf::Sprite m_Sprite;
};

#endif // ENTITY_H

#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity
{
    public:
        Player();
        const sf::View& GetView();
        void SetPosition(float xPos, float yPos);
        void Move(float xOffset, float yOffset);
        void ProcessInput();

    private:
        float m_MovementSpeed;
        float m_Zoom;
        sf::View m_View;
};

#endif // PLAYER_H

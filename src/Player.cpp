#include "Player.h"
#include <iostream>
#include <SFML/Graphics/Texture.hpp>

Player::Player()
{
    m_MovementSpeed = 0.1f;
    m_Zoom = 0.5f;

    // Create the texture and initialize the sprite
    sf::Texture txt;
    if (!txt.loadFromFile("res/textures/player.png"))
    {
        std::cout << "Failed to load player texture.\n";
    }

    m_Sprite.setTexture(txt);
    m_Sprite.setPosition(0.0f, 0.0f);

    // Initialize and center the view
    m_View.setCenter(0.0f, 0.0f);
    m_View.setSize(512.0f, 512.0f);
    m_View.zoom(m_Zoom);
}

void Player::SetPosition(float xPos, float yPos)
{
    m_PosX = xPos;
    m_PosY = yPos;
    m_View.setCenter(m_PosX, m_PosY);
}

void Player::Move(float xOffset, float yOffset)
{
    m_PosX += xOffset*m_MovementSpeed;
    m_PosY += yOffset*m_MovementSpeed;
    m_View.setCenter(m_PosX, m_PosY);
    m_Sprite.setPosition(m_PosX, m_PosY);
}

const sf::View& Player::GetView() { return m_View; }

void Player::ProcessInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        Move(0.00f, -1.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        Move(0.00f, 1.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        Move(-1.0f, -0.00f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        Move(1.0f, 0.00f);
}

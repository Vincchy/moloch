#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
    sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));
    player.setFillColor(sf::Color::Cyan);

    sf::RenderWindow window(sf::VideoMode(512, 512), "Game", sf::Style::None);

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == e.Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            player.move(0.00f, -0.01f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            player.move(0.00f, 0.01f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            player.move(-0.01f, -0.00f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            player.move(0.01f, 0.00f);

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}

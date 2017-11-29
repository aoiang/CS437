#include "MainMenu_Screen.hpp"
#include "Title_Animation.hpp"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

void MainMenu_Screen::draw(sf::RenderWindow &window)
{
    int fontSize = 50;
    sf::Font font;
    font.loadFromFile(REGULARFONT_FILEPATH);
    if(!font.loadFromFile(REGULARFONT_FILEPATH))
    {
       sf::CircleShape circle;
       circle.setRadius(20);
       window.draw(circle);

    }
    sf::Text title(GAME_TITLE, font, fontSize);
    sf::FloatRect titlebox;
    titlebox = title.getGlobalBounds();
    title.setOrigin(titlebox.width/2.0f, titlebox.height/2.0f);
    title.setPosition(sf::Vector2f(window.getSize().x/2,window.getSize().y/2));

    sf::Text menuItem_0(MAINMENUITEM_0, font, fontSize);
    sf::FloatRect item_0_box;
    item_0_box = title.getGlobalBounds();
    menuItem_0.setOrigin(item_0_box.width/2.0f,item_0_box.height/2.0f);
    menuItem_0.setPosition(sf::Vector2f(window.getSize().x/2,(window.getSize().y/2)+50));

    sf::Text menuItem_1(MAINMENUITEM_1, font, fontSize);
    sf::FloatRect item_1_box;
    item_1_box = title.getGlobalBounds();
    menuItem_1.setOrigin(item_1_box.width/2.0f,item_1_box.height/2.0f);
    menuItem_1.setPosition(sf::Vector2f(window.getSize().x/2,(window.getSize().y/2)+100));


    sf::Text menuItem_2(MAINMENUITEM_2, font, fontSize);
    sf::FloatRect item_2_box;
    item_2_box = title.getGlobalBounds();
    menuItem_2.setOrigin(item_2_box.width/2.0f,item_2_box.height/2.0f);
    menuItem_2.setPosition(sf::Vector2f(window.getSize().x/2,(window.getSize().y/2)+150));

    window.draw(menuItem_0);
    window.draw(menuItem_1);
    window.draw(menuItem_2);
    window.draw(title);

}

int MainMenu_Screen::run(sf::RenderWindow &window)
{
    sf:: Event Event;
    bool running = true;

    while(running)
    {
        while (window.pollEvent(Event))
        {
            if(Event.type == sf::Event::Closed)
            {
                    running = false;
                    return -1;
            }
            if(Event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    return 2;
            }

        }
        window.clear(sf::Color(40,140,240));
        draw(window);
        window.display();

    }
    return 1;

}
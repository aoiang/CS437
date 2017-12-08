#include "GameView.hpp"
#include "Screens.hpp"
#include <iostream>
#include <stdlib.h>
#include <Levels_Screen.hpp>
#include <Infinite_Screen.hpp>

/**runs the window: creates the window and all screens*/
int GameView::run(GameLogic logic) {
    logic.set_cur_level(1);
    sf::RenderWindow App(sf::VideoMode(default_window_height, default_window_width, 32), GAME_TITLE,  sf::Style::Close);
    Title_Animation screen_title;
    MainMenu_Screen screen_mainmenu;
    GameView_Screen screen_gameview;
    Levels_Screen screen_levelselect;
    Infinite_Screen screen_infinite;
    Transition_Screen screen_transition;

    std::vector<Screen_Abstract*> screens;
    int cur_screen = SCREEN_TITLE;
    
    screen_title.set_GameLogic(logic);
    screen_mainmenu.set_GameLogic(logic);
    screen_gameview.set_GameLogic(logic);
    screen_levelselect.set_GameLogic(logic);
    screen_infinite.set_GameLogic(logic);
    screen_transition.set_GameLogic(logic);
    screen_title.set_window(App);
    screen_mainmenu.set_window(App);
    screen_gameview.set_window(App);
    screen_levelselect.set_window(App);
    screen_infinite.set_window(App);
    screen_transition.set_window(App);
    
    screens.push_back(&screen_title);
    screens.push_back(&screen_mainmenu);
    screens.push_back(&screen_transition);
    screens.push_back(&screen_gameview);
    screens.push_back(&screen_levelselect);
    screens.push_back(&screen_infinite);

    while (cur_screen != EXIT_GAME) {cur_screen = screens[cur_screen]->run();}
}

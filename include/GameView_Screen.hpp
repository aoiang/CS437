#ifndef CLEAR_GAMEVIEW_SCREEN_HPP
#define CLEAR_GAMEVIEW_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "GameLogic.hpp"
#include "Screen_Abstract.hpp"

static char texture_filepaths[8][40] = {UP_TEXTURE,
                                        RIGHT_TEXTURE,
                                        DOWN_TEXTURE,
                                        LEFT_TEXTURE,
                                        ROTATING_0_TEXTURE,
                                        ROTATING_1_TEXTURE,
                                        ROTATING_2_TEXTURE,
                                        ROTATING_3_TEXTURE};

class GameView_Screen : public Screen_Abstract {
    private:
        sf::RenderWindow *App;
        static const int texture_count = 8;
        static sf::Texture texture[texture_count];
        sf::RectangleShape * block_shapes;
        sf::RectangleShape shadow_shape;
        sf::RectangleShape restriction_shape;
        sf::RectangleShape hint_shape;
        sf::RectangleShape * path_shapes;
        sf::RectangleShape * tab_shapes;
        sf::Text * hintButton;
        float ** animation_ms;
        char ** animation_dir;
        int default_window_width = 600;
        int default_window_height = 600;
        char dir = DEFAULT_DIR;
        bool clicked = false;
        bool running = true;
        int mouse_x_start;
        int mouse_y_start;
        int deadzone = 10;
        std::string levels[20] = {LEVEL_01, LEVEL_02, LEVEL_03, LEVEL_04, LEVEL_05, 
                                  LEVEL_06, LEVEL_07, LEVEL_08, LEVEL_09, LEVEL_10,
                                  LEVEL_11, LEVEL_12, LEVEL_13, LEVEL_14, LEVEL_15,
                                  LEVEL_16, LEVEL_17, LEVEL_18, LEVEL_19, LEVEL_20};
    public:
        static const int block_size = 50;
        int tab_size = block_size/5;
        GameView_Screen();
        void init();
        bool isOpen();
        static sf::RectangleShape make_block_shape(int block_id);
        sf::RectangleShape make_tab_shape();
        sf::RectangleShape make_alpha_rectangle_shape(int, int, int, int, int, int);
        static void load_texture(int);
        static void load_textures();
        void draw(int);
        void draw_shadows();
        void draw_hintbutton();
        bool isOver_hintbutton();
        void show_hint();
        void draw_path_highlighting();
        void draw_blocks(int);
        void draw_tab(int, int, int);
        void draw_tabs();
        void draw_selected_block();
        void draw_hint();
        int BoardToPixel(int board_axis_index, int board_axis_length, int screen_axis_length, bool y_axis);
        int BoardXToXPixel(int x);
        int BoardYToYPixel(int y);
        int PixelToBoard(int pixel_index, int board_axis_length, int screen_axis_length);
        int XPixelToBoardX(int x);
        int YPixelToBoardY(int y);
        int run();
        void check_mouse_input();
        void check_keyboard_input();
};

#endif //CLEAR_GAMEVIEW_HPP

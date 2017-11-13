//
// Created by Yiyang Zhao on 22/10/2017.
// Additional work by Ivan & Yosef
//


#include "GameLogic.h"


void GameLogic::set_GameBoard(GameBoard &board) {this->board = &board;}

/**@return x index of selected block*/
int GameLogic::get_selected_x() {return selected_x;}

/**@return y index of selected block*/
int GameLogic::get_selected_y() {return selected_y;}

/**
  Sets postion of selected block_shape
  @param x index of selected block
  @param y index of selected block
*/
void GameLogic::set_selected_position(int x, int y) {
    selected_x = x;
    selected_y = y;
}

//TODO why should the selected block ever be invalid? should just check validity when setting.
bool GameLogic::is_selected_location_valid() {return board->is_valid_location(selected_x, selected_y);}

bool GameLogic::block_exists(int x, int y) {return board->block_exists(x,y);}

bool GameLogic::selected_block_exists() {return block_exists(selected_x, selected_y);}

/**@return block type integer*/
Block * GameLogic::get_block(int x, int y) {return board->get_block(x, y);}

/**@return selected block*/
Block * GameLogic::get_selected_block() {return get_block(selected_x, selected_y);}

int GameLogic::get_board_width() {return board->get_board_width();}

int GameLogic::get_board_height() {return board->get_board_height();}

/**Checks if a direction relative to a block is clear or blocked.*/
bool GameLogic::path_blocked(int x, int y, char direction) {
    if (direction == 'u') {
        for (int y2 = y+1; y2<get_board_height(); y2++) {
            if (block_exists(x, y2)) {
                return true;
            }
        }
    } else if (direction == 'd') {
        for (int y2 = y-1; y2>=0; y2--) {
            if (block_exists(x, y2)) {
                return true;
            }
        }
    } else if (direction == 'l') {
        for (int x2 = x-1; x2>=0; x2--) {
            if (block_exists(x2, y)) {
                return true;
            }
        }
    } else if (direction == 'r') {
        for (int x2 = x+1; x2<get_board_width(); x2++) {
            if (block_exists(x2, y)) {
                return true;
            }
        }
    }
    return false;
}


/**Removes block*/
void GameLogic::remove_block(int x, int y) {
    std::cout << "Removed block at " << x << ", " << y << "\n";
    board->remove_block(x, y);
    set_selected_position(-1, -1);
}


bool GameLogic::can_move(int block_x, int block_y, char direction) {
    if (!block_exists(block_x, block_y)) {return true;}//TODO figure out what to do with this case
    Block * block = get_block(block_x, block_y);
    switch (block->get_id()) {
        case 10:
            return static_cast<Normal_Block*>(block)->type_allows_movement(direction) && !path_blocked(block_x, block_y, direction);
        case 20:
        case 21:
        case 22:
        case 23:
            return static_cast<Directional_Block*>(block)->type_allows_movement(direction) && !path_blocked(block_x, block_y, direction);
    }
}

/**Attempts to move a block*/
void GameLogic::try_move(int x, int y, char direction) {
    if (block_exists(x, y)) {
        if (can_move(x, y, direction)) {
            remove_block(x, y);
        }
    }
}

void GameLogic::try_move_selected(char direction) {try_move(selected_x, selected_y, direction);}


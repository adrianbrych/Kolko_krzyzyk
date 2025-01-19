#pragma once

#include <string.h>
#include <iostream>
#include <array>

const int NUMBER_OF_FILDES_ON_BOARD = 9;

class Position;

using std::cout; 
using std::endl;
using std::cin;
using std::string;
using Positions_arr = std::array<Position*, NUMBER_OF_FILDES_ON_BOARD>;


enum class POSITION_VALUE
{
    NONE,
    ROUND,
    CROSS,
};

enum class GAME_ENGINE_ERR_CODE
{
    GAME_ENGINE_OK,
    GAME_ENGINE_ERR_NOK,
    GAME_ENGINE_ERR_OCCUPIED_FILED,
};

class Position
{
    private:
        int x;
        int y;
        POSITION_VALUE value;

    public:
        Position(int x_pos, int y_pos, POSITION_VALUE value_pos): x{x_pos}, y{y_pos}, value{value_pos} {};
        string print_state(void);
        void set_value(POSITION_VALUE pos_value);
        POSITION_VALUE get_value(void);

        int get_x(void);
        int get_y(void);
};

class Player
{
    private:
        int id;
        int choose_x;
        int choose_y;
    
    public:
        Player(int id_pos, int choose_x_pos, int choose_y_pos): id{id_pos}, choose_x{choose_x_pos}, 
                                                                choose_y{choose_y_pos} {};
        void set_x(int x);
        void set_y(int y);

        int get_x(void);
        int get_y(void);
};


void print_board(Positions_arr board_squares);
GAME_ENGINE_ERR_CODE make_move(Player* player, Positions_arr squares, POSITION_VALUE which_player);
void check_cross_down_status_of_board(Positions_arr board_positions);
void check_cross_up_status_of_board(Positions_arr board_positions);
void check_col_status_of_board(Positions_arr board_positions);
void check_row_status_of_board(Positions_arr board_positions);
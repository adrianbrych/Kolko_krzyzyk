#include "Player_and_game_engine.h"


void Player::set_x(int x)
{
    choose_x = x;
}

int Player::get_x(void)
{
    return choose_x;
}

void Player::set_y(int y)
{
    choose_y = y;
}

int Player::get_y(void)
{
    return choose_y;
}

string Position::print_state(void)
{
    string state = " ";

    if (POSITION_VALUE::NONE == value)       state = "     ";
    else if (POSITION_VALUE::ROUND == value) state = "  O  ";
    else if (POSITION_VALUE::CROSS == value) state = "  X  ";
    else state = "EROR";

    return state;
}

POSITION_VALUE Position::get_value(void)
{
    return value;
}

int Position::get_x(void)
{
    return x;
}

int Position::get_y(void)
{
    return y;
}

void Position::set_value(POSITION_VALUE pos_value)
{
    value = pos_value;
}

void print_board(Positions_arr board_squares)
{
    cout << "     |     |     " << endl;
    cout << board_squares.at(0)->print_state() + "|" + board_squares.at(1)->print_state() + "|" + board_squares.at(2)->print_state() << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << board_squares.at(3)->print_state() + "|" + board_squares.at(4)->print_state() + "|" + board_squares.at(5)->print_state() << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << board_squares.at(6)->print_state() + "|" + board_squares.at(7)->print_state() + "|" + board_squares.at(8)->print_state() << endl;
    cout << "     |     |     " << endl;
}

GAME_ENGINE_ERR_CODE make_move(Player* player, Positions_arr squares, POSITION_VALUE which_player)
{
    int x = 0;
    int y = 0;
    GAME_ENGINE_ERR_CODE ret = GAME_ENGINE_ERR_CODE::GAME_ENGINE_OK;
    cout << "Choose position" << endl;
    cout << "Position x" << endl;
    cin >> x;
    cout << "Position y" << endl;
    cin >> y;
    player->set_x(x);
    player->set_y(y);

    for(auto pos: squares)
    {
        if (player->get_x() == pos->get_x() && player->get_y() == pos->get_y() &
            pos->get_value() != POSITION_VALUE::CROSS & pos->get_value() != POSITION_VALUE::ROUND)
        {
            pos->set_value(which_player);
        }
        else if (player->get_x() == pos->get_x() && player->get_y() == pos->get_y() &
            (pos->get_value() == POSITION_VALUE::CROSS || pos->get_value() == POSITION_VALUE::ROUND))
        {
            cout << "Occupied field, choose one again" << endl;
            ret = GAME_ENGINE_ERR_CODE::GAME_ENGINE_ERR_OCCUPIED_FILED;
        }
        else{}
    }
    return ret;
}

void check_row_status_of_board(Positions_arr board_positions)
{
    string round_state = "  O  ";
    string cross_state = "  X  ";
    int round_values = 0;
    int cross_values = 0;

    for (auto posibile_position : {0, 1, 2})
    {
        for(auto pos: board_positions)
        {
            if (pos->get_x() == posibile_position && pos->get_value() == POSITION_VALUE::ROUND)
            {
                round_values += 1;
            }

            if (pos->get_x() == posibile_position && pos->get_value() == POSITION_VALUE::CROSS)
            {
                cross_values += 1;
            }
        }

        if (round_values == 3)
        {
            cout << "Round won"<< endl;
            exit(0);
        }
        if (cross_values == 3)
        {
            cout << "Cross won"<< endl;
            exit(0);
        }
    }
}

void check_col_status_of_board(Positions_arr board_positions)
{

    string round_state = "  O  ";
    string cross_state = "  X  ";
    int round_values = 0;
    int cross_values = 0;

    for (auto posibile_position : {0, 1, 2})
    {
        for(auto pos : board_positions)
        {
            if (pos->get_y() == posibile_position && pos->get_value() == POSITION_VALUE::ROUND)
            {
                round_values += 1;
            }

            if (pos->get_y() == posibile_position && pos->get_value() == POSITION_VALUE::CROSS)
            {
                cross_values += 1;
            }
        }

        if (round_values == 3)
        {
            cout << "Round won"<< endl;
            exit(0);
        }
        if (cross_values == 3)
        {
            cout << "Cross won"<< endl;
            exit(0);
        }
    }
}

void check_cross_down_status_of_board(Positions_arr board_positions)
{

    string round_state = "  O  ";
    string cross_state = "  X  ";
    int round_values = 0;
    int cross_values = 0;

    for (auto posibile_position : {0, 1, 2})
    {
        for(auto pos : board_positions)
        {
            if (pos->get_x() == posibile_position && pos->get_y() == posibile_position 
             && pos->get_value() == POSITION_VALUE::ROUND)
            {
                round_values += 1;
            }

            if (pos->get_x() == posibile_position && pos->get_y() == posibile_position 
             && pos->get_value() == POSITION_VALUE::CROSS)
            {
                cross_values += 1;
            }
        }

        if (round_values == 3)
        {
            cout << "Round won"<< endl;
            exit(0);
        }
        if (cross_values == 3)
        {
            cout << "Cross won"<< endl;
            exit(0);
        }
    }
}

void check_cross_up_status_of_board(Positions_arr board_positions)
{

    string round_state = "  O  ";
    string cross_state = "  X  ";
    int round_values = 0;
    int cross_values = 0;

    for (auto posibile_position : {0, 1, 2})
    {
        for(auto pos : board_positions)
        {
            if (pos->get_x() == 0 + posibile_position && pos->get_y() == 2 - posibile_position 
             && pos->get_value() == POSITION_VALUE::ROUND)
            {
                round_values += 1;
            }

            if (pos->get_x() == 0 + posibile_position && pos->get_y() == 2 - posibile_position 
             && pos->get_value() == POSITION_VALUE::CROSS)
            {
                cross_values += 1;
            }
        }

        if (round_values == 3)
        {
            cout << "Round won"<< endl;
            exit(0);
        }
        if (cross_values == 3)
        {
            cout << "Cross won"<< endl;
            exit(0);
        }
    }
}

#include "Player_and_game_engine.h"
#include <array>

Position pos_0_0{0, 0, POSITION_VALUE::NONE};
Position pos_0_1{0, 1, POSITION_VALUE::NONE};
Position pos_0_2{0, 2, POSITION_VALUE::NONE};
Position pos_1_0{1, 0, POSITION_VALUE::NONE};
Position pos_1_1{1, 1, POSITION_VALUE::NONE};
Position pos_1_2{1, 2, POSITION_VALUE::NONE};
Position pos_2_0{2, 0, POSITION_VALUE::NONE};
Position pos_2_1{2, 1, POSITION_VALUE::NONE};
Position pos_2_2{2, 2, POSITION_VALUE::NONE};
Player player_one{1, 0, 0};
Player player_two{2, 0, 0};
Positions_arr positions = {&pos_0_0, &pos_0_1, &pos_0_2, &pos_1_0, &pos_1_1, &pos_1_2, &pos_2_0, &pos_2_1, &pos_2_2};


int main(void)
{
    POSITION_VALUE switching_player = POSITION_VALUE::CROSS;
    GAME_ENGINE_ERR_CODE ret = GAME_ENGINE_ERR_CODE::GAME_ENGINE_ERR_NOK;
    cout << "Lets start the game" << endl;

    while (1)
    {
        ret = GAME_ENGINE_ERR_CODE::GAME_ENGINE_ERR_NOK; 
        
        if (switching_player == POSITION_VALUE::CROSS)
        {
            while (ret != GAME_ENGINE_ERR_CODE::GAME_ENGINE_OK)
            {
                ret = make_move(&player_one, positions,POSITION_VALUE::CROSS);
            }
            switching_player = POSITION_VALUE::ROUND;
        }
        else
        {
            while (ret != GAME_ENGINE_ERR_CODE::GAME_ENGINE_OK)
            {
                ret = make_move(&player_two, positions, POSITION_VALUE::ROUND);
            }
            switching_player = POSITION_VALUE::CROSS;
        }

        print_board(positions);
        check_row_status_of_board(positions);
        check_col_status_of_board(positions);
        check_cross_down_status_of_board(positions);
        check_cross_up_status_of_board(positions);
    }

    return 0;
}
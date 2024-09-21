#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_play.h"



int main(){
    int num_rows = 5;
    int num_cols = 5;
    int amt_to_win = 3;
    char blank_char = '*';
    char** board;
    char* player_pieces;
    int player_turn;
    setup_game(num_rows, num_cols, blank_char, &board, &player_turn, &player_pieces);
    play_game(board, amt_to_win, num_rows, num_cols, blank_char, player_turn, player_pieces);
    clean_up(board, num_rows, num_cols, player_pieces);
}






#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_play.h"
#include "board.h"
#include "win.h"
#include "input_validation.h"

void setup_game(int num_rows, int num_cols, char blank_char, char*** out_board, int* out_starting_player_turn, char* *out_player_pieces){
    char** board = make_board(num_rows, num_cols, blank_char);
    int player_turn = get_player_turn();
    char* player_pieces = get_player_pieces();
    *out_board = board;
    *out_starting_player_turn = player_turn;
    *out_player_pieces = player_pieces;

}

int get_player_turn(){
    return 0;
}

char* get_player_pieces(){
    char* player_pieces = (char*)calloc(3, sizeof(char));
    strcpy(player_pieces, "XO");
    return player_pieces;
}

void cur_take_turn(char** board, int num_rows, int num_cols, char blank_char, char cur_player_piece, int amt_to_win){
    int row, col;
    get_valid_move(board, num_rows, num_cols, blank_char, &row, &col, amt_to_win);
    place_piece(cur_player_piece, board, row, col);
}

void get_valid_move(char** board, int num_rows, int num_cols, char blank_char, int* row, int *col, int amt_to_win){
    int num_args_read;
    do{
        printf("Enter a column between 0 and %d to play in: ", num_cols);
        num_args_read = scanf("%d", col);
    }while(!is_valid_move(num_args_read, board, num_rows, num_cols, blank_char, *row, *col, amt_to_win));

}

bool is_valid_move(int num_args_read, char** board, int num_rows, int num_cols, char blank_char, int row, int col, int amt_to_win){
    const int num_args_needed = amt_to_win;
    return isValidFormat(num_args_read, num_args_needed) && 
            move_is_on_board(num_cols, col) && board[row][col] == blank_char;
        
}

void announce_results(char** board, int amt_to_win, int rows, int cols, int cur_player_turn){
    if(win(board, amt_to_win, rows, cols)){
        if(cur_player_turn == 0){
            printf("Player 1 Won!\n"); 
        }else{
            printf("Player 2 Won!\n"); 
        }
    }else{
        printf("Tie game!\n");
    }
}
void change_turns(int* cur_player_turn){
    // if(turn == 0){
    //     return 1;
    // }else{
    //     return 0;
    // }
    *cur_player_turn = (*cur_player_turn + 1) % 2;
}



void play_game(char** board, int amt_to_win, int rows, int cols, char blank_char, int starting_player_turn, char* player_pieces){
    int cur_player_turn = starting_player_turn;
    while(!is_game_over(board, amt_to_win, rows, cols)){
        cur_take_turn(board, rows, cols, blank_char, player_pieces[cur_player_turn], amt_to_win);
        change_turns(&cur_player_turn);
    }
    announce_results(board, amt_to_win, rows, cols, cur_player_turn);

}

void clean_up(char** board, int rows, int cols, char* player_pieces){
    delete_board(board, rows, cols);
    free(player_pieces);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"

char** make_board(int num_rows, int num_cols, char blank_char){
    int i, j;
    char **board = (char**)calloc(num_rows, sizeof(char*));
    for(i = 0; i < num_rows; i++){
        board[i] = (char*)calloc(num_cols, sizeof(char));
        for(j = 0; j < num_cols; j++){
            board[i][j] = blank_char;
        }
    }
    return board;
}


void display_game_state(char **board, int rows, int cols){
    int i, j;
    
    for(i = rows - 1; i >= 0; i--){
        printf("%d", i);
        for(j = 0; j < cols; j++){
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
    printf(" ");
    for(i = 0; i < cols; i++){
        printf("%d ", i);
    }
    printf("\n");
    

}


void place_piece(char piece, char** board, int row, int col){
    board[row][col] = piece;
}

bool is_between(int value, int min_val, int max_val){
    return value >= min_val && value <= max_val;
}

bool move_is_on_board(int num_cols, int col){
    return is_between(col, 0, num_cols - 1);
}

void delete_board(char** board, int rows, int cols){
    for(int i = 0; i < rows; i++){
        free(board[i]);
    }
    free(board);
}

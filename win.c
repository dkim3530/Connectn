#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "win.h"
#define MIN(i, j) (((i) < (j)) ? (i) : (j))


bool is_game_over(char **board, int amt, int rows, int cols){
    return win(board, amt, rows, cols) || tie(board, amt, rows, cols);
}

bool win_horz(char **board, int amt_to_win, int rows, int cols){
    int i, j, val, count, next_val;

    if(amt_to_win > cols){
        return false;
    }
    for(i = 0; i < rows; i++){
        val = board[i][0];
        count = 1;
        for(j = 0; j < cols - 1; j++){
            next_val = board[i][j+1];
            if(next_val != '*'){
                if(val == next_val){
                    count += 1;
                }else{
                    count = 1;
                    val = next_val;
                }
            }else{
                count = 1;
                val = next_val;    
            }
            if(count == amt_to_win){
                return true;
            }
        }
    }

    return false;
}




bool win_vert(char **board, int amt_to_win, int rows, int cols){
    
    char *win_list[rows];
    int i, j, k = 0;
    if(amt_to_win > rows){
        return false;
    }   
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            win_list[k] = &board[i][j];
            k++;
        }
    }
        

    for(i = 0; i < cols; i++){
        int count = 1;
        char val = *win_list[i];
        if(val != '*'){
            for(j = 1; j < rows; j++){
                int x = i + j * cols;
                char next_val = *win_list[x];
                if(val == next_val){
                    count += 1;
                }else if(next_val == '*'){
                    break;
                }else{
                    count = 1;
                    val = next_val;
                }
            }
        }else{
            continue;
        }
        if(count == amt_to_win){
            return true;
        }
    }
    return false;
}


bool left_diagonal_win(char **board, int amt, int rows, int cols){
    int i, j;
    if(amt > MIN(rows, cols)){
        return false;
    }

    int count = 1;

    for(i = 0; i < cols - amt + 1; i++){
        int row = 0;
        char val = board[0][i];
        for(j = 1; j < MIN(cols - i, rows); j++){
            char next_val = board[row + j][i + j];
            if(val != '*'){
                if(next_val == val){
                    count += 1;
                }else{
                    count = 1;
                    val - next_val;
            
                }
            }else{
                val = next_val;
                count = 1;
            }
            if(count == amt){
                return true;
            }
        }
    }

    for(i = 1; i < rows - amt + 1; i++){
        int col = 0;
        char val = board[i][col];
        for(j = 1; j < MIN(rows - i, cols); j++){
            char next_val = board[i + j][col + j];
            if(val != '*'){
                if(next_val == val){
                    count += 1;
                }else{
                    count = 1;
                    val = next_val;
                }
            }else{
                val = next_val;
                count = 1;
            }
            if(count == amt){
                return true;
            }
        }
    }
    return false;
}


bool right_diagonal_win(char **board, int amt, int rows, int cols){
    int i, j;
    if(amt > MIN(rows, cols)){
        return false;
    }
    for(i = amt - 1; i < cols; i++){
        int count = 1;
        int row = 0;
        char val = board[0][i];
        for(j = 1; j < MIN(i + 1, rows); j++){
            char next_val = board[row + j][i - j];
            if(val != '*'){
                if(next_val == val){
                    count += 1;
                }else{
                    count = 1;
                    val - next_val;
                }
            }else{
                val = next_val;
                count = 1;
            }
            if(count == amt){
                return true;
            }
        }
    }
    for(i = 0; i < rows - amt + 1; i++){
        char col = cols - 1;
        char val = board[i][col];
        for(j = 1; MIN(rows-i, cols); j++){
            char next_val = board[i + j][col - j];
            int count = 1;
            if(val != '*'){
                if(next_val == val){
                    count += 1;
                }else{
                    count = 1;
                    val = next_val;
                }
            }else{
                val = next_val;
                count = 1;
            }
            if(count == amt){
                return true;
            }
        }
    }
    return false;

}

bool win_diagonally(char **board, int amt, int rows, int cols){
    return (left_diagonal_win(board, amt, rows, cols) || right_diagonal_win(board, amt, rows, cols));
}
bool win(char **board, int amt, int rows, int cols){
    return (win_horz(board, amt, rows, cols) || win_vert(board, amt, rows, cols) || win_diagonally(board, amt, rows, cols));
}
bool tie(char **board, int amt, int rows, int cols){
    int i, j;

    if (win(board, amt, rows, cols)){
        return false;
    }

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            if(board[i][j] == '*'){
                return false;
            }
        }
    }

    return true;
}
#ifndef WIN_H
    #define WIN_H
    #include <stdbool.h>    

    bool win(char **board, int amt, int rows, int cols);
    bool win_vert(char **board, int amt_to_win);
    bool win_horz(char **board, int amt_to_win);     
    bool left_diagonal_win(char **board, int amt);
    bool right_diagonal_win(char **board, int amt);    
    bool win_diagonally(char **board, int amt);
    bool tie(char **board, int amt);
    bool is_game_over(char **board, int amt, int rows, int cols);
    

#endif
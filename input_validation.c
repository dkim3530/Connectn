#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_validation.h"

bool isValidFormat(const int numArgsRead, const int numArgsNeed){
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    do{
        scanf("%c", &character);
        if(!isspace(character)){
            formatIsGood = false;
        }
    }while(character != '\n');
    return formatIsGood;
}










#ifndef PRINT
#define PRINT

#define BOLD_RED "\x1b[1;31m"
#define BOLD_GREEN "\x1b[1;32m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define PINK_TEXT "\033[35m"
#define LIGHT_BLUE_TEXT "\033[36m"
#define RESET_TEXT "\033[0m"
#define RED_BOX "\033[101m"
#define GREEN_BOX "\033[102m"
#define BLUE_BOX "\033[43m"



struct game_input 
{
    int r1 ;
    int r2 ;
    int c1 ; 
    int c2 ;
};

// struct game_input all_inputs[60] ;

struct game_input get_input() ;
void print_grid() ;
void print_scores () ;
void print_moves() ;
void main_menu() ;
void print_remaining_dots() ;


#endif
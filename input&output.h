#ifndef PRINT
#define PRINT

#include<time.h>

#define BOLD_RED "\x1b[1;31m"
#define BOLD_GREEN "\x1b[1;32m"
#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[1;34m"
#define PINK_TEXT "\033[1;35m"
#define LIGHT_BLUE_TEXT "\033[1;36m"
#define RESET_TEXT "\033[0m"
#define RED_BOX "\033[1;101m"
#define GREEN_BOX "\033[1;102m"
#define BLUE_BOX "\033[1;43m"
#define LIGHT_BLUE_BOX "\033[1;46m"
#define PINK_BOX "\033[1;45m"



struct game_input 
{
    int r1 ;
    int r2 ;
    int c1 ; 
    int c2 ;
};

extern int game_mode ;

struct game_input get_input() ;
struct game_input generate_random();
struct game_input comp_input();

void print_grid() ;
void print_scores () ;
void print_moves() ;
void main_menu() ;
void print_remaining_dots();
void print_all(clock_t start_time) ;
void print_turn_2_player();
void print_turn_1_player();
struct game_input handle_input_1_player();
void print_game_time(clock_t start_time);


#endif
#include <stdlib.h>
#include "v_do_check.h"
#include "players_turns.h"
#include "input&output.h"



struct game_input get_input(){
    struct game_input ret ;
    scanf( "%d %d %d %d" , &ret.r1 , &ret.r2 , &ret.c1 , &ret.c2 ) ;
    // all_inputs[p1.num_of_moves+p2.num_of_moves] = ret ;
    return ret ; 
}

void print_grid()
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            if (h_lines[i][j] == 1)
            {
                printf("+" BOLD_RED "---" RESET_TEXT);
            }
            else if (h_lines[i][j] == 2)
            {
                printf("+" BOLD_GREEN "---" RESET_TEXT);
            }
            else
            {
                printf("+   ");
            }
        }
        printf("+\n");
        if (i < 5)
        {
            for (int j = 0; j < n; ++j)
            {
                if (v_lines[j][i] == 1)
                {
                    printf(BOLD_RED "|" RESET_TEXT);
                }
                else if (v_lines[j][i] == 2)
                {
                    printf(BOLD_GREEN "|" RESET_TEXT);
                }
                else
                {
                    printf(" ");
                }
                if (boxes[6 * i + j] == 1)
                {
                    printf(RED_BOX "   " RESET_TEXT);
                }
                else if (boxes[6 * i + j] == 2)
                {
                    printf(GREEN_BOX "   " RESET_TEXT);
                }
                else
                {
                    printf("   ");
                }
            }
            printf("\n");
        }
        else
            printf("\n");
    }
}
void print_scores()
{
    printf(RED_TEXT "player one's score %d\n" RESET_TEXT GREEN_TEXT "player two's score %d\n" RESET_TEXT, p1.score, p2.score);
}
void print_moves()
{
    printf(RED_TEXT "player one's moves %d\n" RESET_TEXT GREEN_TEXT "player two's moves %d\n" RESET_TEXT, p1.num_of_moves, p2.num_of_moves);
}
void print_remaining_dots(){
    printf( PINK_TEXT"remaining dots = %d\n"RESET_TEXT , (all_dots-tkn_dots) ) ;
}
void main_menu(){
    printf(PINK_TEXT"hello in dots and boxes !\n"RESET_TEXT YELLOW_TEXT "1_one player game" RESET_TEXT BLUE_TEXT  "\n2_two player game\n" RESET_TEXT ) ;
    int n ; scanf( "%d" , &n ) ;
    if ( n == 1 ){
        one_player_game() ;
    }
    else if ( n == 2 ){
        two_player_game() ;
    }
    
}

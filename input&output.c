#include <stdlib.h>
#include "v_do_check.h"
#include "players_turns.h"
#include "input&output.h"
#include"options.h"
#include"save.h"
#include"top_10.h"

int game_mode ;

struct game_input get_input()
{
    struct game_input ret;
    if (scanf("%d", &ret.r1) < 1 )
    {
        printf("enter only integers\n");
        while (getchar() != '\n');
        printf("try again\n");
        return get_input();
    }
    else{
    if (ret.r1 > 0)
    {
        if ( scanf("%1d%1d%1d", &ret.r2, &ret.c1, &ret.c2) < 1 )
        {
            printf("enter only integers\n");
            while (getchar() != '\n');
            printf("try again\n");
            return get_input();
        }
    }
    return ret;
    }
}

// struct game_input generate_random(){
//     struct game_input ret ;
//     ret.r1 = rand() % 6 + 1;  // Generates a number between 1 and 6
//     ret.r2 = rand() % 6 + 1;
//     ret.c1 = rand() % 6 + 1;
//     ret.c2 = rand() % 6 + 1;
// return ret ;
// }

struct game_input comp_input(){
    struct game_input ret ;
    int flag = 0 ; 
    for( int i = 0 ; i < n ; ++i ){
        for ( int j = 0 ; j < n-1 ; ++j ){
            if ( h_lines[i][j] == 0 ){
                ret.r1 = i+1 ; ret.r2 = i+1 ;
                ret.c1 = j+1 ; ret.c2 = j+2 ;
                flag = 1 ;
                return ret ;
            }
        }
    }
    if ( !flag ){
    for( int i = 0 ; i < n ; ++i ){
        for ( int j = 0 ; j < n-1 ; ++j ){
            if ( v_lines[i][j] == 0 ){
                ret.r1 = j+1 ; ret.r2 = j+2 ;
                ret.c1 = i+1 ; ret.c2 = i+1 ;
                return ret  ; 
            }
        }
    }
}
return ret ;
}

void print_grid()
{
    for ( int i = 1 ; i <= n ; ++i ){
        printf( "        %d " , i ) ;
    }
    printf("\n\n\n\n") ;
    for (int i = 0 ; i < n ; ++i )
    {
        printf("%d       " , i+1 ) ;
        for (int j = 0; j < n - 1; ++j)
        {
            if (h_lines[i][j] == 1)
            {
                printf("+" PINK_TEXT "---------" RESET_TEXT);
            }
            else if (h_lines[i][j] == 2)
            {
                printf("+" LIGHT_BLUE_TEXT "---------" RESET_TEXT);
            }
            else
            {
                printf("+         ");
            }
        }
        printf("+\n");
        if (i < (n-1))
        {
            
            for ( int k = 0 ; k < 3 ; ++k ){
            printf("        ") ;
            for (int j = 0; j < n ; ++j)
            {
                if (v_lines[j][i] == 1)
                {
                    printf(PINK_TEXT "|" RESET_TEXT);
                }
                else if (v_lines[j][i] == 2)
                {
                    printf(LIGHT_BLUE_TEXT "|" RESET_TEXT);
                }
                else
                {
                    printf(" ");
                }
                if ( j < (n-1) ){
                if (boxes[(n-1) * i + j] == 1)
                {
                    printf(PINK_BOX "         " RESET_TEXT);
                }
                else if (boxes[(n-1) * i + j] == 2)
                {
                    printf(LIGHT_BLUE_BOX "         " RESET_TEXT);
                }
                else
                {
                    printf("         ");
                }
                }

            }
            printf("\n");
            }
        }
        else
            printf("\n");
    }
}
void print_scores()
{
    printf(PINK_TEXT "player one's score %d\t\t" RESET_TEXT LIGHT_BLUE_TEXT "player two's score %d\n" RESET_TEXT, p1.score, p2.score);
}
void print_moves()
{
    printf(PINK_TEXT "player one's moves %d\t\t" RESET_TEXT LIGHT_BLUE_TEXT "player two's moves %d\n" RESET_TEXT, p1.num_of_moves, p2.num_of_moves);
}
void print_remaining_dots(){
    printf( YELLOW_TEXT"remaining dots = %d\n"RESET_TEXT , (n*n-tkn_dots) ) ;
}
void print_game_time(clock_t start_time) {
    clock_t current_time = clock();
    int elapsed_time = ( current_time - start_time ) / CLOCKS_PER_SEC ;
    printf( BLUE_TEXT "TIME PASSED %d%d:%d%d\n" RESET_TEXT , (elapsed_time/60)/10 , (elapsed_time/60)%10 , (elapsed_time%60)/10 , (elapsed_time%60)%10 );
    
}
void print_all( clock_t start_time ){
        print_grid();
        print_scores();
        print_moves();
        print_remaining_dots();
        print_game_time(start_time) ;
}
void print_turn_2_player(){
    if ( turn == 0 ){
    printf(GREEN_TEXT"player one's turn\n" RESET_TEXT) ;
    }
    else if ( turn == 1 ){
    printf(GREEN_TEXT"player two's turn\n"RESET_TEXT) ;
    }
}
void print_turn_1_player(){
    if ( turn == 0 ){
    printf(GREEN_TEXT"your turn\n"RESET_TEXT) ;
    }
    else if ( turn == 1 ){
    printf(GREEN_TEXT"computer's turn\n"RESET_TEXT) ;
    }
}
struct game_input handle_input_1_player(){
    struct game_input my_inp ; 

    if ( turn == 0 ){
    my_inp = get_input() ;
    }
    else if ( turn == 1 ){
    computer_moves++ ;
    all_inputs[p1.num_of_moves+p2.num_of_moves].compu_move_this_point = computer_moves ;
    my_inp = comp_input()  ;
    }
    return my_inp ;
}

void main_menu(){
    printf(PINK_TEXT"hello in dots and boxes !\n"RESET_TEXT 
    YELLOW_TEXT "1 one player game\n" RESET_TEXT
    BLUE_TEXT  "2 two player game\n" RESET_TEXT
    RED_TEXT "3 load game\n" RESET_TEXT
    GREEN_TEXT"4 show champions list\n"RESET_TEXT) ;

    if ( scanf( "%d" , &game_mode ) < 0 ){
        printf("you can only enter 1 2 3 or 4\n");
        while (getchar() != '\n');
        printf("try again\n");
        main_menu() ;
    }
    else{
    if ( game_mode == 1 || game_mode == 2 ){
        printf("enter the mode\n1 begineer\n2 expert\n");
        int size ;
        while( scanf( "%d" , &size ) < 0 ){
        printf("you can only enter 1 or 2\n");
        while (getchar() != '\n');
        printf("try again\n");
        }
        if ( size == 1 )
            n = 3 ;
        else 
            n = 6 ; 
    }
    if ( game_mode == 1 ){
        one_player_game() ;
    }
    else if ( game_mode == 2 ){
        two_player_game() ;
    }
    else if ( game_mode == 3 ){
        load_game();
    }
    else if ( game_mode == 4 ){
        showing_champion();
    }
    
    }
    
}


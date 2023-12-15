#include "players_turns.h" 
#include "v_do_check.h"
#include "input&output.h"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define RESET_TEXT "\033[0m"


int turn = 0 ;
struct player p1 , p2 ;

// struct game_input generate_random(){
//     struct game_input ret ; 
//     ret.r1 = rand() % 6 + 1;  // Generates a number between 1 and 6
//     ret.r2 = rand() % 6 + 1;
//     ret.c1 = rand() % 6 + 1;
//     ret.c2 = rand() % 6 + 1;
// return ret ;
// }

struct game_input generate_random(){
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

void two_player_game(){
    p1.score = 0 ; p1.num_of_moves = 0 ;
    p2.score = 0 ; p2.num_of_moves = 0 ;

    while( all_dots - tkn_dots ){
    if ( turn == 0 ){
    printf(YELLOW_TEXT"player one's turn\n" RESET_TEXT) ;
    }
    else if ( turn == 1 ){
    printf(YELLOW_TEXT"player two's turn\n"RESET_TEXT) ;
    }
    struct game_input my_inp ;
    my_inp = get_input() ;
    turn = v_do_check_( my_inp.r1 , my_inp.r2 , my_inp.c1 , my_inp.c2 , turn );
    print_grid();
    print_scores();
    print_moves();
    print_remaining_dots();
    
    }

}   

void one_player_game(){
    p1.score = 0 ; p1.num_of_moves = 0 ;
    p2.score = 0 ; p2.num_of_moves = 0 ;
    while( all_dots - tkn_dots ){
    struct game_input my_inp ;
    if ( turn == 0 ){
    printf(YELLOW_TEXT"your turn\n"RESET_TEXT) ;
    my_inp = get_input() ;
    }
    else if ( turn == 1 ){
    printf(YELLOW_TEXT"computer's turn\n"RESET_TEXT) ;
    my_inp = generate_random()  ;
    }
    print_grid();
    print_scores();
    print_moves();
    print_remaining_dots();
    turn = v_do_check_( my_inp.r1 , my_inp.r2 , my_inp.c1 , my_inp.c2 , turn );
    }
}
void update_scores( int score , int turn_  ){
    if ( !turn_ ){
        p1.score += score ;
    }
    else
        p2.score += score ;
}
void update_moves( int turn_ ){
    if ( !turn_ )
        p1.num_of_moves++;
    else
        p2.num_of_moves++;
}
#include "players_turns.h" 
#include "v_do_check.h"
#include "input&output.h"
#include "options.h"
#include "top_10.h"
int turn = 0 ;
struct player p1 , p2 ;


void two_player_game(){

    print_grid();
    clock_t start_time = clock();
    while( n*n - tkn_dots ){
    
    print_turn_2_player() ;

    struct game_input my_inp ;
    my_inp = get_input() ;

    if( my_inp.r1 >= 0 )
    {
    all_inputs[p1.num_of_moves+p2.num_of_moves].turn = turn ; // tracking turn 
    if(v_do_check_( my_inp.r1 , my_inp.r2 , my_inp.c1 , my_inp.c2 ) == -1 ){
        continue;
    }
    }
    else
    {
        turn = options_window();
        if ( turn == -1 )
        break;
    }

    print_all(start_time) ;

    }
    if(tkn_dots==n*n)
    top_10_calling_2_players();
}   

void one_player_game(){

    clock_t start_time = clock();
    while( n*n - tkn_dots ){

    print_turn_1_player();
    struct game_input my_inp = handle_input_1_player() ;

    if ( my_inp.r1 >= 0 ){

    if(v_do_check_( my_inp.r1 , my_inp.r2 , my_inp.c1 , my_inp.c2  ) == -1 )
    continue;

    if( turn == 0 ){
        computer_moves = 0 ; // tracking computer moves for undo and redo 
        all_inputs[p1.num_of_moves+p2.num_of_moves].compu_move_this_point = computer_moves ; 
    }
    all_inputs[p1.num_of_moves+p2.num_of_moves].turn = turn ; // tracking turn 

    }
    else{
        turn = options_window();
        if ( turn == -1 )
        break;
    }
    print_all(start_time);

    }

    if(tkn_dots==n*n)
    top_10_calling_1_player();
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


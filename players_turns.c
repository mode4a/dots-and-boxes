#include "players_turns.h" 
#include "v_do_check.h"
#include "input&output.h"
#include "options.h"

int turn = 0 ;
struct player p1 , p2 ;




void two_player_game(){
    // p1.score = 0 ; p1.num_of_moves = 0 ;
    // p2.score = 0 ; p2.num_of_moves = 0 ;

    while( all_dots - tkn_dots ){
    if ( turn == 0 ){
    printf(YELLOW_TEXT"player one's turn\n" RESET_TEXT) ;
    }
    else if ( turn == 1 ){
    printf(YELLOW_TEXT"player two's turn\n"RESET_TEXT) ;
    }
    struct game_input my_inp ;
    my_inp = get_input() ;
    if( my_inp.r1 >= 0 ){
    all_inputs[p1.num_of_moves+p2.num_of_moves].turn = turn ; // tracking turn
    turn = v_do_check_( my_inp.r1 , my_inp.r2 , my_inp.c1 , my_inp.c2 , turn ); 
    print_grid();
    print_scores();
    print_moves();
    print_remaining_dots();
    }
    else{
        turn = options_window();
        if ( turn == -1 )
        break;
        print_grid();
        print_scores();
        print_moves();
        print_remaining_dots();
    }
    }

}   

void one_player_game(){
    // p1.score = 0 ; p1.num_of_moves = 0 ;
    // p2.score = 0 ; p2.num_of_moves = 0 ;
    while( all_dots - tkn_dots ){
    struct game_input my_inp ;
    if ( turn == 0 ){
    printf(YELLOW_TEXT"your turn\n"RESET_TEXT) ;
    my_inp = get_input() ;
    }
    else if ( turn == 1 ){
    computer_moves++ ;
    all_inputs[p1.num_of_moves+p2.num_of_moves].compu_move_this_point = computer_moves ;
    printf(YELLOW_TEXT"computer's turn\n"RESET_TEXT) ;
    my_inp = generate_random()  ;
    }
    if ( my_inp.r1 >= 0 ){
    if( turn == 0 ){
        computer_moves = 0 ; 
        all_inputs[p1.num_of_moves+p2.num_of_moves].compu_move_this_point = computer_moves ;
    }
    all_inputs[p1.num_of_moves+p2.num_of_moves].turn = turn ;
    turn = v_do_check_( my_inp.r1 , my_inp.r2 , my_inp.c1 , my_inp.c2 , turn );
    print_grid();
    print_scores();
    print_moves();
    print_remaining_dots();
    }
    else{
        turn = options_window();
        if ( turn == -1 )
        break;
        print_grid();
        print_scores();
        print_moves();
        print_remaining_dots();
    }
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


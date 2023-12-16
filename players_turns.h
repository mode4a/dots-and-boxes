#ifndef PLAYER_TU
#define PLAYER_TU

#include<stdlib.h>


extern int turn ;

struct player{
    char name[50] ;  
    int score ;   
    int num_of_moves ;
};

extern struct player p1 , p2 ;


void two_player_game();
void one_player_game();
void update_scores( int score , int turn_ ) ;
void update_moves( int turn_ ) ;




#endif
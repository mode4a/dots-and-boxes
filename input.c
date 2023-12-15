#include "input.h" 

struct game_input get_input(){
    struct game_input ret ;
    scanf( "%d %d %d %d" , &ret.r1 , &ret.r2 , &ret.c1 , &ret.c2 ) ;
    return ret ; 
}
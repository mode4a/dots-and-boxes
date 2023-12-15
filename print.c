#include<stdlib.h>
#include"v_do_check.h"
#include"players_turns.h"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define RESET_TEXT "\033[0m"

void print_grid(){

    for( int i = 0 ; i < n ; ++i ){
        for ( int j = 0 ; j < n-1 ; ++j ){
            if( h_lines[i][j] == 1 ){
                printf( "+"RED_TEXT"---"RESET_TEXT) ;
            }
            else if ( h_lines[i][j] == 2 ){
                printf( "+"GREEN_TEXT"---"RESET_TEXT);
            }
            else{
                printf("+   ") ;
            }
        }
        printf("+\n") ;
        if ( i < 5 ){
        for ( int j = 0 ; j < n ; ++j ){
            if( v_lines[j][i] == 1  ){
                printf( RED_TEXT"|   "RESET_TEXT ) ;
            }
            else if( v_lines[j][i] == 2 ){
                printf( GREEN_TEXT"|   "RESET_TEXT ) ;
            }
            else{
                printf("    ") ;
            }
        }
        printf("\n") ;
        }
        else printf("\n");
    }
}
void print_scores (){
    printf(RED_TEXT"player one's score %d\n"RESET_TEXT GREEN_TEXT"player two's score %d\n"RESET_TEXT , p1.score , p2.score  ) ;
}
void print_moves (){
printf(RED_TEXT"player one's moves %d\n"RESET_TEXT GREEN_TEXT"player two's moves %d\n"RESET_TEXT , p1.num_of_moves , p2.num_of_moves  ) ;
}

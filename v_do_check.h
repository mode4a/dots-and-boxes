#ifndef V_D_C
#define V_D_C


#include<stdio.h>
#include<math.h>
#include<stdbool.h>


extern int n ;
extern int h_lines[6][5] , v_lines[6][5] , tkn_dots , all_dots , dots[6][6] ;


int min( int a , int b ) ;

int is_H_or_v ( int r1 , int r2 , int c1 , int c2 ) ;

int valid_make_line( int r1 , int r2 , int c1 , int c2 , int turn_ ) ;

int check_h( int r , int c ) ;

int check_v( int c , int r ) ;

int v_do_check_( int r1 , int r2 , int c1 , int c2 , int turn_ ) ;

void update_dots ( int r1 , int r2 , int  c1 , int  c2 ) ;



#endif
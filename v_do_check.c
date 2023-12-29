
#include "v_do_check.h"
#include "input&output.h"
#include "players_turns.h"
#include "options.h"

int n = 6, h_lines[6][5] = {0}, v_lines[6][5] = {0};
int tkn_dots = 0 , dots[6][6] = {0} , boxes[25];

void update_dots(int r1, int r2, int c1, int c2)
{
    dots[r1 - 1][c1 - 1]++;
    dots[r2 - 1][c2 - 1]++;
    if ( ((( r1 == 1 ) && ( ( c1 == 1 ) || ( c1 == n ) )) || ( (r1 == n) && ((c1==1)|| (c1==n)) ))){
        if (dots[r1 - 1][c1 - 1] == 2){
            tkn_dots++;
            all_inputs[p1.num_of_moves+p2.num_of_moves].full_dots[0] = 1 ; // traking the full dots 
        }

    }
    else if ( ( r1 == 1 ) || ( c1 == 1 ) || ( c1 == n ) || (r1 == n) ){
        if (dots[r1 - 1][c1 - 1] == 3 ){
            tkn_dots++;
            all_inputs[p1.num_of_moves+p2.num_of_moves].full_dots[0] = 1 ;
        }
    }
    else
    {
        if ( dots[r1-1][c1-1] == 4 ){
            tkn_dots++;
            all_inputs[p1.num_of_moves+p2.num_of_moves].full_dots[0] = 1 ;
        }
    }
    if ( (( r2 == 1 ) && ( ( c2 == 1 ) || ( c2 == n ) ) ) || ( (r2 == n) && ((c2==1) || (c2==n)) ) ){
        if (dots[r2 - 1][c2 - 1] == 2){
            tkn_dots++;
            all_inputs[p1.num_of_moves+p2.num_of_moves].full_dots[1] = 1 ;
        }
    }
    else if ( ( r2 == 1 ) || ( c2 == 1 ) || ( c2 == n ) || (r2 == n) ){
        if (dots[r2 - 1][c2 - 1] == 3 ){
            tkn_dots++;
            all_inputs[p1.num_of_moves+p2.num_of_moves].full_dots[1] = 1 ;
        }
    }
    else{
        if ( dots[r2-1][c2-1] == 4 ){
            tkn_dots++;
            all_inputs[p1.num_of_moves+p2.num_of_moves].full_dots[1] = 1 ;
        }
    }
}

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int is_H_or_v(int r1, int r2, int c1, int c2)
{
    if( ((r1 == r2) && (c1 == c2)) )
    {
    return -1 ;
    }
    if (r1 == r2)
    {
        return 1;
    }
    else if (c1 == c2)
    {
        return 0;
    }
    return -1;
}
int is_valid_line( int r1, int r2, int c1, int c2 ){
   if( r1 <= n && r1 > 0 && r2 <= n && r2 > 0 && c1 <= n && c1 > 0 && c2 <= n && c2 > 0 && abs(r1-r2) <= 1 && abs(c1-c2) <= 1 )
        return 1 ; 
    return 0 ;
}

int valid_make_line(int r1, int r2, int c1, int c2 )
{
    if ( is_valid_line(r1,r2,c1,c2)  )
    {
        all_inputs[p1.num_of_moves+p2.num_of_moves].r1 = r1 ; // tracking the move 
        all_inputs[p1.num_of_moves+p2.num_of_moves].r2 = r2 ;
        all_inputs[p1.num_of_moves+p2.num_of_moves].c1 = c1 ;
        all_inputs[p1.num_of_moves+p2.num_of_moves].c2 = c2 ;
        if ( game_mode == 2 )
        num_of_undo_done = 0 ; // can't do redo after this move
        else
            if ( turn == 0 )
                num_of_undo_done = 0 ; // can't do redo after this move
        if (is_H_or_v(r1, r2, c1, c2) == 1)
        {
            int r = r1 - 1, c = min(c1, c2) - 1;
            if (!h_lines[r][c])
            {
                h_lines[r][c] = turn + 1;
                update_dots(r1, r2, c1, c2);
                update_moves(turn);
                return 1;
            }
            else
            {
                printf("this line is already taken!!\ntry again\n");
                return -1;
            }
        }
        else if (is_H_or_v(r1, r2, c1, c2) == 0)
        {
            int c = c1 - 1, r = min(r1, r2) - 1;
            if (!v_lines[c][r])
            {
                v_lines[c][r] = turn + 1;
                update_dots(r1, r2, c1, c2);
                update_moves(turn);
                return 2;
            }
            else
            {
                printf("this line is already taken!!\ntry again\n");
                return -1;
            }
        }
        else
        {
        printf("invalid input\ntry again\n");
        return -1;
        }
    }
    else
    {
        printf("invalid input\ntry again\n");
        return -1;
    }
}

int check_h(int r, int c )
{
    int ret = 0;
    if (r - 1 >= 0)
    {
        if (h_lines[r - 1][c] && v_lines[c][r - 1] && v_lines[c + 1][r - 1])
        {
            ret++;
            boxes[(n-1) * (r - 1) + c] = turn+1;
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[0] = (n-1) * (r - 1) + c ; // traking indicies off boxes gettin in this move
        }
        else
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[0] = -1 ;
    }
    else
        all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[0] = -1 ;
    if (r + 1 < n)
    {
        if (h_lines[r + 1][c] && v_lines[c][r] && v_lines[c + 1][r])
        {
            ret++;
            boxes[(n-1) * (r) + c] = turn+1;
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[1] = (n-1) * r + c ;
        }
        else
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[1] = -1 ;
    }
    else
        all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[1] = -1 ;
    return ret;
}
int check_v(int c, int r )
{
    int ret = 0;
    if (c - 1 >= 0)
    {
        if (v_lines[c - 1][r] && h_lines[r][c - 1] && h_lines[r + 1][c - 1])
        {
            ret++;
            boxes[(n-1) * (r) + c - 1] = turn+1;
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[0] = ((n-1) * r + c - 1) ; // traking indicies off boxes gettin in this move
        }
        else
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[0] =  -1 ;
    }
    else
        all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[0] =  -1 ;
    if (c + 1 < n)
    {
        if (v_lines[c + 1][r] && h_lines[r][c] && h_lines[r + 1][c])
        {
            ret++;
            boxes[(n-1) * (r) + c ] = turn+1;
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[1] = ((n-1) * r + c) ; 
        }
        else
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[1] = -1  ;
    }
    else
        all_inputs[p1.num_of_moves+p2.num_of_moves-1].boxs_indx[1] = -1  ;
    return ret;
}

int v_do_check_(int r1, int r2, int c1, int c2 )
{

    int h_or_v_or_invalid = valid_make_line(r1, r2, c1, c2);
    if (h_or_v_or_invalid == 1)
    {
        int r = r1 - 1, c = min(c1, c2) - 1;
        int score = check_h(r, c);
        if (score)
        {
            update_scores(score, turn);
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].num_of_boxes = score ; // traking either it's 1 , 2 or zero boxes get in this move
        }
        else
        {
            turn ^= 1;
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].num_of_boxes = 0 ;
        }
    }
    else if (h_or_v_or_invalid == 2)
    {
        int c = c1 - 1, r = min(r1, r2) - 1;
        int score = check_v(c, r);
        if (score)
        {
            update_scores(score, turn);
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].num_of_boxes = score ;
        }
        else
        {
            turn ^= 1;
            all_inputs[p1.num_of_moves+p2.num_of_moves-1].num_of_boxes = 0 ;
        }
    }
    else if (h_or_v_or_invalid == -1)
    {
        return -1 ;
    }
}

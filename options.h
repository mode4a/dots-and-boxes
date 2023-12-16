#ifndef OPT
#define OPT

struct store_for_undo{
    int r1 , r2 , c1 , c2 , turn , num_of_boxes , boxs_indx[2] , full_dots[2] , compu_move_this_point  ;
};
extern int num_of_undo_done ; 
extern int computer_moves ; 
int undo();
int redo();
int options_window();
extern struct store_for_undo all_inputs[60] ;




















#endif

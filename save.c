#include "v_do_check.h"
#include "input&output.h"
#include "players_turns.h"

void saving1()
{
    FILE *game = fopen("game1.bin", "wb");

    if (game != NULL)
    {
        fwrite(&game_mode, sizeof(int), 1, game);
        fwrite(v_lines, sizeof(int), 30, game);
        fwrite(h_lines, sizeof(int), 30, game);
        fwrite(&n,sizeof(int),1,game);
        fwrite(boxes, sizeof(int), 25, game);
        fwrite(&p1, sizeof(struct player), 1, game);
        fwrite(&p2, sizeof(struct player), 1, game);
        fwrite(&turn, sizeof(int), 1, game);
        fwrite(dots ,sizeof(int) , 36 , game);
        fwrite(&tkn_dots , sizeof(int) , 1 , game );

        fclose(game);
        printf("Data successfully saved.\n");
    }
    else
    {
        printf("Error opening file for saving.\n");
    }
}
void saving2()
{
    FILE *game = fopen("game2.bin", "wb");

    if (game != NULL)
    {
        fwrite(&game_mode, sizeof(int), 1, game);
        fwrite(v_lines, sizeof(int), 30, game);
        fwrite(h_lines, sizeof(int), 30, game);
        fwrite(&n,sizeof(int),1,game);
        fwrite(boxes, sizeof(int), 25, game);
        fwrite(&p1, sizeof(struct player), 1, game);
        fwrite(&p2, sizeof(struct player), 1, game);
        fwrite(&turn, sizeof(int), 1, game);
        fwrite(dots ,sizeof(int) , 36 , game);
        fwrite(&tkn_dots , sizeof(int) , 1 , game );

        fclose(game);
        printf("Data successfully saving.\n");
    }
    else
    {
        printf("Error opening file for saving.\n");
    }
}
void saving3()
{
    FILE *game = fopen("game3.bin", "wb");

    if (game != NULL)
    {
        fwrite(&game_mode, sizeof(int), 1, game);
        fwrite(v_lines, sizeof(int), 30, game);
        fwrite(h_lines, sizeof(int), 30, game);
        fwrite(&n,sizeof(int),1,game);
        fwrite(boxes, sizeof(int), 25, game);
        fwrite(&p1, sizeof(struct player), 1, game);
        fwrite(&p2, sizeof(struct player), 1, game);
        fwrite(&turn, sizeof(int), 1, game);
        fwrite(dots ,sizeof(int) , 36 , game);
        fwrite(&tkn_dots , sizeof(int) , 1 , game );

        fclose(game);
        printf("Data successfully saved.\n");
        
    }
    else
    {
        printf("Error opening file for saving.\n");
    }
}
void reading1()
{
    FILE *game = fopen("game1.bin", "ab+");

    if (game != NULL)
    {
        fread(&game_mode, sizeof(int), 1, game);
        fread(v_lines, sizeof(int), 30, game);
        fread(h_lines, sizeof(int), 30, game);
        fread(&n,sizeof(int),1,game);
        fread(boxes, sizeof(int), 25, game);
        fread(&p1, sizeof(struct player), 1, game);
        fread(&p2, sizeof(struct player), 1, game);
        fread(&turn, sizeof(int), 1, game);
        fread(dots ,sizeof(int) , 36 , game);
        fread(&tkn_dots , sizeof(int) , 1 , game );

        fclose(game);
        printf("Data successfully reload.\n");
        if (game_mode == 1)
        {
            print_grid();
            print_scores();
            print_moves();
            print_remaining_dots();
            one_player_game();
        }
        else if (game_mode == 2)
        {
            print_grid();
            print_scores();
            print_moves();
            print_remaining_dots();
            two_player_game();
        }
    }
    else
    {
        printf("Error opening file for reload.\n");
    }
}
void reading2()
{
    FILE *game = fopen("game2.bin", "ab+");

    if (game != NULL)
    {
        fread(&game_mode, sizeof(int), 1, game);
        fread(v_lines, sizeof(int), 30, game);
        fread(h_lines, sizeof(int), 30, game);
        fread(&n,sizeof(int),1,game);
        fread(boxes, sizeof(int), 25, game);
        fread(&p1, sizeof(struct player), 1, game);
        fread(&p2, sizeof(struct player), 1, game);
        fread(&turn, sizeof(int), 1, game);
        fread(dots ,sizeof(int) , 36 , game);
        fread(&tkn_dots , sizeof(int) , 1 , game );

        fclose(game);
        printf("Data successfully reload.\n");
        if (game_mode == 1)
        {
            print_grid();
            print_scores();
            print_moves();
            print_remaining_dots();
            one_player_game();
        }
        else if (game_mode == 2)
        {
            print_grid();
            print_scores();
            print_moves();
            print_remaining_dots();
            two_player_game();
        }
    }
    else
    {
        printf("Error opening file for reload.\n");
    }
}
void reading3()
{
    FILE *game = fopen("game3.bin", "rb");

    if (game != NULL)
    {
        fread(&game_mode, sizeof(int), 1, game);
        fread(v_lines, sizeof(int), 30, game);
        fread(h_lines, sizeof(int), 30, game);
        fread(&n,sizeof(int),1,game);
        fread(boxes, sizeof(int), 25, game);
        fread(&p1, sizeof(struct player), 1, game);
        fread(&p2, sizeof(struct player), 1, game);
        fread(&turn, sizeof(int), 1, game);
        fread(dots ,sizeof(int) , 36 , game);
        fread(&tkn_dots , sizeof(int) , 1 , game );

        fclose(game);
        printf("Data successfully reload.\n");
        if (game_mode == 1)
        {
            print_grid();
            print_scores();
            print_moves();
            print_remaining_dots();
            one_player_game();
        }
        else if (game_mode == 2)
        {
            print_grid();
            print_scores();
            print_moves();
            print_remaining_dots();
            two_player_game();
        }
    }
    else
    {
        printf("Error opening file for reload.\n");
    }
}
int save_game(){
    printf("1_file1\n2_file2\n3_file3\n"); int choise ; scanf("%d" , &choise) ;
    switch (choise)
    {
    case 1:
        saving1();
        break;
    case 2:
        saving2();
        break;
    case 3:
        saving3();
        break;
    default:
        printf("invalid input!\n") ;
        break;
    }
    return turn ; 
}
void load_game(){
    printf("1_file1\n2_file2\n3_file3\n") ; int choise ; scanf("%d" , &choise ) ;
    switch (choise)
    {
    case 1:
        reading1();
        break;
    case 2:
        reading2();
        break;
    case 3:
        reading3();
        break;
    default:
        printf("invalid input!\n") ;
        break;
    }
}
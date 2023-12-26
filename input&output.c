#include <stdlib.h>
#include<stdio.h>
#include "v_do_check.h"
#include "players_turns.h"
#include "input&output.h"
#include "options.h"
#include "save.h"
#include "top_10.h"

int game_mode;

struct game_input get_input()
{
    struct game_input ret;
    int check = scanf("%d", &ret.r1);
    if (check < 0)
    {
        printf("Invalid input\n");
        while (getchar() != '\n');
        printf("try again ");
        return get_input();
    }
    if (ret.r1 > 0)
    {
        check = scanf("%1d%1d%1d", &ret.r2, &ret.c1, &ret.c2);
        if (check < 1)
        {
            printf("Invalid input\n");
            while (getchar() != '\n');
            printf("try again ");
            return get_input();
        }
    }
    else
    {
        options_window();
    }
    return ret;
}

// struct game_input generate_random(){
//     struct game_input ret ;
//     ret.r1 = rand() % 6 + 1;  // Generates a number between 1 and 6
//     ret.r2 = rand() % 6 + 1;
//     ret.c1 = rand() % 6 + 1;
//     ret.c2 = rand() % 6 + 1;
// return ret ;
// }

struct game_input generate_random()
{
    struct game_input ret;
    int flag = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            if (h_lines[i][j] == 0)
            {
                ret.r1 = i + 1;
                ret.r2 = i + 1;
                ret.c1 = j + 1;
                ret.c2 = j + 2;
                flag = 1;
                return ret;
            }
        }
    }
    if (!flag)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                if (v_lines[i][j] == 0)
                {
                    ret.r1 = j + 1;
                    ret.r2 = j + 2;
                    ret.c1 = i + 1;
                    ret.c2 = i + 1;
                    return ret;
                }
            }
        }
    }
    return ret;
}

void print_grid()
{
    printf(" ");
    for (int i=0;i<n;i++){
        printf (" %d  ",i+1);
    }
    printf("\n");
    for (int i = 0; i < n; ++i)
    { printf("%d ",i+1);
        for (int j = 0; j < n - 1; ++j)
        {
            if (h_lines[i][j] == 1)
            {
                printf("+" BOLD_RED "---" RESET_TEXT);
            }
            else if (h_lines[i][j] == 2)
            {
                printf("+" BOLD_GREEN "---" RESET_TEXT);
            }
            else
            {
                printf("+   ");
            }
        }
        printf("+\n");
        printf("  ");
        if (i < (n - 1))
        {
            for (int j = 0; j < n; ++j)
            {
                if (v_lines[j][i] == 1)
                {
                    printf(BOLD_RED "|" RESET_TEXT);
                }
                else if (v_lines[j][i] == 2)
                {
                    printf(BOLD_GREEN "|" RESET_TEXT);
                }
                else
                {
                    printf(" ");
                }
                if (j < (n - 1))
                {
                    if (boxes[(n - 1) * i + j] == 1)
                    {
                        printf(RED_BOX "   " RESET_TEXT);
                    }
                    else if (boxes[(n - 1) * i + j] == 2)
                    {
                        printf(GREEN_BOX "   " RESET_TEXT);
                    }
                    else
                    {
                        printf("   ");
                    }
                }
            }
            printf("\n");
        }
        else
            printf("\n");
    }
}
void print_scores()
{
    printf(RED_TEXT "player one's score %d\n" RESET_TEXT GREEN_TEXT "player two's score %d\n" RESET_TEXT, p1.score, p2.score);
}
void print_moves()
{
    printf(RED_TEXT "player one's moves %d\n" RESET_TEXT GREEN_TEXT "player two's moves %d\n" RESET_TEXT, p1.num_of_moves, p2.num_of_moves);
}
void print_remaining_dots()
{
    printf(PINK_TEXT "remaining dots = %d\n" RESET_TEXT, (n*n - tkn_dots));
}
void choosing_level()
{
    int choise;
    printf(GREEN_TEXT "choose level\n1.beginer\n2.expert\n" RESET_TEXT);
    int check = scanf("%d", &choise);
        if (check < 1)
    {
        printf("Invalid input\n");
        while (getchar() != '\n');
        choosing_level();
    }
    if (choise == 1)
    {
        n = 3;
    }
    else if (choise == 2)
    {
        n = 6;
    }
    else
    {
        printf("invald input\n");
        choosing_level();
    }
}
void main_menu(){
    printf(
            PINK_TEXT "hello in dots and boxes !\n" RESET_TEXT
            YELLOW_TEXT "1.one player game\n" RESET_TEXT
            BLUE_TEXT "2.two player game\n" RESET_TEXT
            RED_TEXT "3.load game\n" RESET_TEXT
            GREEN_TEXT "4.show top10 player\n" RESET_TEXT
        );
    int choise;
    int check = scanf("%d", &choise);
    if (check < 1)
    {
        printf("Invalid input\n");
        while (getchar() != '\n');
        main_menu();
    }
    if (choise == 1)
    {
        game_mode = 1;
        choosing_level();
        one_player_game();
    }
    else if (choise == 2)
    {
        game_mode = 2;
        choosing_level();
        two_player_game();
    }
    else if (choise == 3)
    {
        load_game();
    }
    else if (choise == 4)
    {
        showing_champion();
    }
    else
    {
        printf("invald input\n");
        main_menu();
    }
}
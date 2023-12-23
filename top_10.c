#include "players_turns.h"
#include <stdio.h>
#include "v_do_check.h"
#include "input&output.h"
#include <stdlib.h>
#include <string.h>
#include "top_10.h"
top_10 winner;
top_10 array[50];
int number_of_players= 0;
int comparePeople(const void *a, const void *b)
{
    // Assuming you want to sort by score
    return ((top_10 *)b)->score - ((top_10 *)a)->score;
}
void showing_champion()
{
    FILE *champions = fopen("champions.bin", "rb+");
    fread(array, sizeof(top_10), 50, champions);
    fread(&number_of_players,sizeof(int),1,champions);
    qsort(array, number_of_players, sizeof(top_10), comparePeople);
    printf("   name                    score  \n");
    for (int i = 0; i < 10; i++)
    {
        int no=i+1;
        printf("%d  %s                    %d   \n",no, array[i].name, array[i].score);
    }
    fclose(champions);
}
void saving_champion(int high_score)
{
    FILE *champions = fopen("champions.bin", "rb+");
    if (!champions )
    {
        printf("error in opening file");
    }
    else
    {
        fread(array, sizeof(top_10), 50, champions);
        fread(&number_of_players, sizeof(int), 1, champions);
        fclose(champions);
        winner.score = high_score;
        int flag = 0, counter;
        for (int i = 0; i < number_of_players; i++)
        {
            if (strcmp(array[i].name, winner.name) == 0)
            {
                flag = 1;
                counter = i;
                break;
            }
        }
        if (flag == 1)
        {
            if (array[counter].score > high_score)
            {
                showing_champion();
            }
            else
            {
                array[counter].score = high_score;
                FILE *old_champions = fopen("champions.bin", "wb+");
                qsort(array, number_of_players, sizeof(top_10), comparePeople);
                fwrite(array, sizeof(winner), 50, old_champions);
                fclose(old_champions);
                showing_champion();
            }
        }
        else
        {
            array[number_of_players++] = winner;
            for (int i = number_of_players ; i < 11; i++)
            {
                strcpy(array[i].name, "no name");
                array[i].score = 000;
            }
            FILE *old_champions = fopen("champions.bin", "wb+");
            qsort(array, number_of_players, sizeof(top_10), comparePeople);
            fwrite(array, sizeof(winner), 50, old_champions);
            fwrite(&number_of_players, sizeof(int), 1, old_champions);
            fclose(old_champions);
            showing_champion();
        }
    }
}

#include "players_turns.h"
#include <stdio.h>
#include "v_do_check.h"
#include "input&output.h"
#include <stdlib.h>
#include <string.h>
#include "top_10.h"
top_10 winner;
top_10 array[50];
int x = 0;
int comparePeople(const void *a, const void *b)
{
    // Assuming you want to sort by score
    return ((top_10 *)b)->score - ((top_10 *)a)->score;
}
void showing_champion()
{
    FILE *champions = fopen("champions.bin", "rb+");
    fread(array, sizeof(top_10), 50, champions);
    fread(&x,sizeof(int),1,champions);
    qsort(array, x, sizeof(top_10), comparePeople);
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
    FILE *champions = fopen("champions.bin", "wb+");
    if (champions = NULL)
    {
        printf("error in opening file");
    }
    else
    {
        fread(array, sizeof(top_10), 50, champions);
        fread(&x, sizeof(int), 1, champions);
        fclose(champions);
        winner.score = high_score;
        int flag = 0, y;
        for (int i = 0; i < x; i++)
        {
            if (strcmp(array[i].name, winner.name) == 0)
            {
                flag = 1;
                y = i;
                break;
            }
        }
        if (flag == 1)
        {
            if (array[y].score > high_score)
            {
                showing_champion();
            }
            else
            {
                array[y].score = high_score;
                FILE *old_champions = fopen("champions.bin", "wb+");
                qsort(array, x, sizeof(top_10), comparePeople);
                fwrite(array, sizeof(winner), 50, old_champions);
                fclose(old_champions);
                showing_champion();
            }
        }
        else
        {
            array[x] = winner;
            x++;
            for (int i = x ; i < 11; i++)
            {
                strcpy(array[i].name, "no name");
                array[i].score = 000;
            }
            FILE *old_champions = fopen("champions.bin", "wb+");
            qsort(array, x, sizeof(top_10), comparePeople);
            fwrite(array, sizeof(winner), 50, old_champions);
            fwrite(&x, sizeof(int), 1, old_champions);
            fclose(old_champions);
            showing_champion();
        }
    }
}

typedef struct 
{
    char name[50];
    int score;
} top_10;
extern top_10 winner;
extern top_10 array[50];
void saving_champion(int high_score);
void showing_champion();
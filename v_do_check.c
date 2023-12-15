
#include "v_do_check.h"
#include "print.h"
#include "players_turns.h"

int n = 6, h_lines[6][5] = {0}, v_lines[6][5] = {0};
int tkn_dots = 0, all_dots = 36, dots[6][6] = {0};

void update_dots(int r1, int r2, int c1, int c2)
{
    dots[r1 - 1][c1 - 1]++;
    dots[r2 - 1][c2 - 1]++;
    if (dots[r1 - 1][c1 - 1] == 2)
    {
        tkn_dots++;
    }
    if (dots[r2 - 1][c2 - 1] == 2)
    {
        tkn_dots++;
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

int valid_make_line(int r1, int r2, int c1, int c2, int turn_)
{
    if (r1 <= n && r1 > 0 && r2 <= n && r2 > 0 && c1 <= n && c1 > 0 && c2 <= n && c2 > 0)
    {
        if (is_H_or_v(r1, r2, c1, c2) == 1)
        {
            int r = r1 - 1, c = min(c1, c2) - 1;
            if (!h_lines[r][c])
            {
                h_lines[r][c] = turn_ + 1;
                update_dots(r1, r2, c1, c2);
                update_moves(turn_);
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
                v_lines[c][r] = turn_ + 1;
                update_dots(r1, r2, c1, c2);
                update_moves(turn_);
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
            printf("invalid input !\ntry again\n");
            return -1;
        }
    }
    else
    {
        printf("invalid input\ntry again\n");
        return -1;
    }
}

int check_h(int r, int c, int box_turn)
{
    int ret = 0;
    if (r - 1 >= 0)
    {
        if (h_lines[r - 1][c] && v_lines[c][r - 1] && v_lines[c + 1][r - 1])
        {
            ret++;
            boxes[6 * (r - 1) + c] = box_turn+1;
        }
    }
    if (r + 1 < n)
    {
        if (h_lines[r + 1][c] && v_lines[c][r] && v_lines[c + 1][r])
        {
            ret++;
            boxes[6 * (r) + c] = box_turn+1;
        }
    }
    return ret;
}
int check_v(int c, int r,int box_turn)
{
    int ret = 0;
    if (c - 1 >= 0)
    {
        if (v_lines[c - 1][r] && h_lines[r][c - 1] && h_lines[r + 1][c - 1])
        {
            ret++;
            boxes[6 * (r) + c - 1] = box_turn+1;
        }
    }
    if (c + 1 < n)
    {
        if (v_lines[c + 1][r] && h_lines[r][c] && h_lines[r + 1][c])
        {
            ret++;
            boxes[6 * (r) + c ] = box_turn+1;
        }
    }
    return ret;
}

int v_do_check_(int r1, int r2, int c1, int c2, int turn_)
{

    int h_or_v = valid_make_line(r1, r2, c1, c2, turn_);
    if (h_or_v == 1)
    {
        int r = r1 - 1, c = min(c1, c2) - 1;
        int score = check_h(r, c, turn_);
        if (score)
        {
            printf("nice one\n");
            update_scores(score, turn_);
        }
        else
        {
            turn_ ^= 1;
        }
    }
    else if (h_or_v == 2)
    {
        int c = c1 - 1, r = min(r1, r2) - 1;
        int score = check_v(c, r,turn_);
        if (score)
        {
            printf("nice one\n");
            update_scores(score, turn_);
        }
        else
        {
            turn_ ^= 1;
        }
    }
    else if (h_or_v == -1)
    {
        return turn_;
    }
    // next player's turn
    print_grid();
    print_scores();
    print_moves();
    return turn_;
}

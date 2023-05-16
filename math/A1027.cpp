#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str_num_map[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    int R, G, B;
    scanf("%d %d %d", &R, &G, &B);
    printf("#");
    if (R > 12)
    {
        printf("%c%c", str_num_map[R / 13], str_num_map[R % 13]);
    }
    else
    {
        printf("0%c", str_num_map[R % 13]);
    }

    if (G > 12)
    {
        printf("%c%c", str_num_map[G / 13], str_num_map[G % 13]);
    }
    else
    {
        printf("0%c", str_num_map[G % 13]);
    }
    if (B > 12)
    {
        printf("%c%c", str_num_map[B / 13], str_num_map[B % 13]);
    }
    else
    {
        printf("0%c", str_num_map[B % 13]);
    }
    printf("\n");
    // printf("%02d%02d%02d\n", R_out, G_out, B_out);
    system("pause");
    return 0;
}
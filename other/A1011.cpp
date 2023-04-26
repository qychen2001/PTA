#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k = 0;
    double a[3][3] = {};
    double max[3] = {-1};
    char T = 'T', W = 'W', L = 'L';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%lf", &a[i][j]);
            if (a[i][j] > max[i])
            {
                max[i] = a[i][j];
                k = j;
            }
        }
        if (k == 0)
            printf("%c ", W);
        else if (k == 1)
            printf("%c ", T);
        else
            printf("%c ", L);
    }
    double sum = (max[0] * max[1] * max[2] * 0.65 - 1) * 2;
    printf("%.2f\n", sum);
    return 0;
}
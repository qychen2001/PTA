#include <bits/stdc++.h>
using namespace std;

int k1, k2;
double a1[1005];
double a2[1005];
int temp[1005];
int non_zero = 0;
double result[2015];
int main()
{
    memset(a1, 0.0, sizeof(a1));
    memset(a2, 0.0, sizeof(a2));
    memset(result, 0.0, sizeof(result));
    scanf("%d", &k1);
    int t;
    for (int i = 0; i < k1; i++)
    {
        scanf("%d", &t);
        scanf("%lf", &a1[t]);
    }

    scanf("%d", &k2);
    for (int i = 0; i < k2; i++)
    {
        scanf("%d", &t);
        scanf("%lf", &a2[t]);
    }
    for (int j = 0; j < 1005; j++)
    {
        for (int i = 0; i < 1005; i++)
        {
            result[i + j] += (a1[j] * a2[i]);
        }
    }
    for (int i = 0; i < 2015; i++)
    {
        if (result[i] != 0)
            non_zero += 1;
    }

    printf("%d", non_zero);

    for (int i = 2014; i >= 0; i--)
    {
        if (result[i] != 0) // 此处不可以写作>0
            printf(" %d %.1f", i, result[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
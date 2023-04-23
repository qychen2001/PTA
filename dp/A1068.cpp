#include <bits/stdc++.h>
using namespace std;
int N, M;
int coin[10005];
int dp[10005] = {0};
bool choice[10005][105];
bool flag[10005];
bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) // 注意边界
    {
        scanf("%d", &coin[i]);
    }
    sort(coin + 1, coin + N + 1, cmp);
    for (int i = 1; i <= N; i++)
    {
        for (int v = M; v >= coin[i]; v--)
        {
            if (dp[v] <= dp[v - coin[i]] + coin[i])
            {
                dp[v] = dp[v - coin[i]] + coin[i];
                choice[i][v] = true;
                // printf("choice");
            }
            else
            {
                choice[i][v] = false;
            }
        }
    }
    if (dp[M] != M)
    {
        printf("No Solution");
    }
    // 寻找路径
    else
    {
        // printf("%d", dp[M]);
        int k = N, v = M, num = 0;
        while (k >= 0)
        {
            // 从后向前一件一件看
            if (choice[k][v] == true)
            {
                // printf("choice");
                flag[k] = true;
                v -= coin[k];
                num++;
            }
            else
            {
                flag[k] = false;
            }
            k--;
        }

        // 输出最终结果
        for (int i = N; i >= 1; i--)
        {
            // printf("%d", flag[i]);
            if (flag[i] == true)
            {
                printf("%d", coin[i]);
                num--;
                if (num > 0)
                    printf(" ");
            }
        }
    }
    system("pause");
    return 0;
}
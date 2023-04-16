#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    int start = 0;
    int end = 0;
    scanf("%d", &k);
    int ans_max = 0;
    int A[10005];
    int dp[10005]; // dp[i]表示以第i个元素结尾的最大子段和
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &A[i]);
    }
    dp[0] = A[0];
    for (int i = 1; i <= k; i++)
    {
        if (dp[i - 1] + A[i] > A[i])
        {
            dp[i] = dp[i - 1] + A[i];
            ans_max = dp[i];
            end = i;
        }
        else
        {
            dp[i] = A[i];
            if (dp[i] > ans_max)
            {
                ans_max = dp[i];
                start = i;
            }
        }
    }
    if (ans_max < 0)
    {
        printf("0 %d %d", A[0], A[k - 1]);
    }
    else
    {
        printf("%d %d %d", ans_max, A[start], A[end]);
    }
}

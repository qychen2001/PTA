#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
using namespace std;
char s[1010];
int main()
{
    cin.getline(s, 1010);
    int len = strlen(s); // gets 不被支持
    int dp[1010][1010];  // 表示i到j是否为回文串
    memset(dp, 0, sizeof(dp));
    int ans = 1;
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i < len - 1)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }

    for (int L = 3; L <= len; L++)
    {
        for (int i = 0; i + L - 1 < len; i++)
        {
            int j = i + L - 1;
            if (s[i] == s[j] and dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
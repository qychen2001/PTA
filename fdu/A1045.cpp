#include <bits/stdc++.h>
using namespace std;

int num_c, num_f, num_s;
int c_hash[205];
int s_after_hash[10005];
// 将问题转化为不降子序列和问题，首先需要将原始的数字做一个映射

int dp[10005]; // dp表示以i结尾的最长不降子序列长度

int main()
{
    scanf("%d", &num_c);
    scanf("%d", &num_f);
    memset(c_hash, -1, sizeof(c_hash));
    for (int i = 1; i <= num_f; i++)
    {
        int x;
        scanf("%d", &x); // 读入了序列，接下来要做一个映射，第一次出现的数字标为1
        c_hash[x] = i;   // 从1开始
    }
    scanf("%d", &num_s);
    int num = 0;
    for (int i = 0; i < num_s; i++)
    {
        int x;
        scanf("%d", &x);
        if (c_hash[x] > 0)
            s_after_hash[num++] = c_hash[x]; // 要判断是否为喜欢的颜色
    }

    int ans = 0;
    for (int i = 0; i < num; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (s_after_hash[j] <= s_after_hash[i])
            // 此处是小于等于！！！
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}
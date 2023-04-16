#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M, L;
    scanf("%d", &N);
    scanf("%d", &M);
    int fc[205];
    int fc_new[205];
    int s[10005];
    int hashmap[205];
    int s_new[10005];
    memset(hashmap, -1, sizeof(hashmap)); // 使用memset来给数据赋初始值
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &fc[i]);
        hashmap[fc[i]] = i; // 用一个hashmap标记新编号
    }
    scanf("%d", &L);
    int num = 0;
    for (int i = 0; i < L; i++)
    {
        scanf("%d", &s[i]);
        if (hashmap[s[i]] != -1) // 如果s[i]是喜欢的颜色
        {
            s_new[num] = hashmap[s[i]]; // 用新编号替换原来的编号，同时num++
            num++;
        }
    }
    // 接下来题目转化为求s_new的最长不降子序列
    int dp[10005]; // dp[i]表示以第i个元素为末尾的最长不降子序列长度
    int ans = -1;
    for (int i = 0; i < num; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (s_new[j] <= s_new[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]); // 动态更新ans的值
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}
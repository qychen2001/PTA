#include <bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int max_depth = 0;
int max_num = 0;
void dfs(int root, int depth)
{
    if (v[root].empty()) // 说明到达叶子节点
    {
        if (depth > max_depth)
        {
            max_depth = depth;
            max_num = 1;
        }
        else if (depth == max_depth)
        {
            max_num++;
        }
    }
    for (int i = 0; i < v[root].size(); i++)
    {
        dfs(v[root][i], depth + 1);
    }
}

int main()
{
    int N;
    double p, r;

    int temp, root;
    scanf("%d %lf %lf", &N, &p, &r);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        if (temp == -1)
            root = i;
        else
        {
            v[temp].push_back(i);
        }
    }
    dfs(root, 0);
    printf("%.2f %d", p * pow(1 + r / 100, max_depth), max_num);
    return 0;
}

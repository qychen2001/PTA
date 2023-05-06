#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int next_add = -1; // 下一个节点的地址
    char data;
    bool in_1 = false;
    bool in_2 = false;
} node[100005];

int main()
{
    int start_add_1, start_add_2, N;
    scanf("%d %d %d", &start_add_1, &start_add_2, &N);
    int add, next;
    char data;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %c %d", &add, &data, &next);
        node[add].data = data;
        node[add].next_add = next;
    }
    for (int p = start_add_1; p != -1; p = node[p].next_add)
    {
        node[p].in_1 = true;
    }
    bool flag = false;
    int result = -1;
    for (int p = start_add_2; p != -1; p = node[p].next_add)
    {
        node[p].in_2 = true;
        if (node[p].in_1 == true)
        {
            result = p;
            break;
        }
    }
    result == -1 ? printf("-1\n", result)
                 : printf("%05d\n", result); // 此处需要判断是否为-1，否则需要用0补全输出
    system("pause");
    return 0;
}

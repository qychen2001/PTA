#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    int add;
    int next;
    int flag = false;
} node[100005];

bool cmp(Node a, Node b)
{

    return a.data < b.data; // 小的保存在前面
}

int main()
{
    int N, root;
    scanf("%d %d", &N, &root);
    int data, add, next;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &add, &data, &next);
        node[add].add = add;
        node[add].data = data;
        node[add].next = next;
    }
    int num_node = 0;

    // 接下来要判断节点的合法性，用flag变量表示
    for (int p = root; p != -1; p = node[p].next)
    {
        node[p].flag = true; // 说明是一条链表中的元素
        // printf("%d\n", node[p].data);
        num_node++;
    }
    if (num_node == 0)
    {
        printf("0 -1");
        return 0;
    } // 特判

    for (int i = 0; i < 100005; i++)
    {
        if (node[i].flag == false)
            node[i].data = 1e5 + 5;
    }

    sort(node, node + 100005, cmp);
    printf("%d %05d\n", num_node, node[0].add); // 此处也需要05d
    for (int i = 0; i < num_node; i++)
    {
        i == num_node - 1 ? printf("%05d %d -1\n", node[i].add, node[i].data) : printf("%05d %d %05d\n", node[i].add, node[i].data, node[i + 1].add); // 千万注意输入输出的细节！
    }
    system("pause");
}
// 测试不在的情况
// 6 00001
// 11111 100 -1
// 00001 0 22222
// 33333 100000 11111
// 12345 -1 33333
// 22222 1000 12345
// 12312 50 67890
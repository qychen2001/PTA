#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int flag[maxn];              // 如果flag为-1，表示没出现过，否则保留第一次出现该数字的add
bool remain[maxn] = {false}; // 是否需要保留
struct Node
{
    int data;
    int add;
    int next = -1;
} node[maxn], remain_node[maxn], remove_node[maxn];

int main()
{
    memset(flag, -1, sizeof(flag)); // 给flag数组赋值，
    int init_node, N;
    scanf("%d %d", &init_node, &N);
    int num_remain = 0;
    for (int i = 0; i < N; i++)
    {
        int add_tmp, data_tmp, next_tmp;
        scanf("%d %d %d", &add_tmp, &data_tmp, &next_tmp);
        node[add_tmp].add = add_tmp;
        node[add_tmp].data = data_tmp;
        node[add_tmp].next = next_tmp;
        data_tmp >= 0 ? data_tmp = data_tmp : data_tmp = -data_tmp; // 取绝对值
    }
    // 移除的节点个数
    int current_node = init_node;
    int current_node_remain = init_node;
    int current_node_remove = -1;
    int current_remove = 0;
    int current_remain = 0;
    for (int i = 0; i < N; i++)
    {
        int data_tmp = node[current_node].data;
        data_tmp >= 0 ? data_tmp = data_tmp : data_tmp = -data_tmp; // 绝对值
        if (flag[data_tmp] == -1)
        {
            flag[data_tmp] = node[current_node].add;
            num_remain++;
            current_node_remain = current_node;

            remain_node[current_remain].add = node[current_node_remain].add;
            remain_node[current_remain].data = node[current_node_remain].data;
            current_remain++;
        }
        else
        {
            current_node_remove = current_node;
            remove_node[current_remove].add = node[current_node_remove].add;
            remove_node[current_remove].data = node[current_node_remove].data;
            current_remove++;
        }
        current_node = node[current_node].next;
    }
    int num_remove = N - num_remain;
    for (int i = 0; i < num_remain; i++)
    {
        i == num_remain - 1 ? printf("%05d %d -1\n", remain_node[i].add, remain_node[i].data) : printf("%05d %d %05d\n", remain_node[i].add, remain_node[i].data, remain_node[i + 1].add);
    }
    for (int i = 0; i < num_remove; i++)
    {
        i == num_remove - 1 ? printf("%05d %d -1\n", remove_node[i].add, remove_node[i].data) : printf("%05d %d %05d\n", remove_node[i].add, remove_node[i].data, remove_node[i + 1].add);
    }
    system("pause");
    return 0;
}

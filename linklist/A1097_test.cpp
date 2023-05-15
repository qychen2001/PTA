#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 100000;
struct NODE
{
    int address, key, next, num = 2 * maxn;
} node[maxn];
bool exist[maxn];
int cmp1(NODE a, NODE b)
{
    return a.num < b.num;
}
int main()
{
    int begin, n, cnt1 = 0, cnt2 = 0, a;
    scanf("%d%d", &begin, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        scanf("%d%d", &node[a].key, &node[a].next);
        node[a].address = a;
    }
    for (int i = begin; i != -1; i = node[i].next)
    {
        if (exist[abs(node[i].key)] == false)
        {
            exist[abs(node[i].key)] = true;
            node[i].num = cnt1;
            cnt1++;
        }
        else
        {
            node[i].num = maxn + cnt2;
            cnt2++;
        }
    }
    sort(node, node + maxn, cmp1);
    int cnt = cnt1 + cnt2;
    for (int i = 0; i < cnt; i++)
    {
        if (i != cnt1 - 1 && i != cnt - 1)
        {
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i + 1].address);
        }
        else
        {
            printf("%05d %d -1\n", node[i].address, node[i].key);
        }
    }
    system("pause");
    return 0;
}

// 00100 5
// 99999 15 87654
// 23854 -15 00000
// 87654 15 -1
// 00000 15 99999
// 00100 15 23854

// 00100 5
// 99999 -7 87654
// 23854 -15 00000
// 00100 21 23854
// 87654 16 -1
// 00000 17 99999

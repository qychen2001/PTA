#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int prv;
    int data;
    int add;
    int next;
};
int add;
Node node[100000];
int main()
{
    vector<int> L1, L2;
    vector<int> ans;
    int l1_root, l2_root, N;
    scanf("%d %d %d", &l1_root, &l2_root, &N);

    for (int i = 0; i < N; i++)
    {
        cin >> add >> node[add].data >> node[add].next;
    }
    int l1_tmp = l1_root;
    while (l1_tmp != -1)
    {
        L1.push_back(l1_tmp);
        l1_tmp = node[l1_tmp].next;
    }
    int l2_tmp = l2_root;
    while (l2_tmp != -1)
    {
        L2.push_back(l2_tmp);
        l2_tmp = node[l2_tmp].next;
    }
    // l1中保存较长的
    if (L1.size() < L2.size())
        swap(L1, L2);

    int c = L2.size() - 1;
    for (int i = 0; i < L1.size(); i++)
    {
        ans.push_back(L1[i]);
        if (i % 2 == 1 and c >= 0)
        {
            ans.push_back(L2[c]);
            c--;
        }
    }
    for (int i = 1; i < ans.size(); i++)
    {
        printf("%05d %d %05d\n", ans[i - 1], node[ans[i - 1]].data, ans[i]);
    }
    printf("%05d %d -1\n", ans[ans.size() - 1], node[ans[ans.size() - 1]].data);
    system("pause");
    return 0;
}
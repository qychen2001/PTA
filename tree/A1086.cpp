#include <bits/stdc++.h>
using namespace std;

int N;
int pre_order[50];
int mid_order[50];
int post_order[50];

struct node
{
    int data;
    node *lchild;
    node *rchild;
};

node *create_tree(int preL, int preR, int midL, int midR)
{
    if (preL > preR)
    {
        return NULL;
    }
    node *root = new node;
    int root_idx = 0;
    root->data = pre_order[preL];
    for (int k = midL; k <= midR; k++)
    {
        if (mid_order[k] == pre_order[preL])
        {
            root_idx = k;
            break;
        }
    }
    int num_left = root_idx - midL;
    root->lchild = create_tree(preL + 1, preL + num_left, midL, root_idx - 1);
    root->rchild = create_tree(preL + num_left + 1, preR, root_idx + 1, midR);
    return root;
}
int num_output = 0;
void post_order_search(node *root)
{
    if (root == NULL)
    {
        return;
    }
    post_order_search(root->lchild);
    post_order_search(root->rchild);
    printf("%d", root->data);
    num_output++;
    if (num_output < N)
        printf(" ");
}

main()
{
    scanf("%d", &N);
    char op[5];
    int temp_num = 0;
    stack<int> sx;
    int idx = 0;
    int idx_1 = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        scanf("%s", &op);
        if (strcmp(op, "Pop") == 0)
        {
            mid_order[idx] = sx.top(); // 得到先序遍历
            sx.pop();
            idx++;
        }
        else
        {
            scanf("%d", &temp_num);
            pre_order[idx_1] = temp_num;
            idx_1++;
            sx.push(temp_num);
        }
    }

    node *root = create_tree(0, N - 1, 0, N - 1);
    post_order_search(root);
    // system("pause");
}
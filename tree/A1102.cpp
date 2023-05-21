#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int left = -1, right = -1;
    Node *left_node = NULL, *right_node = NULL, *root = NULL;
    int data;
} node[15];

void level_order(Node *root)
{
    queue<Node *> q; // 保存的是节点的地址
    cout << root->data;
    if (root->right_node != NULL)
        q.push(root->right_node);
    if (root->left_node != NULL)
        q.push(root->left_node);
    while (!q.empty())
    {
        Node *current = q.front();
        cout << " " << current->data;
        q.pop();
        if (current->right_node != NULL)
            q.push(current->right_node);
        if (current->left_node != NULL)
            q.push(current->left_node);
    }
    cout << endl;
}

vector<int> ans;

void in_order(Node *root)
{
    if (root == NULL)
        return;
    in_order(root->right_node);
    ans.push_back(root->data); // 右结束，保留结点
    in_order(root->left_node);
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        node[i].data = i;
        string left, right;
        cin >> left >> right;
        if (left != "-")
        {
            node[i].left = left[0] - '0';
            node[i].left_node = &node[node[i].left]; // 左子树
            node[node[i].left].root = &node[i];      // 左子树的根节点是现在的节点
        }
        if (right != "-")
        {
            node[i].right = right[0] - '0';
            node[i].right_node = &node[node[i].right]; // 右子树
            node[node[i].right].root = &node[i];       // 右子树的根节点是现在的节点
        }
    }
    Node *root;
    int root_idx = 0;
    for (int i = 0; i < N; i++)
    {
        if (node[i].root == NULL)
        {
            root = &node[i];
            root_idx = i;
            break;
        }
    }
    level_order(root);
    in_order(root);
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != ans.size() - 1)
            cout << ans[i] << " ";
        else
            cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}
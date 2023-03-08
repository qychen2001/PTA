#include <bits/stdc++.h>

#include <queue>

using namespace std;

struct Node {
  int data;
  Node *lchild = NULL;
  Node *rchild = NULL;
};
int N;
int num;
int post[35] = {0};
int in[45] = {0};

Node *generate_tree(int postL, int postR, int inL, int inR) {
  if (postL > postR) {
    return NULL;
  }
  Node *root = new Node;
  root->data = post[postR];  // 后续遍历的最后一个元素是当前子树的根
  int flag = 0;
  for (int k = inL; k <= inR; k++) {
    if (in[k] == post[postR]) {
      // 找到中序的根
      flag = k;
      break;
    }
  }

  int numLeft = flag - inL;

  root->lchild = generate_tree(postL, postL + numLeft - 1, inL, flag - 1);
  root->rchild = generate_tree(postL + numLeft, postR - 1, flag + 1, inR);

  return root;
}

void BFS(Node *root) {
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    Node *now = q.front();
    q.pop();
    printf("%d", now->data);
    num++;
    if (num < N) printf(" ");
    if (now->lchild != NULL) q.push(now->lchild);
    if (now->rchild != NULL) q.push(now->rchild);
  }
}

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &post[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &in[i]);
  }
  Node *root = generate_tree(0, N - 1, 0, N - 1);
  BFS(root);
  return 0;
}

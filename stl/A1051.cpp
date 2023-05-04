#include <bits/stdc++.h>
using namespace std;
int M, N, K;
int arr[1005];
int main()
{
    scanf("%d %d %d", &M, &N, &K);
    // M是栈的最大容量
    stack<int> test;
    for (int i = 0; i < K; i++)
    {
        // k个测试样例
        bool flag = true;
        while (not test.empty())
        {
            test.pop();
        }

        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[j]);
        }

        int current = 0;
        for (int cu = 1; cu <= N; cu++)
        {
            test.push(cu); // 进栈
            if (test.size() > M)
            {
                flag = false;
                break;
            }

            while (!test.empty() and test.top() == arr[current])
            {
                test.pop();
                current++;
            }
        }
        if (current == N and flag == true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    system("pause");
    return 0;
}
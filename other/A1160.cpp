#include <bits/stdc++.h>
using namespace std;

int get_sum(int a)
{
    int temp = a, sum = 0;
    while (temp != 0)
    {
        sum = sum + temp % 10;
        temp = temp / 10;
    }
    return sum;
}

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

bool is_prime(int a)
{
    bool result = true;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            result = false; // 可以被整除，那么就不是素数
            break;
        }
    }
    return result;
}

int main()
{
    int N, K, m; // k是位数
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int current_n_ans = 0;
        vector<int> v[100];
        scanf("%d %d", &K, &m);
        long long min_index = pow(10, K - 1) + 9;
        long long max_index = pow(10, K) - 1;
        for (int A = min_index; A <= max_index; A += 10)
        {
            if (get_sum(A) == m)
            {
                int n = get_sum(A + 1);
                int g_divisor = gcd(n, m);
                if (g_divisor > 2 and is_prime(g_divisor))
                    v[n].push_back(A);
            }
        }
        bool flag = false;
        printf("Case %d\n", i + 1);
        for (int k = 0; k < 90; k++)
        {
            for (int j = 0; j < v[k].size(); j++)
            {
                printf("%d %d\n", k, v[k][j]);
                flag = true;
            }
        }
        if (!flag)
            printf("No Solution\n");
    }
    system("pause");
}
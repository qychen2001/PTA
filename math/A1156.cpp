#include <bits/stdc++.h>
using namespace std;

bool is_prime(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    vector<int> prime;
    int N;
    scanf("%d", &N);
    if (is_prime(N) and is_prime(N - 6) and N > 6)
    {
        printf("Yes\n%d\n", N - 6);
    }
    else if (is_prime(N) and is_prime(N + 6))
    {
        printf("Yes\n%d\n", N + 6);
    }
    else
    {
        printf("No\n");
        for (int i = N + 1; i < pow(10, 8); i++)
        {
            if (is_prime(i - 6) and is_prime(i))
            {
                printf("%d\n", i);
                break;
            }
            else if (is_prime(i + 6) and is_prime(i))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    system("pause");
    return 0;
}
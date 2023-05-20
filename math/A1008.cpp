#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    int begin = 0;
    int next;
    int sum = 0;
    int diff;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &next);
        diff = next - begin;
        begin = next;
        if (diff > 0)
        {
            sum += diff * 6 + 5;
        }
        else
        {
            sum += diff * (-4) + 5;
        }
    }
    printf("%d", sum);
    return 0;
}
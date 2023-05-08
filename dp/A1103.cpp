#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K, P;
    scanf("%d %d %d", N, K, P);
    int temp[405];
    int index = 1;
    while (index ^ P < N)
    {
        temp[index] = index ^ P;
        index++;
    }

    
}
#include <bits/stdc++.h>
using namespace std;

bool is_prime(int a)
{
    bool flag = true;
    // 特判1和2
    if (a == 1)
        return false;
    if (a == 2)
        return true;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int generate_int(int *a, int num)
{
    int result = 0;
    for (int i = num; i < 8; i++)
    {
        result = result * 10 + a[i];
    }
    return result;
}

int main()
{
    bool all_prime = true;
    int a;
    cin >> a;
    int size = 8;
    int a_num[8];
    int tmp = a;
    for (int i = 0; i < 8; i++)
    {
        a_num[7 - i] = tmp % 10;
        tmp = tmp / 10;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = i; j < 8; j++)
            cout << a_num[j];
        if (is_prime(generate_int(a_num, i)))
        {
            cout << " Yes" << endl;
        }
        else
        {
            cout << " No" << endl;
            all_prime = false;
        }
    }
    if (all_prime)
        cout << "All Prime!" << endl;
    system("pause");
}
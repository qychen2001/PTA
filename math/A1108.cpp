#include <bits/stdc++.h>
using namespace std;

double is_legal(string a)
{
    double ans = 0;
    int num_point = 0;
    int minus = 1;
    // 先判断第一位
    if (a[0] >= '0' and a[0] <= '9')
    {
        ans = a[0] - '0';
    }
    else if (a[0] = '-')
    {
        minus = -1;
    }
    else
    {
        return 999999; // 这是非法数字
    }
    double b = 10;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] >= '0' and a[i] <= '9' and num_point == 0)
        {
            ans = ans * b + a[i] - '0';
        }
        else if (a[i] >= '0' and a[i] <= '9' and num_point == 1)
        {
            ans = ans + (a[i] - '0') * b;
            b /= 10;
        }
        else if (a[i] = '.' and num_point == 0)
        {
            num_point++;
            b = 0.1;
        }
        else
        {
            return 999999;
        }
    }
    if (b < 0.001)
        return 999999;
    else
        return ans * minus;
}

int main()
{
    int N;
    cin >> N;
    int num_ans = 0;
    double total = 0;
    string only_one;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        float temp_num = is_legal(temp);
        if (temp_num >= -1000 and temp_num <= 1000)
        {
            num_ans++;
            total += temp_num;
            only_one = temp;
        }
        else
        {
            cout << "ERROR: " << temp << " is not a legal number" << endl;
        }
    }
    if (num_ans == 0)
    {
        cout << "The average of 0 numbers is Undefined" << endl;
    }
    else if (num_ans > 1)
    {
        printf("The average of %d numbers is %.2f\n", num_ans, total / num_ans);
    }
    else
    {
        printf("The average of 1 number is %.2f\n", total); // 注意此处是number而不是numbers
    }

    system("pause");
}
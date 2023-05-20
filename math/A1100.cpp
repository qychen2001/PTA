#include <bits/stdc++.h>
using namespace std;

string mars1[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string mars2[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

void zh1(string s) // 将地球数字转化为火星文
{
    int n = 0, i;
    for (i = 0; i < s.size(); i++) // 求和
        n = n * 10 + s[i] - '0';

    int c2 = n % 13; // 个位
    int c1 = n / 13; // 十位
    string ans;
    if (c1 > 0 && c2 > 0)
        ans = mars1[c1 - 1] + " " + mars2[c2];
    else if (c1 > 0)
        ans = mars1[c1 - 1];
    else
        ans = mars2[c2];
    cout << ans << endl;
}

void zh2(string s) // 将火星文转化为地球数字
{
    int a = 0, b = 0, i;
    string s1, s2;
    if (s.size() < 5) // 火星文由一位数构成
    {
        for (i = 0; i < 13; i++)
            if (mars2[i] == s)
            {
                b = i;
                break;
            }
        if (i == 13) // 火星文只有十位数字
        {
            for (i = 0; i < 12; i++)
                if (mars1[i] == s)
                {
                    a = i;
                    break;
                }
            cout << (a + 1) * 13 << endl;
        }
        else // 火星文只有个位数字
        {
            cout << b << endl;
        }
    }
    else // 火星文由二位数构成
    {
        for (i = 0; s[i] != ' '; i++) // 求和
            s1.push_back(s[i]);
        for (i++; i < s.size(); i++) // 求和
            s2.push_back(s[i]);

        for (i = 0; i < 12; i++)
            if (mars1[i] == s1)
            {
                a = i;
                break;
            }
        for (i = 0; i < 13; i++)
            if (mars2[i] == s2)
            {
                b = i;
                break;
            }
        cout << (a + 1) * 13 + b << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string s;
    while (n--)
    {
        getline(cin, s); // 输入

        if (isdigit(s[0])) // 是地球文
            zh1(s);        // 地球文转化为火星文
        else               // 是火星文
            zh2(s);        // 火星文转化为地球文
    }

    return 0;
}
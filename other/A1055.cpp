#include <bits/stdc++.h>
using namespace std;
struct Info
{
    string name;
    int year;
    int money;
} info[100005];
map<int, string> year_name;

bool cmp(Info a, Info b)
{
    if (a.money != b.money)
    {
        return a.money > b.money;
    }
    else
    // 钱一样多
    {
        if (a.year != b.year)
        {
            return a.year < b.year;
        }
        else
        {
            return a.name < b.name;
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> info[i].name >> info[i].year >> info[i].money;
    }
    int num, min_age, max_age;
    sort(info, info + N, cmp);
    for (int i = 0; i < M; i++)
    {
        int temp_num = 0; // 输出个数
        cin >> num >> min_age >> max_age;
        cout << "Case #" << i + 1 << ":" << endl;
        for (int j = 0; j < N; j++)
        {
            if (info[j].year >= min_age and info[j].year <= max_age)
            {
                cout << info[j].name << " " << info[j].year << " " << info[j].money << endl;
                temp_num++;
            }
            if (temp_num == num)
            {
                break;
            }
        }
        if (temp_num == 0)
        {
            cout << "None" << endl;
        }
    }
    system("pause");
    return 0;
}
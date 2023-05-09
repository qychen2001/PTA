#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int height;
    string name;
} stu[10005];

bool cmp(Student a, Student b)
{
    if (a.height == b.height)
    {
        return a.name > b.name;
    }
    else
    {
        return a.height < b.height;
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> stu[i].name >> stu[i].height;
    }
    sort(stu, stu + N, cmp);
    int num_each = N / K;
    int num_last = N - (N / K) * (K - 1); // 每排人数和最后一排人数
    string name_list[10005];
    for (int p = K - 1; p >= 0; p--)
    {
        // 第k排
        if (p != K - 1)
        {
            int center = (num_each / 2); // 编号从0开始，所以需要减一
            name_list[p * num_each + center] = stu[(p + 1) * num_each - 1].name;
            for (int i = 1; i <= center; i++)
            {
                if (center - i >= 0)
                    name_list[p * num_each + center - i] = stu[(p + 1) * num_each - (2 * i)].name;
                // cout << p << stu[(p + 1) * num_each - (2 * i)].name << (p + 1) * num_each - (2 * i);
                if ((p + 1) * num_each - (2 * i) - 1 >= 0)
                    name_list[p * num_each + center + i] = stu[(p + 1) * num_each - (2 * i) - 1].name;
            }
            for (int i = (p * num_each); i < ((p + 1) * num_each); i++)
            {
                if (i != ((p + 1) * num_each - 1))
                    cout << name_list[i] << " ";
                else
                    cout << name_list[i] << endl;
            }
        }
        else
        {
            int center = (num_last / 2); // 编号从0开始，所以需要减一
            name_list[p * num_each + center] = stu[N - 1].name;
            for (int i = 1; i <= center; i++)
            {
                if (center - i >= 0)
                    name_list[p * num_each + center - i] = stu[N - 2 * i].name;
                if (N - 2 * i - 1 >= 0)
                    name_list[p * num_each + center + i] = stu[N - 2 * i - 1].name;
            }
            for (int i = p * num_each; i < N; i++)
            {
                if (i != (N - 1))
                    cout << name_list[i] << " ";
                else
                    cout << name_list[i] << endl;
            }
            // cout << "finish last line";
        }
    }
    system("pause");
    return 0;
}
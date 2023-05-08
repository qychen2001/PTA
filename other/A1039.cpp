#include <bits/stdc++.h>
using namespace std;

map<string, vector<int>> stu_course;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int current_class, current_num;
    string temp_name;
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d", &current_class, &current_num);
        for (int j = 0; j < current_num; j++)
        {
            cin >> temp_name;
            stu_course[temp_name].push_back(current_class);
        }
    }
    // cout << "read success";
    for (int i = 0; i < N; i++)
    {
        cin >> temp_name;
        int c_size = stu_course[temp_name].size();
        cout << temp_name << " " << c_size;
        sort(stu_course[temp_name].begin(), stu_course[temp_name].end());
        for (int j = 0; j < stu_course[temp_name].size(); j++)
        {
            cout << " " << stu_course[temp_name][j];
        }
        cout << endl;
    }
    system("pause");
}

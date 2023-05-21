#include <bits/stdc++.h>
using namespace std;
vector<string> class_name[3005];
bool cmp(string a, string b)
{
    return a < b;
}
int main()
{
    int num_stu, num_class;
    // cin >> num_stu >> num_class;
    scanf("%d %d", &num_stu, &num_class);
    for (int i = 0; i < num_stu; i++)
    {
        int n, tmp_class;
        string tmp_name;
        cin >> tmp_name >> n;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &tmp_class);
            class_name[tmp_class].push_back(tmp_name);
        }
    }
    for (int i = 1; i <= num_class; i++)
    {
        cout << i << " " << class_name[i].size() << endl;
        sort(class_name[i].begin(), class_name[i].end(), cmp);
        for (int j = 0; j < class_name[i].size(); j++)
        {
            printf("%s\n", (class_name[i][j]).c_str()); // 换用printf而不是cout，cout太慢
        }
    }
}
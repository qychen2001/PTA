#include <bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    string id;
    int score;
} M, F, temp;
int main()
{
    M.score = 101;
    F.score = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char gender;
        cin >> temp.name >> gender >> temp.id >> temp.score;
        if (gender == 'M' and temp.score < M.score)
        {
            M = temp;
        }
        else if (gender == 'F' and temp.score > F.score)
        {
            F = temp;
        }
    }
    if (F.score == -1)
        cout << "Absent" << endl;
    else
    {
        cout << F.name << " " << F.id << endl;
    }
    if (M.score == 101)
        cout << "Absent" << endl;
    else
    {
        cout << M.name << " " << M.id << endl;
    }
    if (F.score == -1 or M.score == 101)
    {
        cout << "NA" << endl;
    }
    else
    {
        cout << F.score - M.score << endl;
    }
}
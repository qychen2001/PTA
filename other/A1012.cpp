#include <bits/stdc++.h>
using namespace std;
int N, M;
struct student
{
    int id;
    int C, M, E, A;
    int C_rank, M_rank, E_rank, A_rank;
    int max_rank;
    char max_item;
} stu[2005];

bool cmp_A(student a, student b) { return a.A > b.A; }
bool cmp_C(student a, student b) { return a.C > b.C; }
bool cmp_M(student a, student b) { return a.M > b.M; }
bool cmp_E(student a, student b) { return a.E > b.E; }
int id_index_map[1000007];
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> stu[i].id >> stu[i].C >> stu[i].M >> stu[i].E;
        stu[i].A = (stu[i].C + stu[i].M + stu[i].E) / 3 + 0.5;
    }
    sort(stu, stu + N, cmp_A);
    stu[0].A_rank = 1;
    for (int i = 1; i < N; i++)
    {
        if (stu[i].A == stu[i - 1].A)
            stu[i].A_rank = stu[i - 1].A_rank;
        else
            stu[i].A_rank = i + 1;
    }

    sort(stu, stu + N, cmp_C);
    stu[0].C_rank = 1;
    for (int i = 1; i < N; i++)
    {
        if (stu[i].C == stu[i - 1].C)
            stu[i].C_rank = stu[i - 1].C_rank;
        else
            stu[i].C_rank = i + 1;
    }

    sort(stu, stu + N, cmp_M);
    stu[0].M_rank = 1;
    for (int i = 1; i < N; i++)
    {
        if (stu[i].M == stu[i - 1].M)
            stu[i].M_rank = stu[i - 1].M_rank;
        else
            stu[i].M_rank = i + 1;
    }

    sort(stu, stu + N, cmp_E);
    stu[0].E_rank = 1;
    for (int i = 1; i < N; i++)
    {
        if (stu[i].E == stu[i - 1].E)
            stu[i].E_rank = stu[i - 1].E_rank;
        else
            stu[i].E_rank = i + 1;
    }

    for (int i = 0; i < N; i++)
    {
        if (stu[i].A_rank <= stu[i].C_rank and stu[i].A_rank <= stu[i].M_rank and stu[i].A_rank <= stu[i].E_rank)
        {
            stu[i].max_rank = stu[i].A_rank;
            stu[i].max_item = 'A';
        }
        else if (stu[i].C_rank <= stu[i].M_rank and stu[i].C_rank <= stu[i].E_rank)
        {
            stu[i].max_rank = stu[i].C_rank;
            stu[i].max_item = 'C';
        }
        else if (stu[i].M_rank <= stu[i].E_rank)
        {
            stu[i].max_rank = stu[i].M_rank;
            stu[i].max_item = 'M';
        }
        else
        {
            stu[i].max_rank = stu[i].E_rank;
            stu[i].max_item = 'E';
        }
    }
    memset(id_index_map, -1, sizeof(id_index_map));
    for (int i = 0; i < N; i++)
    {
        id_index_map[stu[i].id] = i;
    }
    int tmp;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        int id = id_index_map[tmp];
        if (id != -1)
        {
            cout << stu[id].max_rank << " " << stu[id].max_item << endl;
        }
        else
        {
            cout << "N/A" << endl;
        }
    }
    system("pause");
    return 0;
}
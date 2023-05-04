#include <bits/stdc++.h>
using namespace std;
int rate[25];
struct records
{
    char name[23];
    char status[15];
    int month[1005];
    int day[1005];
    int hour[1005];
    int minute[1005];
} rec[1005];

int main()
{
    for (int i = 1; i < 25; i++)
    {
        scanf("%d", &rate[i]); // 读入每个时段的费用
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%s", &rec[i].name);
        scanf("%2d:%2d:%2d:%2d", &rec[i].month, &rec[i].day, &rec[i].hour, &rec[i].minute);
        printf("%2d", rec[i].month);
        scanf("%s", &rec[i].status);
    }

    for (int i = 0; i < k; i++)
    {
        printf("%s %02d:%02d:%02d:%02d %s\n", rec[i].name, rec[i].month, rec[i].day, rec[i].hour, rec[i].minute, rec[i].status);
    }
    system("pause");
    return 0;
}
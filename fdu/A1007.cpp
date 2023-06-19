#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int a[maxn];
int dp[maxn];
int main()
{
	int n;
	bool all_negative = true;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] >= 0)
		{
			// must >= 0
			all_negative = false;
		}
	}
	if (all_negative)
	{
		printf("0 %d %d", a[0], a[n - 1]);
		return 0;
	}
	dp[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(a[i], dp[i - 1] + a[i]);
	}

	int k = 0;
	for (int i = 1; i < n; i++)
	{
		if (dp[i] > dp[k])
		{
			k = i;
		}
	}
	int tmp = dp[k];
	int start = k;
	for (int j = k; j >= 0; j--)
	{
		tmp -= a[j];
		if (tmp == 0)
		{
			start = j;
			break;
		}
	}
	printf("%d %d %d\n", dp[k], a[start], a[k]);
	return 0;
}

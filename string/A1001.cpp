#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
  ll a, b;
  scanf("%lld%lld", &a, &b);
  string result = to_string((a + b));
  if (a + b < 0) {
    result.erase(0, 1);
    cout << "-";
  }
  int s = result.size();
  for (int i = 0; i < s; ++i) {
    if ((s - i) % 3 == 0 and i != 0) cout << ",";
    cout << result[i];
  }
  cout << endl;
  return 0;
}
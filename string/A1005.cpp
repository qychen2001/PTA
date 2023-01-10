#include <bits/stdc++.h>
using namespace std;

string table[10] = {"zero", "one", "two",   "three", "four",
                    "five", "six", "seven", "eight", "nine"};
int array[105];
int main() {
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 0; i < s.size(); i++) sum = sum + s[i] - '0';
  string sum_s = to_string(sum);
  for (int i = 0; i < sum_s.size(); i++) {
    if (i != sum_s.size() - 1) {
      cout << table[sum_s[i] - '0'] << " ";
    } else {
      cout << table[sum_s[i] - '0'] << endl;
    }
  }
  return 0;
}
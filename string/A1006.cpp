#include <bits/stdc++.h>
using namespace std;

struct student {
  string id;
  string sign_in;
  string sign_out;
};

bool cmp(string a_time, string b_time) {
  string a_h = a_time.substr(0, 2);
  string a_m = a_time.substr(3, 2);
  string a_s = a_time.substr(7, 2);
  string b_h = b_time.substr(0, 2);
  string b_m = b_time.substr(3, 2);
  string b_s = b_time.substr(7, 2);
  if (a_h != b_h)
    return a_h > b_h;
  else {
    if (a_m != b_m)
      return a_m > b_m;
    else
      return a_s > b_s;
  }
}

int main() {
  int m;
  scanf("%d", &m);
  student stu[m + 5];
  int sign_in_idx = 0;
  int sign_out_idx = 0;
  for (int i = 0; i < m; i++) {
    cin >> stu[i].id >> stu[i].sign_in >> stu[i].sign_out;
    if (cmp(stu[i].sign_out, stu[sign_out_idx].sign_out) == true)
      sign_out_idx = i;

    if (cmp(stu[i].sign_in, stu[sign_in_idx].sign_in) == false) sign_in_idx = i;
  }
  cout << stu[sign_in_idx].id << " " << stu[sign_out_idx].id << endl;
  return 0;
}

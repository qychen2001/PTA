#include <bits/stdc++.h>
using namespace std;
float pa[1005];
float pb[1005];
float pfinal[1005];
int main() {
  char s;
  int ka = 0;
  int kb = 0;
  scanf("%d", &ka);
  int index, index_max = 0;
  float num;
  for (int i = 0; i < ka; ++i) {
    scanf("%d%f", &index, &num);
    pa[index] = num;
    if (index > index_max) index_max = index;
  }
  scanf("%d", &kb);
  for (int i = 0; i < kb; ++i) {
    scanf("%d%f", &index, &num);
    pb[index] = num;
    if (index > index_max) index_max = index;
  }
  // 读入完成
  string result;
  int num_result = 0;
  for (int j = 0; j <= index_max; j++) {
    pfinal[j] = pa[j] + pb[j];
    if (pfinal[j] != 0) {
      num_result++;
    }
  }
  printf("%d", num_result);
  for (int j = index_max; j >= 0; j--) {
    if (pfinal[j] != 0) {
      printf(" %d %.1f", j, pfinal[j]);
    }
  }
  return 0;
}
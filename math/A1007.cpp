#include <bits/stdc++.h>
using namespace std;
/*思路：只要当前序列的和不小于0，那么加上一个大于0的数，总会变得更大
 */
int main() {
  int k;
  scanf("%d", &k);
  int A[100005];
  for (int i = 0; i < k; i++) scanf("%d", &A[i]);
  int tmp_sum = 0, max_sum = -100000;
  int start = 0, end = k - 1, tmp = 0;
  // tmp是暂时的开始位置
  for (int i = 0; i < k; i++) {
    tmp_sum += A[i];
    if (tmp_sum >= 0) {
      /*
      此处需要>=，如果只使用=测试点5会不通过，原因是可能存在和为0的情况
      例如：
      5
      -1 0 -1 -1 -1 -1
      输出应该为 0 0 0
      */
      if (tmp_sum > max_sum) {
        max_sum = tmp_sum;
        end = i;
        start = tmp;
      }
    } else {
      tmp = i + 1;  // 开始位置应该是下一个
      tmp_sum = 0;
    }
  }
  if (max_sum < 0) {
    max_sum = 0;
    end = k - 1;
    start = 0;
  }  // 不确定逻辑，最后检查一遍
  printf("%d %d %d\n", max_sum, A[start], A[end]);
}
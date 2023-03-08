#include <math.h>
#include <stdio.h>

int main() {
  float a, b, c, p, disc, q, x1, x2;
  scanf("%f%f%f", &a, &b, &c);
  p = -b / (2 * a);
  disc = b * b - 4 * a * c;
  q = sqrt(disc) / (2 * a);
  x1 = p + q;
  x2 = p - q;
  printf("%f%f", x1, x2);
  return 0;
}
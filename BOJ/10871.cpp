#include <iostream>

using namespace std;

int main() {
  int n, x;
  int temp;

  scanf("%d %d", &n, &x);

  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    if (temp < x) printf("%d ", temp);
  }
  return 0;
}
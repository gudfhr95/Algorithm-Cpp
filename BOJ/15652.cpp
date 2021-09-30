#include <iostream>

using namespace std;

bool c[10];
int a[10];

void permutation(int index, int n, int m) {
  if (index == m) {
    for (int i = 0; i < m; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    c[i] = true;

    if (index > 0 && a[index - 1] > i) continue;

    a[index] = i;
    permutation(index + 1, n, m);
    c[i] = false;
  }
}

int main() {
  int N, M;

  cin >> N >> M;

  permutation(0, N, M);
}
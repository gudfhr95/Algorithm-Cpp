#include <iostream>
#include <vector>

using namespace std;

vector<int> preprocessing(string p) {
  int m = p.size();

  vector<int> pi(m);
  pi[0] = 0;

  int j = 0;
  for (int i = 1; i < m; i++) {
    while (j > 0 && p[i] != p[j]) {
      j = pi[j - 1];
    }

    if (p[i] == p[j]) {
      pi[i] = j + 1;
      j += 1;
    } else {
      pi[i] = 0;
    }
  }

  return pi;
}

vector<int> kmp(string s, string p) {
  auto pi = preprocessing(p);

  vector<int> result;

  int n = s.size();
  int m = p.size();
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j > 0 && s[i] != p[j]) {
      j = pi[j - 1];
    }
    if (s[i] == p[j]) {
      if (j == m - 1) {
        result.push_back(i - m + 1);
        j = pi[j];
      } else {
        j += 1;
      }
    }
  }

  return result;
}

int main() {
  string T, P;

  getline(cin, T);
  getline(cin, P);

  auto result = kmp(T, P);

  cout << result.size() << '\n';
  for (int idx : result) {
    cout << idx + 1 << '\n';
  }
}
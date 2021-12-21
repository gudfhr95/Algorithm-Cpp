#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int children[26];
  bool valid;

  Node() {
    for (int i = 0; i < 26; i++) {
      children[i] = -1;
    }

    valid = false;
  }
};

vector<Node> trie;
int root;

int init() {
  Node x;
  trie.push_back(x);
  return (int)trie.size() - 1;
}

void add(int node, string &s, int index) {
  if (index == s.size()) {
    trie[node].valid = true;
    return;
  }

  int c = s[index] - 'a';
  if (trie[node].children[c] == -1) {
    int next = init();
    trie[node].children[c] = next;
  }

  int child = trie[node].children[c];
  add(child, s, index + 1);
}

bool search(int node, string &s, int index) {
  if (node == -1) return false;

  if (index == s.length()) return trie[node].valid;

  int c = s[index] - 'a';
  int child = trie[node].children[c];

  return search(child, s, index + 1);
}

int main() {
  int N, M;

  cin >> N >> M;

  string s;

  root = init();
  for (int i = 0; i < N; i++) {
    cin >> s;

    add(root, s, 0);
  }

  int result = 0;
  for (int i = 0; i < M; i++) {
    cin >> s;

    if (search(root, s, 0)) {
      result++;
    }
  }

  cout << result;
}
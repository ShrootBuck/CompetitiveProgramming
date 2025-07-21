#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<int> a(N);
  vector<int> cow_id(N);

  for (int i = 0; i < N; i++) {
    cin >> a[i];
    cow_id[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    cin >> cow_id[a[i] - 1];
  }

  for (int id : cow_id) {
    cout << id << "\n";
  }
}

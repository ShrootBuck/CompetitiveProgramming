

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  long long sum = n * (n + 1) / 2;

  // Handle NO (Gauss's childhood formula)
  if (sum % 2 != 0) {
    cout << "NO";
    return 0;
  }

  long long max_per_set = sum / 2;

  vector<long long> setA;
  vector<long long> setB;
  long long sumA = 0;

  // Anything at this point must be YES
  // Greedy systematic fill
  for (long long k = n; k >= 1; k--) {
    if (max_per_set - sumA >= k) {
      setA.push_back(k);
      sumA += k;
    } else {
      setB.push_back(k);
    }
  }

  const char *separator = "";

  cout << "YES\n";
  cout << setA.size() << "\n";
  for (int item : setA) {
    cout << separator << item;
    separator = " ";
  }

  separator = "";

  cout << "\n" << setB.size() << "\n";
  for (int item : setB) {
    cout << separator << item;
    separator = " ";
  }
}

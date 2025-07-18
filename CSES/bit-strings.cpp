int main() {
  int n;
  long long result = 1;
  long long mod_constraint = 1000000007;
  cin >> n;

  for (int i = 0; i < n; i++) {
    result = result * 2 % mod_constraint;
  }

  cout << result;
}

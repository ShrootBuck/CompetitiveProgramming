#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> solve(int n) {
    if (n == 1) {
        return {"0", "1"};
    }

    vector<string> a = solve(n - 1);
    vector<string> b = a;
    reverse(b.begin(), b.end());

    for (int i = 0; i < a.size(); i++) {
        a[i] = "0" + a[i];
        b[i] = "1" + b[i];
    }

    a.insert(a.end(), b.begin(), b.end());

    return a;
}

int main() {
    int n;
    cin >> n;

    auto result = solve(n);

    for (string code : result) {
        cout << code << "\n";
    }
}

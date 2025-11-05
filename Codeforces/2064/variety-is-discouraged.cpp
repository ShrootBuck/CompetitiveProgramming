#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ll long long

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> freq(n + 1);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        a[i] = num;
        freq[num]++;
    }

    // Prefix sum of sub-lengths
    vector<int> len(n + 1);
    len[0] = freq[a[0]] == 1;

    for (int i = 1; i < n; i++) {
        if (freq[a[i]] == 1) {
            len[i] = len[i - 1] + 1;
        }
    }

    int biggest_run = *max_element(len.begin(), len.end());
    if (biggest_run == 0) {
        cout << "0";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (len[i] == biggest_run) {
            cout << (i + 1) - (len[i] - 1) << " " << i + 1;
            return;
        }
    }
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}

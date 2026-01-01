#include <bits/stdc++.h>

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

int main() {
    setIO();

    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> b(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < N; i++) {
        cin >> b[i];
        b[i]--;
    }

    vector<bool> marked(N, false);
    int shift = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        while (shift < N && marked[a[shift]]) {
            shift++;
        }

        if (a[shift] == b[i]) {
            shift++;
        } else {
            ans++;
            marked[b[i]] = true;
        }
    }

    cout << ans;
}

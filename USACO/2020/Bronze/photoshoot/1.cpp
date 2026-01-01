#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#ifdef LOCAL_RUN
    else {
        freopen("f.in", "r", stdin);
        freopen("f.out", "w", stdout);
    }
#endif
}

int main() {
    setIO("photo");

    ll N;
    cin >> N;

    vector<int> a(N);
    iota(a.begin(), a.end(), 1);

    vector<int> b(N - 1);
    for (int i = 0; i < N - 1; i++)
        cin >> b[i];

    auto check = [&]() {
        for (int i = 0; i < N - 1; i++) {
            if (a[i] + a[i + 1] != b[i]) {
                return false;
            }
        }

        return true;
    };

    do {
        if (check()) {
            for (int i = 0; i < N; i++) {
                cout << a[i] << (i != N - 1 ? " " : "");
            }

            break;
        }
    } while (next_permutation(a.begin(), a.end()));
}

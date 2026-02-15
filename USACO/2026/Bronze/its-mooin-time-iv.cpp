#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ZK_LOCAL_RUN
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
#else
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#endif
}

int main() {
    setIO();

    int T, k;
    cin >> T >> k;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        cout << "YES\n";
        if (k == 0)
            continue;

        vector<char> moo(N, ' ');
        bool flip = false;

        for (int i = N - 1; i >= 0; i--) {
            char c = S[i];
            if (flip)
                c = (c == 'M' ? 'O' : 'M');
            moo[i] = c;

            if (c == 'O')
                flip = !flip;
        }

        for (char c : moo)
            cout << c;
        cout << '\n';
    }
}

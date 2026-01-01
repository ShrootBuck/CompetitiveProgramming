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
    setIO("gymnastics");

    ll K, N;
    cin >> K >> N;

    vector<vector<ll>> sessions(K, vector<ll>(N));
    for (ll i = 0; i < K; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> sessions[i][j];
        }
    }

    ll consistent = 0;

    for (ll i = 1; i <= N - 1; i++) {
        for (ll j = i + 1; j <= N; j++) {
            bool consistency = find(sessions[0].begin(), sessions[0].end(), i) <
                               find(sessions[0].begin(), sessions[0].end(), j);
            bool valid = true;
            for (auto& session : sessions) {
                bool local_consistency = find(session.begin(), session.end(), i) <
                                         find(session.begin(), session.end(), j);
                if (local_consistency != consistency) {
                    valid = false;
                }
            }
            consistent += valid;
        }
    }

    cout << consistent;
}

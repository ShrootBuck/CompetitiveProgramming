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
    setIO("moop");

    int N;
    cin >> N;
    vector<pair<int, int>> particles(N);
    for (auto& particle : particles)
        cin >> particle.first >> particle.second;
    sort(particles.begin(), particles.end());

    vector<int> suffix_max_y(N);
    suffix_max_y[N - 1] = particles[N - 1].second;
    for (int i = N - 2; i >= 0; i--)
        suffix_max_y[i] = max(suffix_max_y[i + 1], particles[i].second);

    int ans = 1, min_so_far = INT_MAX;
    for (int i = 0; i < N - 1; i++) {
        min_so_far = min(min_so_far, particles[i].second);
        if (min_so_far > suffix_max_y[i + 1])
            ans++;
    }

    cout << ans;
}

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

int solve() {
    int N;
    cin >> N;

    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    int biggest = h.back();
    h.pop_back();

    map<int, int> count;
    for (int i = 0; i < h.size(); i++) {
        count[h[i]]++;
    }

    int ans = 1;

    for (auto& [height, freq] : count) {
        if (freq >= 2 && height != biggest) {
            ans += 2;
        }
    }

    return ans;
}

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        cout << solve() << "\n";
    }
}

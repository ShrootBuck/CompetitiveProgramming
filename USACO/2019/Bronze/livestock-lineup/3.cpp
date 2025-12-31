#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using ll = long long;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#ifdef ZK_LOCAL_RUN
    else {
        freopen("f.in", "r", stdin);
        freopen("f.out", "w", stdout);
    }
#endif
}

vector<string> cows{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

bool verify_order(const vector<pair<string, string>>& requirements) {
    bool valid = true;
    for (auto& requirement : requirements) {
        bool found = false;
        for (ll i = 0; i < cows.size() - 1; i++) {
            const auto& cow1 = cows[i];
            const auto& cow2 = cows[i + 1];

            if ((cow1 == requirement.first && cow2 == requirement.second) ||
                (cow1 == requirement.second && cow2 == requirement.first)) {
                found = true;
            }
        }

        if (!found) {
            valid = false;
        }
    }

    if (valid) {
        for (auto& cow : cows) {
            cout << cow << "\n";
        }
        return true;
    } else {
        return false;
    }
}

int main() {
    setIO("lineup");

    ll N;
    cin >> N;

    sort(cows.begin(), cows.end());

    vector<pair<string, string>> requirements(N);
    for (ll i = 0; i < N; i++) {
        string s;
        cin >> requirements[i].first >> s >> s >> s >> s >> requirements[i].second;
    }

    do {
        if (verify_order(requirements)) {
            return 0;
        }
    } while (next_permutation(cows.begin(), cows.end()));
}

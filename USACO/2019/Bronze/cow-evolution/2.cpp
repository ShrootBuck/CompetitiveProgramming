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
    setIO("evolution");

    int N;
    cin >> N;

    set<string> features;
    set<set<string>> populations;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        set<string> population;
        for (int j = 0; j < K; j++) {
            string s;
            cin >> s;
            population.insert(s);
            features.insert(s);
        }

        populations.insert(population);
    }

    for (const string& feature : features) {
        for (auto& p1 : populations) {
            for (auto& p2 : populations) {
                if (p1.count(feature) == 0 || p2.count(feature) == 0) {
                    break;
                }

                if (p1.size() == p2.size()) {
                    cout << "no";
                    return 0;
                }
            }
        }
    }

    cout << "yes";
}

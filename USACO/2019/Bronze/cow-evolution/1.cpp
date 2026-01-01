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

    set<string> distinct;
    vector<set<string>> sub_populations(N);

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        for (int j = 0; j < K; j++) {
            string s;
            cin >> s;

            sub_populations[i].insert(s);
            distinct.insert(s);
        }
    }

    for (int i = 0; i < distinct.size() - 1; i++) {
        for (int j = i + 1; j < distinct.size(); j++) {
            string a = *next(distinct.begin(), i);
            string b = *next(distinct.begin(), j);

            bool a_not_b = false, b_not_a = false, both = false;

            for (auto& sub : sub_populations) {
                if (sub.count(a)) {
                    if (sub.count(b)) {
                        both = true;
                    } else {
                        a_not_b = true;
                    }
                } else if (sub.count(b)) {
                    b_not_a = true;
                }
            }

            if (a_not_b && b_not_a && both) {
                cout << "no";
                return 0;
            }
        }
    }

    cout << "yes";
}

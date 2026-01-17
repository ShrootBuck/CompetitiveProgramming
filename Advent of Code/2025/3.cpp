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
    setIO();

    vector<string> lines;
    string line;
    while (cin >> line) {
        lines.push_back(line);
    }

    ll sum = 0;
    for (const string& s : lines) {
        int local_max = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            for (int j = i + 1; j < s.size(); j++) {
                local_max = max(local_max, (s[i] - '0') * 10 + (s[j] - '0'));
            }
        }

        sum += local_max;
    }

    cout << "Part 1:\t" << sum << "\n";

    sum = 0;
    constexpr ll M = 12;

    for (const string& s : lines) {
        string num = "";
        ll current = 0;
        while (num.size() < M) {
            ll max_digit = 0;

            for (ll i = current; i <= s.size() - (M - num.size()); i++) {
                if (s[i] - '0' > max_digit) {
                    max_digit = s[i] - '0';
                    current = i + 1;
                }
            }

            num += to_string(max_digit);
        }

        sum += stoll(num);
    }

    cout << "Part 2:\t" << sum;
}

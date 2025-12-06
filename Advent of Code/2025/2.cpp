#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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
    setIO("f");

    string input;
    cin >> input;

    vector<pair<ll, ll>> ranges;

    stringstream ss(input);
    string range;
    while (getline(ss, range, ',')) {
        size_t dashPos = range.find('-');
        ll left = stoll(range.substr(0, dashPos));
        ll right = stoll(range.substr(dashPos + 1));
        ranges.push_back({left, right});
    }

    ll sum = 0;

    for (auto& r : ranges) {
        ll left = r.first;
        ll right = r.second;

        for (ll i = left; i <= right; i++) {
            string s = to_string(i);
            bool ok = true;

            if (s.size() % 2 != 0) {
                continue;
            }

            for (ll j = 0; j < s.size() / 2; j++) {
                if (s[j] != s[j + s.size() / 2]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                sum += i;
            }
        }
    }

    cout << "Part 1:\t" << sum << "\n";

    sum = 0;

    for (auto& r : ranges) {
        ll left = r.first;
        ll right = r.second;

        for (ll i = left; i <= right; i++) {
            string s = to_string(i);
            for (ll step = 1; step <= s.size() / 2; step++) {
                if (s.size() % step != 0) {
                    continue;
                }

                bool ok = true;
                for (ll j = 0; j < s.size(); j++) {
                    if (s[j] != s[j % step]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    sum += i;
                    break;
                }
            }
        }
    }
    cout << "Part 2:\t" << sum;
}

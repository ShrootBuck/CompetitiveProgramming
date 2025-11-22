#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
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
    setIO();

    string S;
    cin >> S;

    vector<pair<int, int>> segments;

    int last = S[0] - '0';
    int count = 1;

    for (int i = 1; i < S.size(); i++) {
        int current = S[i] - '0';
        if (current == last) {
            count++;
        } else {
            segments.push_back({last, count});
            count = 1;
        }

        last = current;
    }

    // Final block!
    segments.push_back({last, count});

    ll ans = 0;
    for (int i = 0; i < segments.size() - 1; i++) {
        int digit1 = segments[i].first, digit2 = segments[i + 1].first;
        int length1 = segments[i].second, length2 = segments[i + 1].second;

        if (digit2 - digit1 == 1) {
            ans += min(length1, length2);
        }
    }

    cout << ans;
}

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

    int n;
    string s;
    cin >> n >> s;

    unordered_set<char> unique_chars;
    for (int i = 0; i < n; i++)
        unique_chars.insert(s[i]);

    int left = 0, longest = n;
    map<char, int> freq;
    for (int right = 0; right < n; right++) {
        freq[s[right]]++;
        while (freq.size() == unique_chars.size()) {
            longest = min(longest, right - left + 1);

            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);

            left++;
        }
    }

    cout << longest;
}

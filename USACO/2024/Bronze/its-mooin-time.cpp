#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
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

void find_moos(const string& s, int F, set<string>& possible_moos) {
    map<string, int> counts;
    for (int i = 0; i < s.length() - 2; i++) {
        if (s[i] != s[i + 1] && s[i + 1] == s[i + 2]) {
            counts[s.substr(i, 3)]++;
        }
    }

    for (const auto& pair : counts) {
        if (pair.second >= F) {
            possible_moos.insert(pair.first);
        }
    }
}

int main() {
    setIO("");

    int N, F;
    cin >> N >> F;

    string contest;
    cin >> contest;

    set<string> possible_moos;

    find_moos(contest, F, possible_moos);

    for (int i = 0; i < N; i++) {
        char original_char = contest[i];

        for (char c = 'a'; c <= 'z'; c++) { // C++!?
            if (c == original_char) {
                continue;
            }

            string temp_contest = contest;
            temp_contest[i] = c;
            find_moos(temp_contest, F, possible_moos);
        }
    }

    cout << possible_moos.size();

    for (const auto& moo : possible_moos) {
        cout << "\n" << moo;
    }
}
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>
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

    string s;
    cin >> s;
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'y'};

    for (auto& c : s) {
        c = tolower(c);

        if (vowels.count(c) == 0) {
            cout << '.' << c;
        }
    }
}

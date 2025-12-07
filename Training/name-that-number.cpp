/*
ID: zayd1
LANG: C++
TASK: namenum
*/

#include <cstdio>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
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

string input;
set<string> dict;

bool none = true;

unordered_map<char, vector<char>> touchpad = {
    {'2', {'A', 'B', 'C'}}, {'3', {'D', 'E', 'F'}}, {'4', {'G', 'H', 'I'}}, {'5', {'J', 'K', 'L'}},
    {'6', {'M', 'N', 'O'}}, {'7', {'P', 'R', 'S'}}, {'8', {'T', 'U', 'V'}}, {'9', {'W', 'X', 'Y'}}};

void solve(string name) {
    if (name.size() == input.size()) {
        if (dict.count(name)) {
            cout << name << "\n";
            none = false;
        }

        return;
    }

    for (int i = 0; i < 3; i++) {
        solve(name + touchpad[input[name.size()]][i]);
    }
}

int main() {
    setIO("namenum");

    ifstream dict_io("dict.txt");
    while (dict_io >> input) {
        dict.insert(input);
    }

    cin >> input;

    solve("");

    if (none) {
        cout << "NONE\n";
    }
}

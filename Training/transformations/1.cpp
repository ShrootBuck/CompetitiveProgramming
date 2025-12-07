/*
ID: zayd1
LANG: C++
TASK: transform
*/

#include <cstdio>
#include <iostream>
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

vector<vector<bool>> rotate_90(vector<vector<bool>> start) {
    auto result = start;

    for (int i = 0; i < start.size(); i++) {
        for (int j = 0; j < start.size(); j++) {
            result[i][j] = start[start.size() - j - 1][i];
        }
    }

    return result;
}

int main() {
    setIO("transform");

    int N;
    cin >> N;

    vector<vector<bool>> original(N, vector<bool>(N)), target(N, vector<bool>(N));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            char ch;
            cin >> ch;
            original[r][c] = ch == '@';
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            char ch;
            cin >> ch;
            target[r][c] = ch == '@';
        }
    }

    auto temp = original;

    for (int attempt = 1; attempt <= 3; attempt++) {
        temp = rotate_90(temp);
        if (temp == target) {
            cout << attempt << "\n";
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = original[i][N - j - 1];
        }
    }

    if (temp == target) {
        cout << "4\n";
        return 0;
    }

    for (int attempt = 1; attempt <= 3; attempt++) {
        temp = rotate_90(temp);
        if (temp == target) {
            cout << "5\n";
            return 0;
        }
    }

    if (original == target) {
        cout << "6\n";
        return 0;
    }

    cout << "7\n";
}

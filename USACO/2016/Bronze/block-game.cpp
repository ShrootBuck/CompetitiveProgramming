#include <bits/stdc++.h>

using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {

    setIO("blocks");

    int N;
    cin >> N;

    array<int, 26> letters_count{};

    for (int i = 0; i < N; i++) {

        string word1, word2;
        cin >> word1 >> word2;

        array<int, 26> freq1{};
        array<int, 26> freq2{};

        for (char c : word1) {
            freq1[c - 'a']++;
        }

        for (char c : word2) {
            freq2[c - 'a']++;
        }

        for (int j = 0; j < 26; j++) {
            letters_count[j] += max(freq1[j], freq2[j]);
        }
    }

    for (int count : letters_count) {
        cout << count << "\n";
    }
}
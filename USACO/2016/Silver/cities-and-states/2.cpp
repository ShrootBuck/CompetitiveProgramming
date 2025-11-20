#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
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
    setIO("citystate");

    unordered_map<string, unordered_map<string, int>> freq;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string city, state;
        cin >> city >> state;

        string prefix = city.substr(0, 2);
        freq[state][prefix]++;
    }

    int pairs = 0;

    // Time to go re-learn iterators
    for (auto p1 : freq) {
        string A = p1.first;

        for (auto p2 : p1.second) {
            string B = p2.first;

            if (A < B) {
                auto itB = freq.find(B);

                if (itB != freq.end()) {
                    // Genuinely how does one properly name this variable??
                    auto itAinB = itB->second.find(A);

                    if (itAinB != itB->second.end()) {
                        pairs += p2.second * itAinB->second;
                    }
                }
            }
        }
    }

    cout << pairs;
}
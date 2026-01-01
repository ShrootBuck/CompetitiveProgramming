#include <bits/stdc++.h>

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
    setIO("breedflip");

    int N;
    cin >> N;

    string s1, s2;
    cin >> s1 >> s2;

    int transforms = 0;
    bool primed = false;

    for (int i = 0; i < N; i++) {
        if (primed) {
            if (s1[i] == s2[i]) {
                transforms++;
                primed = false;
            }
        } else {
            if (s1[i] != s2[i]) {
                primed = true;
            }
        }
    }

    // Weird because this is required for correctness, but none of the test
    // cases catch it!
    if (primed) {
        transforms++;
    }

    cout << transforms;
}

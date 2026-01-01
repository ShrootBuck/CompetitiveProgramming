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
    setIO("family");

    int N;
    string X, Y;
    cin >> N >> X >> Y;

    unordered_map<string, string> parents;

    for (int i = 0; i < N; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        parents[s2] = s1;
    }

    // Siblings
    if (parents.count(X) && parents.count(Y) && parents[X] == parents[Y]) {
        cout << "SIBLINGS";
        return 0;
    }

    auto top_ancestor = [&](string s) {
        while (parents.count(s)) {
            s = parents[s];
        }

        return s;
    };

    // Will check if Y is a *-mother or *-aunt of X, then swich X and Y and try again
    auto print = [&]() {
        string current = X;
        int levels = 0;

        while (true) {

            // Grandmas
            if (current == Y) {
                cout << Y << " is the ";
                for (int i = 0; i < levels - 2; i++) {
                    cout << "great-";
                }
                if (levels >= 2) {
                    cout << "grand-";
                }
                cout << "mother" << " of " << X;
                return true;
            }

            // Aunts
            if (parents.count(current) && parents.count(Y) &&
                parents.at(current) == parents.at(Y)) {
                cout << Y << " is the ";
                for (int i = 0; i < levels - 1; i++) {
                    cout << "great-";
                }
                cout << "aunt" << " of " << X;
                return true;
            }

            if (!parents.count(current)) {
                break;
            }

            levels++;
            current = parents[current];
        }

        return false;
    };

    if (print()) {
        return 0;
    }

    swap(X, Y);

    if (print()) {
        return 0;
    }

    // Cousin check
    if (top_ancestor(X) == top_ancestor(Y)) {
        cout << "COUSINS";
    } else {
        cout << "NOT RELATED";
    }
}

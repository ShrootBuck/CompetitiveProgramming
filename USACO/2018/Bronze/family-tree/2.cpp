#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
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

ll N;
string a, b;
unordered_map<string, string> mother;

int main() {
    setIO("family");

    cin >> N >> a >> b;
    for (int i = 0; i < N; i++) {
        string X, Y;
        cin >> X >> Y;
        mother[Y] = X;
    }

    unordered_map<string, int> dist_a;

    string current = a;
    int d = 0;
    while (true) {
        dist_a[current] = d;
        if (mother.count(current)) {
            current = mother[current];
            d++;
        } else {
            break;
        }
    }

    current = b, d = 0;
    int da = 0, db = 0;
    while (true) {
        if (dist_a.count(current)) {
            da = dist_a[current];
            db = d;

            if (db > da) {
                swap(a, b);
                swap(db, da);
            }

            if (da == db && da == 1) {
                cout << "SIBLINGS";
            } else if (da > 1 && db > 1) {
                cout << "COUSINS";
            } else {
                cout << b << " is the ";

                int greats = da - 2;
                for (int i = 0; i < greats; i++)
                    cout << "great-";

                if (db == 0) {
                    if (da == 1) {
                        cout << "mother";
                    } else {
                        cout << "grand-mother";
                    }
                } else {
                    cout << "aunt";
                }
                cout << " of " << a;
            }
            return 0;
        }
        if (mother.count(current)) {
            current = mother[current];
            d++;
        } else {
            break;
        }
    }
    cout << "NOT RELATED";
}

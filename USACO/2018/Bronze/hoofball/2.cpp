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
    setIO("hoofball");

    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    sort(a.begin(), a.end());

    vector<int> to(N);
    to[0] = 1;
    to[N - 1] = N - 2;

    for (int i = 1; i < N - 1; i++) {
        if (a[i + 1] - a[i] < a[i] - a[i - 1]) {
            to[i] = i + 1;

        } else {
            to[i] = i - 1;
        }
    }

    vector<int> indegree(N, 0);

    for (int i = 0; i < N; i++) {
        indegree[to[i]]++;
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            ans++;
        } else if (to[to[i]] == i && indegree[to[i]] != 2 && indegree[i] != 2) {
            if (i == min(to[i], i)) {
                ans++;
            }
        }
    }

    cout << ans;
}

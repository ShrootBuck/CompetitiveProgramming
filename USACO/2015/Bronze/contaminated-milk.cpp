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

struct Event {
    int p, m, t;
};

int main() {
    setIO("badmilk");

    int N, M, D, S;
    cin >> N >> M >> D >> S;

    vector<Event> events(D);
    vector<int> sick_time(N, -1); // -1 if not sick
    unordered_set<int> bad_milks; // Potentially bad that is
    vector<unordered_set<int>> drank_milk(M);

    for (int i = 0; i < D; ++i) {
        int p, m, t;
        cin >> p >> m >> t;
        events[i].p = p;
        events[i].m = m;
        events[i].t = t;

        drank_milk[m - 1].insert(p - 1);
    }

    // So actually we don't really care about healthy people
    for (int i = 0; i < S; ++i) {
        int p, t;
        cin >> p >> t;
        sick_time[p - 1] = t;
    }

    // Sort events by time
    sort(events.begin(), events.end(), [](const Event& a, const Event& b) { return a.t < b.t; });

    for (int m = 1; m <= M; ++m) {
        bool sus = true;

        for (int p = 0; p < N; ++p) {
            if (sick_time[p] == -1) {
                continue;
            }

            bool drank_on_time = false;

            for (auto event : events) {
                if (event.p == p + 1 && event.m == m && event.t < sick_time[p]) {
                    drank_on_time = true;
                }
            }

            if (!drank_on_time) {
                sus = false;
                break;
            }
        }

        if (sus) {
            bad_milks.insert(m);
        }
    }

    int max_drank = 0; // I really should work on my variable naming

    for (auto milk : bad_milks) {
        max_drank = max(max_drank, (int)drank_milk[milk - 1].size());
    }

    cout << max_drank;
}

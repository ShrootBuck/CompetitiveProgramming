#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

using ll = long long;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#ifdef LOCAL_RUN
    else {
        freopen("f.in", "r", stdin);
        freopen("f.out", "w", stdout);
    }
#endif
}

struct Event {
    ll day, delta, cow;
};

int main() {
    setIO("measurement");

    ll N;
    cin >> N;

    vector<Event> events(N);
    unordered_map<string, ll> cow_to_id{{"Bessie", 0}, {"Elsie", 1}, {"Mildred", 2}};
    for (ll i = 0; i < N; i++) {
        ll day, delta;
        string cow;
        cin >> day >> cow >> delta;
        events[i].day = day;
        events[i].cow = cow_to_id[cow];
        events[i].delta = delta;
    }
    sort(events.begin(), events.end(), [](Event& e1, Event& e2) { return e1.day < e2.day; });

    vector<ll> leader(3, 7);
    vector<ll> top{0, 1, 2};
    ll ans = 0;

    for (ll i = 0; i < events.size(); i++) {
        leader[events[i].cow] += events[i].delta;
        ll max_score = LLONG_MIN;
        vector<ll> new_top;
        for (ll j = 0; j < 3; j++) {
            if (leader[j] > max_score) {
                new_top = {j};
                max_score = leader[j];
            } else if (leader[j] == max_score) {
                new_top.push_back(j);
                max_score = leader[j];
            }
        }

        if (new_top != top) {
            ans++;
            top = new_top;
        }
    }

    cout << ans;
}

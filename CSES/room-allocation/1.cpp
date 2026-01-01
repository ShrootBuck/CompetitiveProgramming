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

struct customer {
    int a, b, i;
};

int main() {
    setIO();

    int n;
    cin >> n;

    vector<customer> events(n);
    for (int i = 0; i < n; i++) {
        cin >> events[i].a >> events[i].b;
        events[i].i = i;
    }
    sort(events.begin(), events.end(),
         [](const customer& c1, const customer& c2) { return c1.a < c2.a; });

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int last_room = 0;
    vector<int> ans(n);

    for (auto& event : events) {
        if (!pq.empty() && pq.top().first < event.a) {
            ans[event.i] = pq.top().second;
            pq.pop();
        } else {
            ans[event.i] = ++last_room;
        }

        pq.push({event.b, ans[event.i]});
    }

    cout << last_room << "\n";
    for (int& room : ans) {
        cout << room << " ";
    }
}

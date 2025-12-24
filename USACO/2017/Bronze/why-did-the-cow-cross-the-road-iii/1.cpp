#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
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
    setIO("cowqueue");

    int N;
    cin >> N;

    vector<pair<int, int>> events(N);

    while (N--) {
        cin >> events[N].first >> events[N].second;
    }

    sort(events.begin(), events.end());

    // Convert event<start, duration> to event<start, end>
    for (int i = 0; i < events.size(); i++) {
        if (i == 0) {
            events[i].second = events[i].first + events[i].second;
            continue;
        }

        if (events[i].first < events[i - 1].second) {
            events[i].second = events[i - 1].second + events[i].second;
        } else {
            events[i].second = events[i].first + events[i].second;
        }
    }

    cout << events[events.size() - 1].second;
}

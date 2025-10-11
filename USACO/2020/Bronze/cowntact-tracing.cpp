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
  int t, x, y;
};

int main() {
  setIO("tracing");
  int N, T;
  cin >> N >> T;

  string cows;
  cin >> cows;

  vector<bool> health(N + 1, false);

  for (int i = 0; i < N; i++) {
    health[i + 1] = cows[i] == '1';
  }

  vector<Event> events(T);

  for (int i = 0; i < T; i++) {
    cin >> events[i].t >> events[i].x >> events[i].y;
  }

  sort(events.begin(), events.end(),
       [](const Event &a, const Event &b) { return a.t < b.t; });

  set<int> possible_p0s;
  int min_k = T + 1;
  int max_k = -1;

  for (int p0 = 1; p0 <= N; p0++) {
    for (int K = 0; K <= T; K++) {
      vector<bool> infected(N + 1, false);
      vector<int> handshakes_left(N + 1, 0);
      infected[p0] = true;
      handshakes_left[p0] = K;

      for (Event event : events) {
        if (infected[event.x] && !infected[event.y]) {
          // X infects Y
          if (handshakes_left[event.x] > 0) {
            infected[event.y] = true;
            handshakes_left[event.x]--;
            handshakes_left[event.y] = K;
          }
        } else if (infected[event.y] && !infected[event.x]) {
          // Y infects X
          if (handshakes_left[event.y] > 0) {
            infected[event.x] = true;
            handshakes_left[event.y]--;
            handshakes_left[event.x] = K;
          }
        } else if (infected[event.y] && infected[event.x]) {
          // Both infected so they both lose a shake
          handshakes_left[event.x]--;
          handshakes_left[event.y]--;
        }
      }

      if (infected == health) {
        possible_p0s.insert(p0);
        min_k = min(min_k, K);
        max_k = max(max_k, K);
      }
    }
  }

  cout << possible_p0s.size() << " " << min_k << " ";
  if (max_k == T) {
    cout << "Infinity" << endl;
  } else {
    cout << max_k << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;

struct Cow {
  int id;
  char dir;
  long long x, y;
};

struct Event {
  int stopper_cow;
  int stopped_cow;
  long long t;
};

int main() {
  int N;
  cin >> N;

  vector<Cow> cows(N);

  vector<Cow> east_cows;
  vector<Cow> north_cows;
  vector<int> results(N);

  vector<Event> events;

  // Reading in the inputs
  for (int i = 0; i < N; i++) {
    char dir;
    long long x, y;

    cin >> dir >> x >> y;
    cows[i].dir = dir;
    cows[i].x = x;
    cows[i].y = y;
    cows[i].id = i;

    if (dir == 'E') {
      east_cows.push_back({i, dir, x, y});
    } else {
      north_cows.push_back({i, dir, x, y});
    }
  }

  // Assembling (potential) events
  for (const auto &east_cow : east_cows) {
    for (const auto &north_cow : north_cows) {
      if (north_cow.x > east_cow.x && north_cow.y < east_cow.y) {
        long long t;

        // Valid possible collision
        if (north_cow.x - east_cow.x > east_cow.y - north_cow.y) {
          t = north_cow.x - east_cow.x;

          events.push_back({north_cow.id, east_cow.id, t});
        } else if (north_cow.x - east_cow.x < east_cow.y - north_cow.y) {
          t = east_cow.y - north_cow.y;

          events.push_back({east_cow.id, north_cow.id, t});
        } else {
          // Equal means no stop because they both eat the grass
        }
      }
    }
  }

  sort(events.begin(), events.end(),
       [](const Event &a, const Event &b) { return a.t < b.t; });

  // Now, simulate collisions
  vector<long long> final_distance(N, -1);

  for (const Event &event : events) {
    if (final_distance[event.stopped_cow] != -1) {
      continue; // It's already been stopped ("phantom" event)
    }

    Cow &stopper = cows[event.stopper_cow];
    Cow &stopped = cows[event.stopped_cow];

    // Case 1: The stopper cow is still moving (hasn't been stopped yet)
    if (final_distance[stopper.id] == -1) {
      // The event is definitely real
      final_distance[event.stopped_cow] = event.t;
    }
    // Case 2: The stopper cow was already stopped by a previous event
    else {
      // We need to know if it traveled far enough
      // to cause THIS collision before it got stopped
      long long distance_needed;
      if (stopper.dir == 'E') {
        distance_needed = stopped.x - stopper.x;
      } else {
        distance_needed = stopped.y - stopper.y;
      }

      if (final_distance[stopper.id] >= distance_needed) {
        // It made it to the intersection so this event is real
        final_distance[event.stopped_cow] = event.t;
      }
    }
  }

  // Write out the results
  for (auto &result : final_distance) {
    if (result == -1) {
      cout << "Infinity" << "\n";
    } else {
      cout << result << "\n";
    }
  }
}

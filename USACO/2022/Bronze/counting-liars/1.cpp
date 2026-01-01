#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t N;
    cin >> N;

    size_t liars = N;

    vector<char> sightings(N);
    vector<size_t> p(N);

    for (int i = 0; i < N; i++) {
        cin >> sightings[i];
        cin >> p[i];
    }

    for (int i = 0; i < N; i++) {
        size_t local_liars = 0;
        for (int j = 0; j < N; j++) {
            if (sightings[j] == 'G') {
                if (p[j] > p[i]) {
                    local_liars++;
                }
            } else {
                if (p[j] < p[i]) {
                    local_liars++;
                }
            }
        }

        liars = min(liars, local_liars);
    }

    cout << liars;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> search_space{};
int N;
vector<size_t> p;

size_t min_diff = ULONG_MAX;
size_t total = 0;

// Permute each set
void search(int k) {
    if (k == N) {
        size_t local_sum = 0;
        for (int weight : search_space) {
            local_sum += p[weight];
        }

        min_diff = min(min_diff, 2 * local_sum - total);
    } else {
        search(k + 1);
        search_space.push_back(k);
        search(k + 1);
        search_space.pop_back();
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int weight;
        cin >> weight;
        total += weight;
        p.push_back(weight);
    }

    // Search the entire space
    search(0);

    cout << min_diff;
}

#include <bits/stdc++.h>
using namespace std;

struct bucket {
    int capacity;
    int milk;
};

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    array<bucket, 3> buckets;

    for (size_t i = 0; i < 3; i++) {
        cin >> buckets[i].capacity;
        cin >> buckets[i].milk;
    }

    for (size_t i = 0; i < 100; i++) {
        size_t from_bucket = i % 3;
        size_t to_bucket = (from_bucket + 1) % 3;
        int able_to_fill =
            min(buckets[from_bucket].milk, buckets[to_bucket].capacity - buckets[to_bucket].milk);

        buckets[from_bucket].milk -= able_to_fill;
        buckets[to_bucket].milk += able_to_fill;
    }

    for (bucket bucket : buckets) {
        cout << bucket.milk << "\n";
    }
}

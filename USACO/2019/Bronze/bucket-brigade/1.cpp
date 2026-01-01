#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int lake_x, lake_y, barn_x, barn_y, rock_x, rock_y;

    // Get the important locations
    for (int y = 1; y <= 10; y++) {
        for (int x = 1; x <= 10; x++) {
            char temp;
            cin >> temp;
            switch (temp) {
            case 'L':
                lake_x = x;
                lake_y = y;
                break;
            case 'B':
                barn_x = x;
                barn_y = y;
                break;

            case 'R':
                rock_x = x;
                rock_y = y;
                break;
            }
        }
    }

    // Handle edge cases

    if (lake_x == barn_x) {
        if ((rock_y > min(lake_y, barn_y)) && rock_x == lake_x && (rock_y < max(lake_y, barn_y))) {
            cout << abs(lake_y - barn_y) + 1;
            return 0;
        } else {
            cout << abs(lake_y - barn_y) - 1;
            return 0;
        }
    }
    if (lake_y == barn_y) {
        if ((rock_x > min(lake_x, barn_x)) && rock_y == lake_y && (rock_x < max(lake_x, barn_x))) {
            cout << abs(lake_x - barn_x) + 1;
            return 0;
        } else {
            cout << abs(lake_x - barn_x) - 1;
            return 0;
        }
    }

    cout << abs(lake_x - barn_x) + abs(lake_y - barn_y) - 1;
    return 0;
}

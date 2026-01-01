#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<bool> nums(2000000 + 1, true);
    nums[0] = false;
    nums[1] = false;

    // Sieve of whatever his name was
    for (int i = 2; i <= sqrt(2000000); i++) {
        if (nums[i]) {
            for (int j = 2 * i; j <= 2000000; j += i) {
                nums[j] = false;
            }
        }
    }

    long long sum = 0;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i]) {
            sum += i;
        }
    }

    cout << sum;
}

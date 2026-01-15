#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// stop @ fA to avoid overflow because i forgot how to use the bigger gcc extension
ll safe_value(ll given_a, ll x, ll A, ll B, ll cA, ll cB, ll fA) {
    ll currentA = A + given_a;
    if (currentA >= fA)
        return fA;

    ll needed_a = fA - currentA;
    ll current_b = B + (x - given_a);
    ll conversions_possible = current_b / cB;
    ll conversions_needed = needed_a / cA;
    if (needed_a % cA != 0) {
        conversions_needed++;
    }

    if (conversions_possible >= conversions_needed) {
        return fA;
    }

    // If we haven't reached the target, the result should ve small enough to fit in ll?
    return currentA + conversions_possible * cA;
}

bool check(ll x, ll A, ll B, ll cA, ll cB, ll fA) {
    // 1. All B
    ll option1 = safe_value(0, x, A, B, cA, cB, fA);

    // 2. All A
    ll res2 = safe_value(x, x, A, B, cA, cB, fA);

    ll current_remaining = (B + x) % cB;
    ll given_a_low = (current_remaining + 1) % cB;
    ll option3 = LLONG_MAX;
    if (given_a_low <= x) {
        option3 = safe_value(given_a_low, x, A, B, cA, cB, fA);
    }

    ll given_a_high = given_a_low + ((x - given_a_low) / cB) * cB;

    ll option4 = LLONG_MAX;
    if (given_a_high <= x) {
        option4 = safe_value(given_a_high, x, A, B, cA, cB, fA);
    }

    return min({option1, res2, option3, option4}) >= fA;
}

ll solve() {
    ll A, B, cA, cB, fA;
    cin >> A >> B >> cA >> cB >> fA;

    if (A >= fA)
        return 0;

    ll low = 0, high = 1e18; // (10^9)^2
    ll ans = LLONG_MAX;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid, A, B, cA, cB, fA)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    setIO();

    ll T;
    cin >> T;

    while (T--) {
        cout << solve() << "\n";
    }
}

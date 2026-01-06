#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ZK_LOCAL_RUN
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
#else
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#endif
}

int main() {
    setIO();

    ll n;
    cin >> n;

    multiset<ll> people;
    set<ll> unique_people;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        people.insert(a);
        unique_people.insert(a);
    }

    set<ll> weights;
    for (auto& person : unique_people) {
        const size_t people_count = people.count(person);
        for (size_t uses = 0; uses < people_count && uses < 3;) {
            if (!weights.count(person - 1) && person - 1 > 0) {
                weights.insert(person - 1);
                uses++;
            } else if (!weights.count(person) && person > 0) {
                weights.insert(person);
                uses++;
            } else if (!weights.count(person + 1) && person + 1 > 0) {
                weights.insert(person + 1);
                uses++;
            } else {
                break;
            }
        }
    }

    cout << weights.size();
}

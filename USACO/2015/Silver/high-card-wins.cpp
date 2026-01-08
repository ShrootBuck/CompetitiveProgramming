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
    setIO("highcard");

    ll N;
    cin >> N;

    vector<ll> elsie_cards(N);
    unordered_set<ll> elsie_cardset(N);
    for (ll i = 0; i < N; i++) {
        ll n;
        cin >> n;

        elsie_cards[i] = n;
        elsie_cardset.insert(n);
    }

    set<ll> bessie_cards;
    for (ll i = 1; i <= 2 * N; i++) {
        if (!elsie_cardset.count(i)) {
            bessie_cards.insert(i);
        }
    }

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        auto thing = bessie_cards.lower_bound(elsie_cards[i] + 1);

        if (thing == bessie_cards.end()) {
            bessie_cards.erase(0);
        } else {
            bessie_cards.erase(thing);
            ans++;
        }
    }

    cout << ans;
}

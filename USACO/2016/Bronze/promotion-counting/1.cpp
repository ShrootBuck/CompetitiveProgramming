#include <iostream>
using namespace std;

int main() {
    // Competition requirement is binding std IO to file IO
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int bronze_start, bronze_end;
    int silver_start, silver_end;
    int gold_start, gold_end;
    int plat_start, plat_end;

    cin >> bronze_start >> bronze_end >> silver_start >> silver_end >> gold_start >> gold_end >>
        plat_start >> plat_end;

    int new_players = (bronze_end + silver_end + gold_end + plat_end) -
                      (bronze_start + silver_start + gold_start + plat_start);

    // incrementally 'consume' players
    int advancing_players = new_players;

    advancing_players -= (bronze_end - bronze_start);

    int silver_promotions = advancing_players;

    advancing_players -= (silver_end - silver_start);

    int gold_promotions = advancing_players;

    advancing_players -= (gold_end - gold_start);

    int plat_promotions = advancing_players;

    cout << silver_promotions << "\n" << gold_promotions << "\n" << plat_promotions;

    //   if (bronze_end > bronze_start) {
    //     advancing_players -= (bronze_end - bronze_start);
    //   }
}

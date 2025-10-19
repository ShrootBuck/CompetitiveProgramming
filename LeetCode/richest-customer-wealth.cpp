class Solution {
  public:
    int maximumWealth(vector<vector<int>> &accounts) {
        int richest = 0;

        for (auto &account : accounts) {
            int local_wealth = 0;

            for (auto &money : account) {
                local_wealth += money;
            }

            richest = max(richest, local_wealth);
        }

        return richest;
    }
};

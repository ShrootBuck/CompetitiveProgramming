class Solution {
  public:
    int rob(vector<int> &nums) {
        int s1 = 0;
        int s2 = 0;

        for (auto &num : nums) {
            int temp = max(num + s1, s2);

            s1 = s2;
            s2 = temp;
        }

        return s2;
    }
};

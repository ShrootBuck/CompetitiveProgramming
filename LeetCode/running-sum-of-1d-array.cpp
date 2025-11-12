class Solution {
  public:
    vector<int> runningSum(vector<int>& nums) {
        // So basically, a prefix sum.
        auto prefix = nums;

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) {
                prefix[i] += prefix[i - 1];
            }
        }

        return prefix;
    }
};

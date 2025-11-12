class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen{};

        for (int i = 0; i < nums.size(); i++) {
            int& num = nums[i];

            auto& index = seen[target - num];

            if (index != 0) {
                return {index - 1, i};
            }

            seen[num] = i + 1;
        }

        return {}; // LeetCode compiler is strict
    }
};

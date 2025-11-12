class Solution {
  public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int total = 0;
        long long prod = 1;

        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            prod *= nums[r];

            // Size the window
            while (l <= r && prod >= k) {
                prod /= nums[l];
                l++;
            }

            // All subarrays ending at r with start from l to r are valid
            total += r - l + 1;
        }

        return total;
    }
};

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> nobbers;

        for (int nobber : nums) {
            if (nobbers.count(nobber)) {
                return true;
            }
            nobbers.insert(nobber);
        }

        return false;
    }
};

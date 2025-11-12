class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> toolbox;

        for (auto& c : magazine) {
            toolbox[c]++;
        }

        for (auto& c : ransomNote) {
            if (toolbox[c] == 0) {
                return false;
            }

            toolbox[c]--;
        }

        return true;
    }
};

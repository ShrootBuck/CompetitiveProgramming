class Solution {
  public:
    vector<string> fizzBuzz(int n) {
        vector<string> return_value;

        for (int i = 1; i <= n; i++) {
            string result = "";

            if (i % 3 == 0) {
                result += "Fizz";
            }
            if (i % 5 == 0) {
                result += "Buzz";
            }

            if (result == "") {
                result = to_string(i);
            }

            return_value.push_back(result);
        }

        return return_value;
    }
};

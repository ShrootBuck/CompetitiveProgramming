#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    vector<int> digits;

    while (getline(cin, line)) {
        for (char c : line) {
            if (isdigit(c)) {
                digits.push_back(c - '0'); // Convert char digit to int
            }
        }
    }

    long long max_product = 0;
    for (int i = 0; i <= (int)digits.size() - 13; ++i) {
        long long current_product = 1;

        for (int j = 0; j < 13; ++j) {
            if (digits[i + j] == 0) {
                current_product = 0;
                i = i + j;
                break;
            }
            current_product *= digits[i + j];
        }

        max_product = max(max_product, current_product);
    }

    cout << max_product;
}
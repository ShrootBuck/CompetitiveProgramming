#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    vector<int> b;
    unordered_map<int, int>
        freq{}; // This is the best way I can think of to solve this, am I stupid?

    int n1, n2;
    while (cin >> n1 >> n2) {

        a.push_back(n1);
        b.push_back(n2);

        freq[n2]++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int total = 0;

    for (int i = 0; i < a.size(); i++) {
        total += abs(a[i] - b[i]);
    }

    cout << "Part 1:\t";
    cout << total;

    cout << "\n";

    int similarity = 0;

    for (int n : a) {
        similarity += n * freq[n];
    }

    cout << "Part 2:\t";
    cout << similarity;
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int in1, in2, in3, in4, in5, in6, in7;
    cin >> in1 >> in2 >> in3 >> in4 >> in5 >> in6 >> in7;

    vector<int> numbers = {in1, in2, in3, in4, in5, in6, in7};
    sort(numbers.begin(), numbers.end());

    int a = numbers[0];
    int b = numbers[1];
    int c = numbers[numbers.size() - 1] - a - b;

    cout << a << " " << b << " " << c;
}

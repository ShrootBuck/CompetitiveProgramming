#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

#define ll long long

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// Do I love or do I hate recursion? I am undecided.
void solve(int n, int source, int auxiliary, int destination) {

    // Base case = no disks
    if (n == 0) {
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary
    // The destination peg now becomes the temp auxiliary peg
    solve(n - 1, source, destination, auxiliary);

    // Step 2: Move the one big disk from source to destination
    cout << source << " " << destination << "\n";

    // Step 3: Move the n-1 disks from auxiliary to destination
    // The original source peg now becomes the temp auxiliary peg
    solve(n - 1, auxiliary, source, destination);
}

int main() {
    setIO();

    int n;
    cin >> n;

    // Print the number of moves, which is proven always 2^n - 1
    cout << (1 << n) - 1 << "\n";

    solve(n, 1, 2, 3);
}

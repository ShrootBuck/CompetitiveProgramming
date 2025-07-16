// Source: https://usaco.guide/general/io
//
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {

  setIO("paint");

  int a;
  int b;
  int c;
  int d;

  cin >> a >> b >> c >> d;

  int lenA = b - a;
  int lenB = d - c;

  int overlap = max(0, min(b, d) - max(a, c));

  cout << lenA + lenB - overlap;
}

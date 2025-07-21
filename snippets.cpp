// Copy-paste central for USACO and competitive programming

void setIO(std::string name = "") {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int n;
vector<int> current;

// Generic backtracking template
void search(int k) {
  if (k == n) {
    // Process one full solution (current)
    return;
  }

  // For each choice option at step k
  // (for subsets, the options are {skip, take})
  for (int option : {0, 1}) {
    if (option == 1)
      current.push_back(k); // take

    search(k + 1);

    if (option == 1)
      current.pop_back(); // undo (backtrack)
  }
}

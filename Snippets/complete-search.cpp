int n;
vector<int> current_subset;

// Recursive function to explore all subsets
void generate(int k) {
  if (k == n) {
    // Process the subset

    // Then return!
    return;
  }

  // Choice 1: "leave it"
  // We don't add item k to our subset and move on to the next item
  generate(k + 1);

  // Choice 2: "take it"
  // We add item k to our subset
  current_subset.push_back(k);
  // ...and then move on to the next item
  generate(k + 1);
  // ...and then we MUST backtrack by removing it, to clean up the state
  // for other branches of the recursion.
  current_subset.pop_back();
}

// Kick off the recursion from the first item (index 0)
// generate(0);

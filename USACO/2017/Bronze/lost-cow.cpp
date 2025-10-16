#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream fin("lostcow.in");
  ofstream fout("lostcow.out");

  int x, y;
  fin >> x >> y;

  if (x == y) {
    fout << 0 << endl;
    return 0;
  }

  long long total_distance = 0;
  int current_pos = x;
  int move_amount = 1;
  int direction = 1; // 1 for positive, -1 for negative

  while (true) {
    int destination = x + (direction * move_amount);

    bool found_cow = false;
    if (direction == 1) { // Moving right
      if (current_pos <= y && y <= destination) {
        found_cow = true;
      }
    } else { // Moving left
      if (destination <= y && y <= current_pos) {
        found_cow = true;
      }
    }

    if (found_cow) {
      total_distance += abs(y - current_pos);
      break;
    }

    total_distance += abs(destination - current_pos);
    current_pos = destination;
    move_amount *= 2;
    direction *= -1;
  }

  fout << total_distance << endl;

  return 0;
}

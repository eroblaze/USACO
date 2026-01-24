// @eroblaze
#include <bits/stdc++.h>
// #include "../PCH.h"
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int bad[4], good[4];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("billboard.in", "r", stdin), freopen("billboard.out", "w", stdout);

  for (int i = 0; i < 4; ++i) cin >> bad[i];
  for (int i = 0; i < 4; ++i) cin >> good[i];

  int good_height = good[3] - good[1], good_width = good[2] - good[0];
  int bad_height = bad[3] - bad[1], bad_width = bad[2] - bad[0];

  int x = max(0, min(bad[2], good[2]) - max(bad[0], good[0]));
  int y = max(0, min(bad[3], good[3]) - max(bad[1], good[1]));
  int area_of_bad = (bad[2] - bad[0]) * (bad[3] - bad[1]);

  if (x == 0 || y == 0) {
    // there are no intersections
    cout << area_of_bad << endl;
    exit(0);
  }

  if ((good[0] > bad[0] && good[2] < bad[2]) || (good[1] > bad[1] && good[3] < bad[3])) {
    cout << area_of_bad << endl;
    exit(0);
  }

  if (y < bad_height && x < bad_width) {
    cout << area_of_bad << endl;
    exit(0);
  }

  int breadth = bad_width - x;
  int length = y;

  if (y < bad_height) {
    breadth = x;
    length = bad_height - y;
  }

  cout << breadth * length << endl;

  return 0;
}

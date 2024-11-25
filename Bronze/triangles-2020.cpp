// @eroblaze
#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("triangles.in", "r", stdin), freopen("triangles.out", "w", stdout);

  int n;
  cin >> n;

  map<int, vector<int>> mp_x, mp_y;
  vector<array<int, 2>> entries;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    entries.push_back({x, y});
    mp_x[y].push_back(x);
    mp_y[x].push_back(y);
  }

  double ans = 0;

  for (array<int, 2> &e : entries) {
    int e_x = e[0];
    int e_y = e[1];

    for (int up_or_down : mp_y[e_x]) {
      if (up_or_down != e_y) {
        for (int left_or_right : mp_x[e_y]) {
          if (left_or_right != e_x) {
            double height = abs(e_y - up_or_down);
            double base = abs(e_x - left_or_right);
            double area = (base * height) / 2.0;
            ans = max(ans, area);
          }
        }
      }
    }
  }

  cout << fixed << setprecision(0) << 2 * ans << '\n';

  return 0;
}

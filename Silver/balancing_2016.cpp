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
  // USACO
  freopen("balancing.in", "r", stdin), freopen("balancing.out", "w", stdout);

  int n;
  cin >> n;
  vector<pair<int, int>> coord;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    coord.push_back({x, y});
  }

  sort(coord.begin(), coord.end());
  auto y_sorted = coord;
  sort(y_sorted.begin(), y_sorted.end(),
       [&](pair<int, int> &one, pair<int, int> &two) { return one.second < two.second; });

  unordered_map<int, bool> vis;

  int ans = 1001;

  for (int i = 0; i < n - 1; ++i) {
    int a = coord[i].first + 1;

    if (!vis[a]) {
      vis[a] = 1;

      for (pair<int, int> &el : y_sorted) {
        int b = el.second + 1;
        int lower_left = 0, lower_right = 0, upper_left = 0, upper_right = 0;

        for (pair<int, int> &co : coord) {
          int x, y;
          tie(x, y) = co;

          if (x < a) {
            if (y < b) lower_left++;
            else upper_left++;
          } else {
            if (y < b) lower_right++;
            else upper_right++;
          }
        }

        ans = min(ans, max(lower_left, max(lower_right, max(upper_left, upper_right))));
      }
    }
  }

  cout << ans << '\n';

  return 0;
}

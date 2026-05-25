#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

using ll = int64_t;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 2>> coord(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    coord[i] = {x, y};
  }
  sort(coord.begin(), coord.end());
  for (int i = 0; i < n; ++i) coord[i][0] = i + 1;
  sort(coord.begin(), coord.end(), [](array<int, 2>& a, array<int, 2>& b) { return a[1] < b[1]; });
  for (int i = 0; i < n; ++i) coord[i][1] = i + 1;

  vector<vector<int>> grid(n + 1, vector<int>(n + 1));
  for (array<int, 2>& co : coord) grid[co[0]][co[1]] = 1;

  vector<vector<ll>> pref(n + 1, vector<ll>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) pref[i][j] = grid[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
  }
  auto query = [&](ll x1, ll y1, ll x2, ll y2) {
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
  };

  sort(coord.begin(), coord.end());
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    ++ans;
    ll x1 = coord[i][0], y1 = coord[i][1];
    for (int j = i + 1; j < n; ++j) {
      ll x2 = coord[j][0], y2 = coord[j][1];
      ll y_min = min(y1, y2);
      ll y_max = max(y1, y2);
      ll below = query(x1, 1, x2, y_min - 1) + 1;
      ll above = query(x1, y_max + 1, x2, n) + 1;

      ans += below * above;
    }
  }

  cout << ans << endl;
  return 0;
}

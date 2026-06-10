#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("art.in", "r", stdin), freopen("art.out", "w", stdout);

  int n;
  cin >> n;
  vector<vector<int>> grid(n + 1, vector<int>(n + 1));
  unordered_map<int, array<int, 4>> boundary;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int curr;
      cin >> curr;
      if (curr == 0) continue;
      grid[i][j] = curr;
      int x1 = boundary[curr][0] == 0 ? INT_MAX : boundary[curr][0];
      int y1 = boundary[curr][1] == 0 ? INT_MAX : boundary[curr][1];
      boundary[curr][0] = min(x1, i);
      boundary[curr][1] = min(y1, j);
      boundary[curr][2] = max(boundary[curr][2], i);
      boundary[curr][3] = max(boundary[curr][3], j);
    }
  }
  vector<vector<int>> diff(n + 2, vector<int>(n + 2));
  for (auto& [k, v] : boundary) {
    int x1 = v[0], y1 = v[1], x2 = v[2], y2 = v[3];
    diff[x1][y1]++;
    diff[x1][y2 + 1]--;
    diff[x2 + 1][y1]--;
    diff[x2 + 1][y2 + 1]++;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
    }
  }

  set<int> st;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (diff[i][j] > 1) st.insert(grid[i][j]);
    }
  }
  int ans = n * n;
  // Edge case of only 1 color showing on the canvas
  if (n > 1 && (int)boundary.size() == 1) --ans;
  else ans -= (int)st.size();
  cout << ans << endl;
  return 0;
}

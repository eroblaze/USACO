// @eroblaze
#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

const int N = 1000;
char grid[N + 1][N + 1];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<array<int, 2>> pos;
    int cnt_of_g = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> grid[i][j];
        if (grid[i][j] == 'G') ++cnt_of_g;
        if (grid[i][j] == 'B') {
          pos.push_back({i, j});
        }
      }
    }

    if (a == 0 && b == 0) {
      cout << (int)pos.size() + cnt_of_g << '\n';
      continue;
    }
    if ((a != 0 || b != 0) && (!pos.empty() && cnt_of_g == 0)) {
      cout << -1 << '\n';
      continue;
    }

    auto is_valid = [&](int r, int c, bool up) {
      if (up) {
        return (r - b >= 0 && c - a >= 0);
      } else {
        return (c + a < n && r + b < n);
      }
    };

    int ans = 0;
    bool ok = 1;
    for (array<int, 2>& ar : pos) {
      int r = ar[0], c = ar[1];
      if (grid[r][c] == 'W') continue;

      grid[r][c] = 'W';
      bool fnd = 0;
      // dbg(r, c);
      // come from
      while (is_valid(r, c, true)) {
        r -= b, c -= a;
        // dbg(grid[r][c]);
        if (grid[r][c] == 'G') {
          fnd = 1;
        } else if (grid[r][c] == 'W') {
          break;
        }
        ++ans;
        grid[r][c] = 'W';
        if (fnd) break;
      }
      if (!fnd) {
        ok = 0;
        break;
      }

      // go to
      // cnt for this 'B'
      ++ans;
      // dbg(ans);
      r = ar[0], c = ar[1];
      while (is_valid(r, c, false)) {
        r += b, c += a;
        // dbg(r, c);
        // dbg(grid[r][c]);
        if (grid[r][c] == 'G') {
          if (is_valid(r, c, false) && grid[r + b][c + a] == 'B') {
            break;
          } else
            grid[r][c] = 'W';

          break;
        } else if (grid[r][c] == 'B') {
          ++ans;
          grid[r][c] = 'W';
        } else {
          break;
        }
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 'G') {
          ++ans;
          grid[i][j] = 'W';
          if (is_valid(i, j, false)) {
            int r = i + b, c = j + a;
            assert(grid[r][c] != 'B');
            grid[r][c] = 'W';
          }
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}

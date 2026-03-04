// @eroblaze
#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

array<int, 2> arr_x[int(5e5) + 1], arr_y[int(5e5) + 1];
array<int, 2> dirs[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("reduce.in", "r", stdin), freopen("reduce.out", "w", stdout);

  // THIS IS NOT THE OPTIMAL SOLUTION -> The optimal one involves only considering 12 cows i.e 3 smallest on the x axis,
  // 3 largest on the x axis, 3 smallest on the y axis and 3 largest on the y axis
  /* This problem is just a complete search (bruteforce) problem
    where you need to remove all combinations of 3 directions from the 4 directions (i.e top, right, bottom, left)
    and then calculate the area of the rectange for the rest (n-3) cows and get the overall minimum
  */
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    arr_x[i] = {a, b};
    arr_y[i] = {b, a};
  }
  sort(arr_x, arr_x + n);
  sort(arr_y, arr_y + n);

  vector<vector<bool>> vis(40001, vector<bool>(40001));

  auto mark = [&](int idx) -> pair<int, int> {
    int r = dirs[idx][0], c = dirs[idx][1];
    if (r == 1) {
      // down -> least y
      for (int i = 0; i < n; ++i) {
        int x = arr_y[i][1], y = arr_y[i][0];
        if (!vis[x][y]) {
          vis[x][y] = 1;
          return {x, y};
        }
      }

    } else if (r == -1) {
      // up -> biggest y
      for (int i = n - 1; i >= 0; --i) {
        int x = arr_y[i][1], y = arr_y[i][0];
        if (!vis[x][y]) {
          vis[x][y] = 1;
          return {x, y};
        }
      }
    } else if (c == 1) {
      // right -> most x
      for (int i = n - 1; i >= 0; --i) {
        int x = arr_x[i][0], y = arr_x[i][1];
        if (!vis[x][y]) {
          vis[x][y] = 1;
          return {x, y};
        }
      }
    } else if (c == -1) {
      // left -> least x
      for (int i = 0; i < n; ++i) {
        int x = arr_x[i][0], y = arr_x[i][1];
        if (!vis[x][y]) {
          vis[x][y] = 1;
          return {x, y};
        }
      }
    }

    assert(false);
  };

  int64_t ans = INT_MAX;
  for (int i = 0; i < 4; ++i) {
    int r_x = 0, r_y = 0;
    tie(r_x, r_y) = mark(i);

    for (int j = 0; j < 4; ++j) {
      int r_x2 = 0, r_y2 = 0;
      tie(r_x2, r_y2) = mark(j);

      for (int k = 0; k < 4; ++k) {
        int r_x3 = 0, r_y3 = 0;
        tie(r_x3, r_y3) = mark(k);

        int l = 0, r = 0, u = 0, d = 0;
        for (int p = 0; p < n; ++p) {
          int x_t = arr_x[p][0], y_t = arr_x[p][1];
          if (!vis[x_t][y_t]) {
            l = x_t;
            break;
          }
        }
        for (int p = n - 1; p >= 0; --p) {
          int x_t = arr_x[p][0], y_t = arr_x[p][1];
          if (!vis[x_t][y_t]) {
            r = x_t;
            break;
          }
        }
        // Case of a vertical line
        if (l == r) {
          ans = 0;
          break;
        }
        assert(l < r);

        for (int p = 0; p < n; ++p) {
          int x_t = arr_y[p][1], y_t = arr_y[p][0];
          if (!vis[x_t][y_t]) {
            d = y_t;
            break;
          }
        }

        for (int p = n - 1; p >= 0; --p) {
          int x_t = arr_y[p][1], y_t = arr_y[p][0];
          if (!vis[x_t][y_t]) {
            u = y_t;
            break;
          }
        }

        // Case of a horizontal line
        if (u == d) {
          ans = 0;
          break;
        }
        assert(d < u);

        int64_t curr = (r - l) * (u - d);
        ans = min(ans, curr);
        vis[r_x3][r_y3] = 0;
      }
      if (ans == 0) break;
      vis[r_x2][r_y2] = 0;
    }
    if (ans == 0) break;
    vis[r_x][r_y] = 0;
  }

  cout << ans << '\n';

  return 0;
}

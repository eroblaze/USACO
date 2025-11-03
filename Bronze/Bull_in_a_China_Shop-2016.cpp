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
  freopen("bcs.in", "r", stdin), freopen("bcs.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  vector<string> f(n);
  vector<vector<string>> a(k);
  // left, right, top, bottom
  vector<vector<int>> bounds(k);
  vector<vector<string>> rectangle(k);
  int hash_cnt = 0;

  for (int i = 0; i < n; ++i) {
    string tmp;
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      if (c == '#') hash_cnt++;
      tmp += c;
    }
    f[i] = tmp;
  }

  for (int i = 0; i < k; ++i) {
    // j-> row, l -> column

    int left = n, right = 0, bottom = 0, top = n;
    string row;

    for (int j = 0; j < n; ++j) {
      for (int l = 0; l < n; ++l) {
        char c;
        cin >> c;

        if (c == '#') {
          left = min(left, l);
          right = max(right, l);
          top = min(top, j);
          bottom = max(bottom, j);
        }

        row += c;
      }

      a[i].push_back(row);
      row.clear();
    }

    bounds[i].push_back(left);
    bounds[i].push_back(right);
    bounds[i].push_back(top);
    bounds[i].push_back(bottom);

    for (int r = top; r <= bottom; ++r) {
      string s_r;

      for (int c = left; c <= right; ++c) { s_r += a[i][r][c]; }
      rectangle[i].push_back(s_r);
    }
  }

  auto is_valid = [&](int r, int c, int curr) -> bool {
    int left = bounds[curr][0], right = bounds[curr][1], top = bounds[curr][2], bottom = bounds[curr][3];
    int x_gap = right - left, y_gap = bottom - top;

    return (c + x_gap < n && r + y_gap < n) ? true : false;
  };

  for (int i = 0; i < k; ++i) {

    // start from top left -> {0, 0}
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        if (is_valid(r, c, i)) {
          vector<vector<bool>> present(n, vector<bool>(n));
          int left = bounds[i][0], right = bounds[i][1], top = bounds[i][2], bottom = bounds[i][3];
          int x_gap = right - left, y_gap = bottom - top;

          bool ok = 1;
          int tmp_hash_cnt = hash_cnt;

          for (int i_r = r; i_r <= r + y_gap; ++i_r) {
            for (int i_c = c; i_c <= c + x_gap; ++i_c) {

              if (rectangle[i][i_r - r][i_c - c] == '#') {
                if (f[i_r][i_c] == '#') {
                  present[i_r][i_c] = 1;
                  --tmp_hash_cnt;
                } else {
                  ok = 0;
                  break;
                }
              }

              if (!ok) break;
            }

            if (!ok) break;
          }

          if (!ok) continue;

          // j -> partner block
          for (int j = i + 1; j < k; ++j) {
            int tmp_hash_cnt2 = tmp_hash_cnt;

            // start the partner from top left -> {0,0}
            for (int j_r = 0; j_r < n; ++j_r) {
              for (int j_c = 0; j_c < n; ++j_c) {

                if (is_valid(j_r, j_c, j)) {
                  int left = bounds[j][0], right = bounds[j][1], top = bounds[j][2], bottom = bounds[j][3];
                  int x_gap = right - left, y_gap = bottom - top;
                  bool ok2 = 1;

                  for (int jj_r = j_r; jj_r <= j_r + y_gap; ++jj_r) {
                    for (int jj_c = j_c; jj_c <= j_c + x_gap; ++jj_c) {

                      if (rectangle[j][jj_r - j_r][jj_c - j_c] == '#') {
                        if (f[jj_r][jj_c] == '#') {
                          if (present[jj_r][jj_c]) {
                            ok2 = 0;
                            break;
                          }
                          --tmp_hash_cnt2;
                        } else {
                          ok2 = 0;
                          break;
                        }
                      }
                      if (!ok2) break;
                    }
                    if (!ok2) break;
                  }

                  if (ok2 && tmp_hash_cnt2 == 0) {
                    cout << i + 1 << " " << j + 1 << '\n';

                    return 0;
                  }
                } else break;
              }
            }
          }

        } else break;
      }
    }
  }

  return 0;
}

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
  freopen("cowtip.in", "r", stdin), freopen("cowtip.out", "w", stdout);

  int n;
  cin >> n;
  vector<string> g(n);
  for (int i = 0; i < n; ++i) cin >> g[i];

  auto flip = [&](int r, int c) {
    for (int i = 0; i <= r; ++i) {
      for (int j = 0; j <= c; ++j) {
        if (g[i][j] == '1') g[i][j] = '0';
        else g[i][j] = '1';
      }
    }
  };

  int ans = 0;

  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (g[i][j] != '0') {
        ++ans;
        flip(i, j);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}

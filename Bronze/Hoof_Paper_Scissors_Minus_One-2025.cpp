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
  // freopen("herding.in", "r", stdin), freopen("herding.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<map<int, bool>> arr(n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i + 1; ++j) {
      char r;
      cin >> r;
      if (r == 'W') arr[j][i] = 1;
      if (r == 'L') arr[i][j] = 1;
    }
  }

  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;

    int cnt = 0;

    for (auto &[k, v] : arr[l]) {
      if (arr[r].count(k)) ++cnt;
    }

    int ans = cnt * ((2 * (n - 1)) + 1);
    if (cnt > 1) ans -= cnt * (cnt - 1);

    cout << (cnt ? ans : 0) << '\n';
  }

  return 0;
}

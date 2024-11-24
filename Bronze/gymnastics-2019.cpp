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
  freopen("gymnastics.in", "r", stdin), freopen("gymnastics.out", "w", stdout);

  int k, n;
  cin >> k >> n;

  vector<vector<int>> a(n);

  for (int i = 0; i < k; ++i) {

    for (int j = 0; j < n; ++j) {
      int idx;
      cin >> idx;
      idx--;
      a[idx].push_back(j + 1);
    }
  }

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    bool ok = 1;
    for (int j = i + 1; j < n; ++j) {
      for (int l = 1; l < k; ++l) {
        if (a[i][0] > a[j][0]) {
          if (a[i][l] < a[j][l]) {
            ok = 0;
            break;
          }
        } else {
          if (a[j][l] < a[i][l]) {
            ok = 0;
            break;
          }
        }
      }
      if (ok) ++ans;
      else ok = 1;
    }
  }

  cout << ans << '\n';

  return 0;
}

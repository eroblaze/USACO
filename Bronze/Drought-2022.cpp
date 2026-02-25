// @eroblaze
#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int64_t a[int(1e5) + 7];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  // freopen("sol.in", "r", stdin), freopen("sol.out", "w", stdout);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];

    int64_t ans = 0;

    for (int i = 0; i < n; ++i) {
      if (i == n - 1) continue;
      if (a[i] > a[i + 1]) {
        if ((i + 1) % 2 == 1) {
          ans = -1;
          break;
        } else {
          int64_t diff = a[i] - a[i + 1];
          ans += diff * 1ll * (i + 1);
        }
      } else {
        int64_t diff = a[i + 1] - a[i];
        if (diff) {
          if (i + 2 >= n || a[i + 2] - diff < 0) {
            ans = -1;
            break;
          } else {
            a[i + 2] -= diff;
            ans += diff * 1ll * 2;
            a[i + 1] = a[i];
          }
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}

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
  freopen("pairup.in", "r", stdin), freopen("pairup.out", "w", stdout);
  int n;
  cin >> n;
  vector<array<ll, 2>> a(n);
  for (int i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;
    a[i] = {y, x};
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0, j = n - 1; i <= j;) {
    if (i == j) {
      ans = max(ans, a[i][0] * 2);
      break;
    }
    ans = max(ans, a[i][0] + a[j][0]);
    ll mn = min(a[i][1], a[j][1]);
    a[i][1] -= mn;
    a[j][1] -= mn;
    if (a[i][1] == 0) ++i;
    if (a[j][1] == 0) --j;
  }
  cout << ans << endl;
  return 0;
}

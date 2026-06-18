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
  int n, q;
  cin >> n >> q;
  vector<array<ll, 3>> a(n);
  for (int i = 0; i < n; ++i) {
    ll x, y, t;
    cin >> x >> y >> t;
    a[i] = {t, x, y};
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  while (q--) {
    ll x, y, t;
    cin >> x >> y >> t;
    int b = -1;
    for (int k = (n + 1) / 2; k >= 1; k /= 2) {
      while (b + k < n && a[b + k][0] < t) b += k;
    }
    b = min(b + 1, n - 1);
    ll dx = abs(a[b][1] - x), dy = abs(a[b][2] - y);
    ll dist = dx * dx + dy * dy;
    ll td = a[b][0] - t;
    ll dt = t - a[b][0];
    int ok = 0;
    if (a[b][0] >= t) {
      if (dist > td * td) ok = 1;
      if (b > 0) {
        dx = abs(a[b - 1][1] - x), dy = abs(a[b - 1][2] - y);
        dist = dx * dx + dy * dy;
        dt = t - a[b - 1][0];
        if (dist > dt * dt) ok = 1;
      }
    } else {
      if (dist > dt * dt) ok = 1;
    }
    ans += ok;
  }
  cout << ans << "\n";
  return 0;
}

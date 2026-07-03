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
  freopen("socdist.in", "r", stdin), freopen("socdist.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<array<ll, 2>> a(m);
  for (int i = 0; i < m; ++i) cin >> a[i][0] >> a[i][1];
  sort(a.begin(), a.end());
  auto check = [&](ll D) -> bool {
    ll start = 0, cnt = 0;
    for (int i = 0; i < m; ++i) {
      ll left = a[i][0], right = a[i][1];
      if (start < left) start = left;
      if (start >= left && start <= right) {
        ll curr = (right - start + 1 + D - 1) / D;
        cnt += curr;
        start += D * curr;
      }
    }
    return cnt >= n;
  };
  ll low = 1, high = ll(1e18), ans = 1;
  while (low <= high) {
    ll mid = low + (high - low) / 2;
    if (check(mid)) {
      ans = mid;
      low = mid + 1;
    } else high = mid - 1;
  }

  cout << ans << endl;
  return 0;
}

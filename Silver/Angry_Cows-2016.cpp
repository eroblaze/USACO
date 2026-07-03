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
  freopen("angry.in", "r", stdin), freopen("angry.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  auto check = [&](ll R) -> bool {
    int cnt = 1;
    ll end = 2 * R + a[0];
    for (int i = 0; i < n; ++i) {
      if (a[i] > end) {
        ++cnt;
        end = a[i] + 2 * R;
      }
    }
    return cnt <= k;
  };
  ll low = 0, high = ll(1e9), ans = 0;
  while (low <= high) {
    ll mid = low + (high - low) / 2;
    if (check(mid)) {
      ans = mid;
      high = mid - 1;
    } else low = mid + 1;
  }
  cout << ans << endl;
  return 0;
}

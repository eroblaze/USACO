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
  // freopen("us.in", "r", stdin), freopen("us.out", "w", stdout);

  int64_t n, k;
  cin >> n >> k;
  vector<int64_t> a(n);
  for (int64_t i = 0; i < n; ++i) cin >> a[i];

  int64_t ans = 1 + k;

  for (int64_t i = 1; i < n; ++i) ans += min(a[i] - a[i - 1], 1 + k);

  cout << ans << '\n';

  return 0;
}

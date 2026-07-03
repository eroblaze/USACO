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
  freopen("loan.in", "r", stdin), freopen("loan.out", "w", stdout);
  ll n, k, m;
  cin >> n >> k >> m;

  auto check = [&](ll x) -> bool {
    ll tmp = n, steps = 0;
    while (tmp > 0) {
      ll curr = tmp / x;
      if (curr <= m) {
        steps += (tmp + m - 1) / m;
        break;
      }
      ll mn = curr * x;
      ll leeway = (tmp - mn + 1);
      ll times = (leeway + curr - 1) / curr;
      tmp -= times * curr;
      steps += times;
      if (steps > k) break;
    }
    return steps <= k;
  };

  ll low = 1, high = n, ans = 1;
  while (low <= high) {
    ll mid = low + (high - low) / 2;
    if (check(mid)) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  cout << ans << endl;

  return 0;
}


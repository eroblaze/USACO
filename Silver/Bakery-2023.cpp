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
  int tt;
  cin >> tt;
  while (tt--) {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<array<ll, 3>> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    auto highest = [&](ll x) -> ll {
      ll best = -1, low = 1, high = b;
      while (low <= high) {
        ll mid = low + (high - low) / 2;
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
          if (arr[i][0] * x + arr[i][1] * mid > arr[i][2]) {
            ok = 0;
            break;
          }
        }
        if (ok) {
          best = mid;
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      return best;
    };
    ll h = 1, low = 1, high = a;
    while (low <= high) {
      ll mid = low + (high - low) / 2;
      ll other = highest(mid);
      if (other != -1) {
        h = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    auto calc = [&](ll f, ll s) -> ll { return a - f + b - s; };
    ll ans = calc(h, highest(h));
    low = 1, high = h - 1;
    while (low <= high) {
      ll mid = low + (high - low) / 2;
      ll first = calc(mid, highest(mid)), second = calc(mid + 1, highest(mid + 1));
      if (first < second) {
        ans = min(ans, first);
        high = mid - 1;
      } else if (first > second) {
        low = mid + 1;
      } else {
        ll right_ptr = mid + 1;
        while (right_ptr <= high) {
          second = calc(right_ptr, highest(right_ptr));
          if (first != second) break;
          right_ptr++;
        }
        ans = min({ans, first, second});
        if (first > second) low = right_ptr;
        else high = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

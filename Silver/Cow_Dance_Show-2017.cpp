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
  freopen("cowdance.in", "r", stdin), freopen("cowdance.out", "w", stdout);
  ll n, T;
  cin >> n >> T;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  auto check = [&](int k) -> bool {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < k; ++i) pq.push(a[i]);
    ll mx = 0;
    int idx = k;
    while (!pq.empty()) {
      ll curr = pq.top();
      pq.pop();
      mx = curr;
      if (idx < n) {
        pq.push(curr + a[idx++]);
      }
    }
    return mx <= T;
  };
  int low = 1, high = n, ans = 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (check(mid)) {
      ans = mid;
      high = mid - 1;
    } else low = mid + 1;
  }
  cout << ans << endl;
  return 0;
}

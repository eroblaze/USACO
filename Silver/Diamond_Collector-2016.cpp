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
  freopen("diamond.in", "r", stdin), freopen("diamond.out", "w", stdout);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  vector<ll> pref(n), suff(n);
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j + 1 < n && a[j + 1] <= a[i] + k) ++j;
    suff[i] = j - i + 1;
  }
  for (int i = n - 2; i >= 0; --i) suff[i] = max(suff[i], suff[i + 1]);
  j = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    while (j - 1 >= 0 && a[j - 1] >= a[i] - k) --j;
    pref[i] = i - j + 1;
  }
  for (int i = 1; i < n; ++i) pref[i] = max(pref[i], pref[i - 1]);
  ll ans = 0;
  for (int i = 0; i < n; ++i) ans = max(ans, pref[i] + (i + 1 < n ? suff[i + 1] : 0));
  cout << ans << endl;
  return 0;
}

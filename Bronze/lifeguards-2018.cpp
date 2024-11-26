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
  freopen("lifeguards.in", "r", stdin), freopen("lifeguards.out", "w", stdout);

  int n;
  cin >> n;

  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) { cin >> a[i].first >> a[i].second; }
  sort(a.begin(), a.end());
  dbg(a);

  if (n == 1) cout << 0 << '\n';
  else {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int tmp = 0;
      int last = -1;

      for (int j = 0; j < n; ++j) {
        if (j == i) continue;
        if (last == -1) {
          tmp += a[j].second - a[j].first;
          last = a[j].second;
        } else {
          if (a[j].first < last) {
            tmp += a[j].second - a[j].first - (last - a[j].first);
            last = a[j].second;
          } else {
            tmp += a[j].second - a[j].first;
            last = a[j].second;
          }
        }
      }

      ans = max(ans, tmp);
    }
    cout << ans << '\n';
  }

  return 0;
}

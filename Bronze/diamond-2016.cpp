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
  freopen("diamond.in", "r", stdin), freopen("diamond.out", "w", stdout);

  int n = 0, k = 0, ans = 0;

  cin >> n >> k;

  vector<int> a(n);

  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  for (int i = 0; i < n; ++i) {
    int tmp = 1;
    for (int j = i + 1; j < n; ++j) {
      if (abs(a[i] - a[j]) <= k) ++tmp;
      else break;
    }
    ans = max(ans, tmp);
  }

  cout << ans << '\n';

  return 0;
}

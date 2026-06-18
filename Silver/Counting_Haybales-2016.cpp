#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("haybales.in", "r", stdin), freopen("haybales.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  while (q--) {
    int f, s;
    cin >> f >> s;
    auto it = upper_bound(a.begin(), a.end(), s);
    auto it2 = lower_bound(a.begin(), a.end(), f);
    cout << it - it2 << '\n';
  }

  return 0;
}

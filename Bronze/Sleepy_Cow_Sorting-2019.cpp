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
  freopen("sleepy.in", "r", stdin), freopen("sleepy.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int ans = 0;

  int last = 0;

  for (int i = 0; i < n - 1; ++i) {
    if (a[i] > a[i + 1]) {
      ans += (i + 1) - last;
      last = i + 1;
    }
  }

  cout << ans << endl;

  return 0;
}

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
  freopen("breedflip.in", "r", stdin), freopen("breedflip.out", "w", stdout);

  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  int ans = 0, cnt = 0;
  bool prev = 0;

  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      if (!prev) cnt = 1;
      prev = 1;
    } else {
      ans += cnt;
      prev = 0;
      cnt = 0;
    }
  }
  ans += cnt;

  cout << ans << '\n';

  return 0;
}

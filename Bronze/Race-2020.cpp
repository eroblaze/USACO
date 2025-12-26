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
  freopen("race.in", "r", stdin), freopen("race.out", "w", stdout);

  int64_t k, n;
  cin >> k >> n;

  int64_t ss = 1, idx = 2;
  while (ss < k) ss += idx++;
  --idx;

  for (int i = 0; i < n; ++i) {
    int64_t x;
    cin >> x;
    if (x >= idx) {
      cout << idx << '\n';
      continue;
    }

    int64_t to_x = (x * (x + 1)) / 2;
    to_x += x;

    int64_t ans = x + 1, last = x + 1;
    while (to_x < k) {
      to_x += last;
      if (to_x < k) {
        to_x += last;
        ++ans;
      }
      ++last;
      ++ans;
    }

    cout << ans << '\n';
  }

  return 0;
}

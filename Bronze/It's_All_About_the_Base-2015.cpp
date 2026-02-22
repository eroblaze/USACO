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
  freopen("whatbase.in", "r", stdin), freopen("whatbase.out", "w", stdout);

  int tt;
  cin >> tt;
  while (tt--) {
    string f, s;
    cin >> f >> s;

    int64_t n = int64_t(15e3);
    int64_t ans_x = 0, ans_y = 0;

    for (int64_t i = 10; i <= n; ++i) {
      int64_t v = ((f[0] - '0') * 1ll * (i * i)) + ((f[1] - '0') * 1ll * i) + (f[2] - '0');

      auto fnd_y = [&](int64_t y) {
        int64_t v2 = ((s[0] - '0') * 1ll * (y * y)) + ((s[1] - '0') * 1ll * y) + (s[2] - '0');
        return v2;
      };

      int64_t b = 9;
      for (int64_t k = n / 2; k >= 1; k /= 2) {
        while (b + k <= n && fnd_y(b + k) < v) {
          b += k;
        }
      }

      ++b;
      if (fnd_y(b) == v) {
        ans_x = i, ans_y = b;
        break;
      }
    }
    assert(ans_x >= 10 && ans_y >= 10);
    cout << ans_x << " " << ans_y << endl;
  }
  return 0;
}

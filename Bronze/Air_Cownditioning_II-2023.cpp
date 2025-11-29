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
  // freopen("bcs.in", "r", stdin), freopen("bcs.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> h(101, 0);

  for (int i = 0; i < n; ++i) {
    int s, t, c;
    cin >> s >> t >> c;

    for (; s <= t; ++s) h[s] = c;
  }

  vector<vector<int>> air(m);
  for (int i = 0; i < m; ++i) {
    int a, b, p, c;
    cin >> a >> b >> p >> c;
    air[i].insert(air[i].end(), {a, b, p, c});
  }

  int64_t ans = LLONG_MAX;

  for (int i = 1; i < (1 << m); ++i) {
    int64_t ss = 0;
    vector<int> h_cpy = h;

    for (int j = 0; j < m; ++j) {
      if (i & (1 << j)) {
        int a = air[j][0], b = air[j][1], p = air[j][2], c = air[j][3];
        ss += c;

        for (; a <= b; ++a) { h_cpy[a] = max(0, h_cpy[a] - p); }
      }
    }

    if (all_of(h_cpy.begin(), h_cpy.end(), [](int el) { return el == 0; })) { ans = min(ans, ss); }
  }

  cout << ans << '\n';

  return 0;
}

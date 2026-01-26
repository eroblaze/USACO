// @eroblaze
#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

pair<int, int> e[4];
int ans[3];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("promote.in", "r", stdin), freopen("promote.out", "w", stdout);

  for (int i = 0; i < 4; ++i) cin >> e[i].first >> e[i].second;

  int carry_over = 0;

  for (int i = 3; i >= 1; --i) {
    int diff = (e[i].second + carry_over) - e[i].first;
    ans[i - 1] = diff;
    carry_over = diff;
  }

  for (int i = 0; i < 3; ++i) cout << ans[i] << endl;

  return 0;
}

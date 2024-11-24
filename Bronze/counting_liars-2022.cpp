// @eroblaze
#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

const int inf = 1001;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> l, g;
  for (int i = 0; i < n; ++i) {
    char s;
    int val;
    cin >> s >> val;
    if (s == 'G') g.push_back(val);
    else l.push_back(val);
  }

  sort(l.begin(), l.end());
  sort(g.begin(), g.end());

  int ans = inf;

  for (int i = 0; i < (int)l.size(); ++i) {

    for (int j = 0; j < (int)g.size(); ++j) {
      if (g[j] <= l[i]) {
        int from_l = (int)l.size() - i;
        int from_g = j + 1;
        ans = min(ans, n - (from_l + from_g));
      } else break;
    }
  }

  for (int i = 0; i < (int)g.size(); ++i) {

    for (int j = 0; j < (int)l.size(); ++j) {
      if (l[j] >= g[i]) {
        int from_l = (int)l.size() - i;
        int from_g = i + 1;
        ans = min(ans, n - (from_l + from_g));
      } else break;
    }
  }

  if (ans == inf) ans = min((int)g.size(), (int)l.size());

  cout << ans << '\n';

  return 0;
}

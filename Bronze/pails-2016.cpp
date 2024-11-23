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
  freopen("pails.in", "r", stdin), freopen("pails.out", "w", stdout);

  int x, y, m;
  cin >> x >> y >> m;
  vector<int> entries;
  int a = m / x, b = m / y;

  int ans = 0;

  for (int i = 0; i < a; ++i) entries.push_back(x);
  for (int i = 0; i < b; ++i) entries.push_back(y);

  for (int i = 0; i < entries.size(); ++i) {
    int tmp = entries[i];
    for (int j = i + 1; j < entries.size(); ++j) {
      if (entries[j] + tmp <= m) tmp += entries[j];
    }
    ans = max(ans, tmp);
  }

  cout << ans << '\n';

  return 0;
}

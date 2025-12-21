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
  freopen("whereami.in", "r", stdin), freopen("whereami.out", "w", stdout);
  int n;
  cin >> n;
  string s;
  cin >> s;

  for (int i = 1; i <= n; ++i) {
    bool ok = 1;
    map<string, bool> mp;

    for (int j = 0; j + i <= n; ++j) {
      string tmp = s.substr(j, i);
      if (mp.count(tmp)) {
        ok = 0;
        break;
      }
      mp[tmp] = 1;
    }

    if (ok) {
      cout << i << '\n';
      exit(0);
    }
  }
  return 0;
}

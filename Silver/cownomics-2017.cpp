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
  freopen("cownomics.in", "r", stdin), freopen("cownomics.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<string> spotty(n), not_spotty(n);
  for (int i = 0; i < n; ++i) cin >> spotty[i];
  for (int i = 0; i < n; ++i) cin >> not_spotty[i];

  unordered_map<string, bool> mp;
  int ans = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      for (int k = j + 1; k < m; ++k) {
        for (string &s : spotty) {
          string form;
          form += s[i];
          form += s[j];
          form += s[k];

          mp[form] = 1;
        }
        bool ok = 1;

        for (string &s : not_spotty) {
          string form;
          form += s[i];
          form += s[j];
          form += s[k];

          if (mp[form]) {
            ok = 0;
            break;
          }
        }

        if (ok) ++ans;
        mp.clear();
      }
    }
  }

  cout << ans << '\n';

  return 0;
}

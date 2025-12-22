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
  freopen("citystate.in", "r", stdin), freopen("citystate.out", "w", stdout);
  int n;
  cin >> n;

  vector<pair<string, string>> arr(n);
  map<string, map<string, int>> mp;

  for (int i = 0; i < n; ++i) {
    string city, state;
    cin >> city >> state;

    mp[city.substr(0, 2)][state]++;
    arr[i] = {city, state};
  }

  int ans = 0;
  map<string, map<string, bool>> vis;

  for (pair<string, string> &p : arr) {
    string left = p.first.substr(0, 2), right = p.second;
    if (left == right) continue;
    if (mp[right].count(left) && !vis[right][left]) {
      ans += mp[right][left];
      vis[left][right] = 1;
    }
  }

  cout << ans << '\n';

  return 0;
}

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
  vector<vector<int>> a(m), b(m);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    for (int j = 0; j < m; ++j) { a[j].push_back(s[j]); }
  }
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    for (int j = 0; j < m; ++j) { b[j].push_back(s[j]); }
  }

  int ans = 0;

  for (int i = 0; i < m; ++i) {
    vector<int> intersect;
    sort(a[i].begin(), a[i].end());
    sort(b[i].begin(), b[i].end());

    set_intersection(a[i].begin(), a[i].end(), b[i].begin(), b[i].end(), back_inserter(intersect));
    if (intersect.size() == 0) ++ans;
  }

  cout << ans << '\n';

  return 0;
}

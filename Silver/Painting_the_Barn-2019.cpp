#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("paintbarn.in", "r", stdin), freopen("paintbarn.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  int N = 1000;
  vector<vector<int>> diff(N + 2, vector<int>(N + 2));
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1++, y1++;
    diff[x1][y1]++;
    diff[x1][y2 + 1]--;
    diff[x2 + 1][y1]--;
    diff[x2 + 1][y2 + 1]++;
  }
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
      if (diff[i][j] == k) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

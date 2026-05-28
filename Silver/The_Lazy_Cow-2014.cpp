#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

using ll = int64_t;
const int N = 1000;
ll pref[N][N];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("lazy.in", "r", stdin), freopen("lazy.out", "w", stdout);

  ll n, k;
  cin >> n >> k;
  vector<array<int, 2>> a;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int X = i + j, Y = i - j + n;
      cin >> pref[X][Y];
      a.push_back({X, Y});
    }
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
  }

  auto query = [&](int x1, int y1, int x2, int y2) -> ll {
    x1 = max(x1, 1);
    y1 = max(y1, 1);
    x2 = min(x2, N - 1);
    y2 = min(y2, N - 1);
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
  };
  ll ans = 0;
  for (array<int, 2>& ar : a) {
    ans = max(ans, query(ar[0] - k, ar[1] - k, ar[0] + k, ar[1] + k));
  }
  cout << ans << endl;

  return 0;
}

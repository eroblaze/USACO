// @eroblaze
#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int a[int(1e6)], b[int(1e6)];
bool vis[int(1e6)];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  // freopen("us.in", "r", stdin), freopen("us.out", "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  int ans = 0, idx = 0;

  for (int i = 0; i < n; ++i) {
    if (vis[a[idx]]) {
      while (vis[a[idx]]) ++idx;
    }

    if (a[idx] != b[i]) {
      ++ans;
    } else ++idx;
    vis[b[i]] = 1;
  }

  cout << ans << endl;

  return 0;
}

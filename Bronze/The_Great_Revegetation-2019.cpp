// @eroblaze
#include <bits/stdc++.h>
// #include "../PCH.h"
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int ans[101];
int cows[151];
vector<int> pastures[101];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("revegetate.in", "r", stdin), freopen("revegetate.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    cows[i] = a + b;

    pastures[a].push_back(i);
    pastures[b].push_back(i);
  }

  ans[1] = 1;

  for (int i = 2; i <= n; ++i) {
    vector<bool> entry(5);
    for (int c : pastures[i]) { entry[ans[cows[c] - i]] = 1; }

    for (int k = 1; k <= 4; ++k) {
      if (!entry[k]) {
        ans[i] = k;
        break;
      }
    }
  }

  for (int i = 1; i <= n; ++i) { cout << ans[i]; }
  return 0;
}
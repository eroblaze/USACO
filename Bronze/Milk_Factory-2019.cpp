// @eroblaze
#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

const int N = 101;
vector<int> adj[N];

bool dfs(int source, int target) {
  if (source == target) return 1;

  for (int neighbor : adj[source]) {
    bool ret = dfs(neighbor, target);
    if (ret) return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("factory.in", "r", stdin), freopen("factory.out", "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  int ans = -1;

  for (int i = 1; i <= n; ++i) {

    bool ok = 1;
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (!dfs(j, i)) {
        ok = 0;
        break;
      }
    }

    if (ok) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}

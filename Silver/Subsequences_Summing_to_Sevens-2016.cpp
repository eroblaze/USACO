#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("div7.in", "r", stdin), freopen("div7.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> seen(7, -1);
  seen[0] = 0;
  int curr = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    curr = ((curr + a[i]) % 7 + 7) % 7;
    if (seen[curr] == -1) seen[curr] = i;
    else {
      ans = max(ans, i - seen[curr]);
    }
  }
  cout << ans << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("convention.in", "r", stdin), freopen("convention.out", "w", stdout);
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  auto check = [&](int wait) -> bool {
    int end = a[0] + wait, buses = 1, cnt = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] > end || cnt + 1 > c) {
        ++buses;
        cnt = 1;
        end = a[i] + wait;
        continue;
      }
      ++cnt;
    }
    return buses <= m;
  };
  int low = 0, high = int(1e9), ans = 0;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (check(mid)) {
      ans = mid;
      high = mid - 1;
    } else low = mid + 1;
  }
  cout << ans << endl;
  return 0;
}

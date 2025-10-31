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
  // freopen("usaco.in", "r", stdin), freopen("usaco.out", "w", stdout);

  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for (int i = 0; i < N; ++i) cin >> a[i];
  for (int i = 0; i < N; ++i) cin >> b[i];

  int tot_correct = 0;
  for (int i = 0; i < N; ++i)
    if (a[i] == b[i]) tot_correct++;

  vector<int> ans(N + 1);

  auto expand = [&](int left, int right) {
    int remove = 0, add = 0;

    while (left >= 0 && right < N) {
      // we can expand
      remove += (a[left] == b[left]) + (a[right] == b[right]);
      add += (a[left] == b[right]) + (a[right] == b[left]);

      ans[tot_correct + add - remove]++;

      --left, ++right;
    }
  };

  for (int i = 0; i < N; ++i) {
    // odd centers
    expand(i, i);
    // even centers
    expand(i, i + 1);
  }

  for (int i = 0; i <= N; ++i) cout << ans[i] << '\n';

  return 0;
}

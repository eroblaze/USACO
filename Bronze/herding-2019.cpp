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
  freopen("herding.in", "r", stdin), freopen("herding.out", "w", stdout);

  array<int, 3> ar;
  for (int i = 0; i < 3; ++i) cin >> ar[i];
  sort(ar.begin(), ar.end());
  int mini = min(ar[1] - ar[0], ar[2] - ar[1]) - 1;
  int maxi = max(ar[1] - ar[0], ar[2] - ar[1]) - 1;

  cout << (!mini && !maxi ? 0 : mini == 1 ? 1 : 2) << '\n';
  cout << maxi << '\n';

  return 0;
}

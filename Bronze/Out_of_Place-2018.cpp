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
  freopen("outofplace.in", "r", stdin), freopen("outofplace.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> arr(n);
  map<int, int> f, l;
  int pos = -1, prev = 0;

  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    if (i != 0) {
      if (tmp < prev) { pos = i; }
    }

    prev = tmp;
    if (!f.count(tmp)) f[tmp] = i;
    l[tmp] = i;

    arr[i] = tmp;
  }

  assert(pos != -1);

  int ans = 0;

  if (!(pos + 1 < n) || arr[pos + 1] >= arr[pos - 1]) {
    for (int i = pos - 1; i >= 0; --i) {
      if (arr[i] > arr[pos]) {
        i = f[arr[i]];
        ++ans;
      } else break;
    }
  } else {
    --pos;
    for (int i = pos + 1; i < n; ++i) {
      if (arr[i] < arr[pos]) {
        i = l[arr[i]];
        ++ans;
      } else break;
    }
  }

  cout << ans << '\n';

  return 0;
}

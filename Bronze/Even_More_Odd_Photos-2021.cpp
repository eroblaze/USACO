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
  // freopen("outofplace.in", "r", stdin), freopen("outofplace.out", "w", stdout);

  int n;
  cin >> n;
  int even = 0, odd = 0;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    if (tmp % 2 == 0) ++even;
    else ++odd;
  }

  int ans = 0;
  bool turn = 1;
  while (1) {
    if (turn) {
      if (even == 0) {
        if (odd < 2) break;
        odd -= 2;
      } else {
        --even;
      }
    } else {
      if (odd == 0) break;
      --odd;
    }
    turn = !turn;
    ++ans;
  }

  if (odd != 0) --ans;

  cout << ans << '\n';

  return 0;
}

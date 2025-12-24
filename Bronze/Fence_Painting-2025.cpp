// @eroblaze
#include <atomic>
#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("paint.in", "r", stdin), freopen("paint.out", "w", stdout);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if ((d >= a && d <= b) || (d >= b && c <= b)) cout << (max(b, d) - min(a, c)) << '\n';
  else cout << ((b - a) + d - c) << '\n';
  return 0;
}

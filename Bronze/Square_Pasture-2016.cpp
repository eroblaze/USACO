// @eroblaze
#include <bits/stdc++.h>
// #include "../PCH.h"
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int first[4], second[4];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("square.in", "r", stdin), freopen("square.out", "w", stdout);

  for (int i = 0; i < 4; ++i) cin >> first[i];
  for (int i = 0; i < 4; ++i) cin >> second[i];

  int ans =
      max(max(first[2], second[2]) - min(first[0], second[0]), max(first[3], second[3]) - min(first[1], second[1]));

  cout << ans * ans << endl;

  return 0;
}

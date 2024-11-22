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
  freopen("traffic.in", "r", stdin), freopen("traffic.out", "w", stdout);

  int n;
  cin >> n;

  vector<tuple<string, int, int>> readings;
  int first_none = -1, last_none = 0;

  for (int i = 0; i < n; ++i) {
    int lower, upper;
    string what;
    cin >> what >> lower >> upper;

    if (first_none == -1 && what == "none") first_none = i;
    if (what == "none") last_none = i;

    readings.push_back({what, lower, upper});
  }

  int b_l = get<1>(readings[last_none]);
  int b_u = get<2>(readings[last_none]);

  for (int i = last_none - 1; i >= 0; --i) {
    int lower, upper;
    string what;
    tie(what, lower, upper) = readings[i];

    if (what == "off") {
      b_l += lower;
      b_u += upper;
    } else if (what == "on") {
      b_u = max(0, b_u - lower);
      b_l = max(0, b_l - upper);
    } else {
      // "none"
      b_u = min(b_u, upper);
      b_l = max(b_l, lower);
    }
  }

  cout << b_l << " " << b_u << '\n';

  b_l = get<1>(readings[first_none]);
  b_u = get<2>(readings[first_none]);

  for (int i = first_none + 1; i < n; ++i) {
    int lower, upper;
    string what;
    tie(what, lower, upper) = readings[i];

    if (what == "off") {
      int bound = b_u - b_l;
      b_l = max(b_l - upper, 0);
      b_u = max(bound, b_u - lower);
    } else if (what == "on") {
      b_u += upper;
      b_l += lower;
    } else {
      // none
      b_u = min(b_u, upper);
      b_l = max(b_l, lower);
    }
  }

  cout << b_l << " " << b_u << '\n';

  return 0;
}

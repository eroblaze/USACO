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
  freopen("bcount.in", "r", stdin), freopen("bcount.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  vector<int> one(n + 1), two(n + 1), three(n + 1);
  for (int i = 1; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    if (tmp == 1) {
      one[i] = 1;
    } else if (tmp == 2) {
      two[i] = 1;
    } else {
      three[i] = 1;
    }
  }

  vector<int> p_one(n + 1), p_two(n + 1), p_three(n + 1);
  partial_sum(one.begin(), one.end(), p_one.begin());
  partial_sum(two.begin(), two.end(), p_two.begin());
  partial_sum(three.begin(), three.end(), p_three.begin());

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << p_one[r] - p_one[l - 1] << " " << p_two[r] - p_two[l - 1] << " " << p_three[r] - p_three[l - 1] << '\n';
  }

  return 0;
}

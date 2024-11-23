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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int ans = n;

  for (int i = 0; i < n; ++i) {
    int curr_sum = a[i];

    for (int j = i + 1; j < n; ++j) {
      curr_sum += a[j];
      int div = j - i + 1;

      if (curr_sum % div == 0) {
        int r = curr_sum / div;

        for (int k = i; k <= j; ++k) {
          if (a[k] == r) {
            ++ans;
            break;
          }
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}

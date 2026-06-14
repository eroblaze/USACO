#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

using ll = int64_t;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), cnt(n + 1);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    cnt[b[i]]++;
  }
  vector<array<int, 2>> new_a(n), new_b(n);
  for (int i = 0; i < n; ++i) {
    new_a[i] = {a[i], min(i, n - i - 1)};
    new_b[i] = {b[i], min(i, n - i - 1)};
  }
  sort(new_a.begin(), new_a.end(), [](auto& f, auto& s) {
    if (f[0] == s[0]) {
      return f[1] < s[1];
    }
    return f[0] < s[0];
  });
  sort(new_b.begin(), new_b.end(), [](auto& f, auto& s) {
    if (f[0] == s[0]) {
      return f[1] < s[1];
    }
    return f[0] < s[0];
  });
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      ll left = (i * 1ll * (i + 1)) / 2;
      ll right = ((n - i) * 1ll * (n - i - 1)) / 2;
      ans += left + right;
    }
  }
  ll curr_sum = 0, j = 0, curr_cnt = 0, prev = -1;
  for (int i = 0; i < n; ++i) {
    if (new_a[i][0] != prev) curr_sum = 0, curr_cnt = 0;

    while (j >= 0 && j < n && new_b[j][0] < new_a[i][0]) ++j;
    while (j < n && new_b[j][0] == new_a[i][0] && new_b[j][1] <= new_a[i][1]) {
      curr_sum += new_b[j][1];
      ++curr_cnt;
      ++j;
    }
    ans += curr_sum + curr_cnt + cnt[new_a[i][0]] - curr_cnt;
    ans += (cnt[new_a[i][0]] - curr_cnt) * new_a[i][1];
    prev = new_a[i][0];
  }

  cout << ans << endl;
  return 0;
}

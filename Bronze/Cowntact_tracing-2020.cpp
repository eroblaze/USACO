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
  freopen("tracing.in", "r", stdin), freopen("tracing.out", "w", stdout);

  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;

  vector<array<int, 3>> arr;
  map<int, int> mp;

  for (int i = 0; i < t; ++i) {
    int time, a, b;
    cin >> time >> a >> b;
    --a, --b;

    arr.push_back({time, a, b});
    if (s[a] == '1') {
      if (mp.count(a)) mp[a] = min(mp[a], time);
      else mp[a] = time;
    }
    if (s[b] == '1') {
      if (mp.count(b)) mp[b] = min(mp[b], time);
      else mp[b] = time;
    }
  }

  sort(arr.begin(), arr.end());

  int x = 0, final_y = INT_MAX, final_z = -1;

  for (int i = 0; i < n; ++i) {

    if (s[i] == '1') {

      int l = 0;
      for (int k = (t + 1) / 2; k >= 1; k /= 2) {
        while (l + k < t && arr[l + k][0] <= mp[i]) l += k;
      }

      int minimum_k = INT_MAX, maximum_k = 0;
      bool fnd = 0;

      // brute force all possible values of k,
      // if there is no k which works, i is not a patient 0
      for (int k = 0; k <= t; ++k) {
        string s_tmp(n, '0');
        s_tmp[i] = '1';

        bool ok = 1;

        map<int, int> k_left;
        for (int fill = 0; fill < n; ++fill)
          if (s[fill] == '1') k_left[fill] = k;

        // start the operations from position l in the arr interactions
        for (int l_tmp = l; l_tmp < t; ++l_tmp) {
          int a = arr[l_tmp][1], b = arr[l_tmp][2];

          if (s_tmp[a] == '1') {
            if (s_tmp[b] == '0') {
              if (s[b] == '0') {
                if (k_left[a] != 0) {
                  ok = 0;
                  break;
                }
              } else {
                if (k_left[a] > 0) {
                  s_tmp[b] = '1';
                  k_left[a]--;
                }
              }
            } else {
              if (k_left[a] > 0) k_left[a]--;
              if (k_left[b] > 0) k_left[b]--;
            }
          } else {
            if (s_tmp[b] == '1') {
              if (s[a] == '0') {
                if (k_left[b] != 0) {
                  ok = 0;
                  break;
                }
              } else {
                if (k_left[b] > 0) {
                  s_tmp[a] = '1';
                  k_left[b]--;
                }
              }
            }
          }

          if (!ok) break;
        }

        if (!ok || s_tmp != s) continue;
        fnd = 1;
        minimum_k = min(minimum_k, k);
        maximum_k = max(maximum_k, k);
      }

      if (!fnd) continue;
      ++x;
      final_y = min(final_y, minimum_k);
      if (final_z != t) final_z = max(final_z, maximum_k);
    }
  }

  assert(x > 0);

  cout << x << " " << (final_y == INT_MAX ? 0 : final_y) << " ";

  final_z = (final_z == t) ? -1 : final_z;
  if (final_z == -1) cout << "Infinity" << '\n';
  else cout << final_z << '\n';

  return 0;
}

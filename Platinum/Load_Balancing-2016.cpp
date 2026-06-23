#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

using indexed_multiset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("balancing.in", "r", stdin), freopen("balancing.out", "w", stdout);
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  const int N = int(1e6);
  vector<int> Y(N + 1);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a[i] = {x, y};
    Y[y]++;
  }
  sort(a.begin(), a.end());
  for (int i = 1; i <= N; ++i) Y[i] += Y[i - 1];
  indexed_multiset st;
  int ans = INT_MAX, idx = 0;
  for (int i = 0; i < n; ++i) {
    st.insert({a[i][1], idx++});
    while (i + 1 < n && a[i + 1][0] == a[i][0]) {
      ++i;
      st.insert({a[i][1], idx++});
    }
    int l = 1, h = N;
    while (l <= h) {
      int mid = l + (h - l) / 2;
      int bottom_left = st.order_of_key({mid + 1, 0});
      int top_left = i + 1 - bottom_left;
      int bottom_right = Y[mid] - bottom_left;
      int top_right = n - bottom_left - top_left - bottom_right;
      int mx_top = max(top_left, top_right);
      int mx_bottom = max(bottom_left, bottom_right);

      ans = min(ans, max(mx_top, mx_bottom));
      if (mx_top == mx_bottom) break;
      if (mx_top > mx_bottom) {
        l = mid + 1;
      } else {
        h = mid - 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}

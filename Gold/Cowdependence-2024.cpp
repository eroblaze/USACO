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
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    mp[tmp].push_back(i);
  }
  vector<int> ans(n + 2);
  auto fn = [&](int label, int x) -> int {
    vector<int>& indices = mp[label];
    int ret = 1, end = indices[0] + x;
    for (int i = 1; i < (int)indices.size(); ++i) {
      if (indices[i] <= end) continue;
      ++ret;
      end = indices[i] + x;
    }
    return ret;
  };
  auto solve = [&](auto self, int label, int low, int high) -> void {
    int cnt1 = fn(label, low), cnt2 = fn(label, high);
    if (cnt1 == cnt2) {
      ans[low] += cnt1, ans[high + 1] -= cnt1;
      return;
    }
    int mid = low + (high - low) / 2;
    self(self, label, low, mid);
    self(self, label, mid + 1, high);
  };
  for (auto& [label, _] : mp) {
    solve(solve, label, 1, n);
  }
  for (int i = 1; i <= n; ++i) {
    ans[i] += ans[i - 1];
    cout << ans[i] << '\n';
  }
  return 0;
}

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
  // freopen("us.in", "r", stdin), freopen("us.out", "w", stdout);

  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> arr;
  for (int i = 0; i < n; i += 2) {
    if (s[i] == s[i + 1]) continue;
    if (s[i] == 'G' && s[i + 1] == 'H') arr.push_back(1);
    else arr.push_back(0);
  }

  dbg(arr);
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  dbg(arr);

  int ans = 0;

  for (int i = arr.size() - 1; i >= 0; --i) {
    if (arr[i] == 1) {
      ans = i + 1;
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}

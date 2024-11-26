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
  freopen("circlecross.in", "r", stdin), freopen("circlecross.out", "w", stdout);

  string s;
  cin >> s;
  map<char, vector<int>> mp;
  int ans = 0;

  for (int i = 0; i < s.size(); ++i) { mp[s[i]].push_back(i); }
  for (int i = 0; i < s.size(); ++i) {
    char curr = s[i];
    if (mp[curr][0] == i) {
      for (int j = i + 1; j < mp[curr][1]; ++j) {
        if (mp[s[j]][1] > mp[curr][1]) ++ans;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}

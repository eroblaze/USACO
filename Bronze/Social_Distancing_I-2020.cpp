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
  freopen("socdist1.in", "r", stdin), freopen("socdist1.out", "w", stdout);

  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> p, edges;
  int mn = INT_MAX;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      int l = i;
      while (i < n && s[i] == '0') {
        ++i;
      }
      --i;
      int cnt = (i - l) + 1;
      if (l == 0 || i == n - 1)
        edges.push_back(cnt);
      else
        p.push_back(cnt);

      if (l > 0 && i < n - 1) mn = min(mn, i + 1 - l + 1);
    } else {
      int l = i;
      while (i < n && s[i] == '1') {
        ++i;
      }
      --i;
      if ((i - l) + 1 > 1) mn = 1;
    }
  }
  sort(p.begin(), p.end(), greater<int>());
  sort(edges.begin(), edges.end(), greater<int>());

  // take the 2 from the first
  // take 1 from the first, 1 from the second
  // take from the edges
  vector<int> ans;
  if (!p.empty()) {
    // take the 2 from the first -> (cnt+1)/3
    if (p[0] > 1) {
      ans.push_back((p[0] + 1) / 3);
    }
    // take 1 from the first -> (cnt+1)/2 and the other from the second
    if (p.size() > 1) {
      ans.push_back(min((p[0] + 1) / 2, (p[1] + 1) / 2));
    }
  }

  if (!edges.empty()) {
    // Take 1 -> cnt
    // Take 2 -> (cnt+1)/2

    // take 2 from the first
    if (edges[0] > 1) {
      ans.push_back((edges[0] + 1) / 2);
    }
    // take 1 from the first and the other from the second
    if (edges.size() > 1) {
      ans.push_back(min(edges[0], edges[1]));
    }
    // take 1 from the edges and the other not from edges
    if (!p.empty()) {
      ans.push_back(min((p[0] + 1) / 2, edges[0]));
    }

    // if the whole string is 0
    if ((int)edges.size() == 1 && p.empty() && edges[0] == n) {
      ans.push_back(n - 1);
    }
  }

  cout << max(1, min(*max_element(ans.begin(), ans.end()), mn)) << '\n';

  return 0;
}

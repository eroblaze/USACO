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
  // USACO
  freopen("badmilk.in", "r", stdin), freopen("badmilk.out", "w", stdout);

  int n, m, d, s;
  cin >> n >> m >> d >> s;

  unordered_map<int, set<int>> st;
  unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> mp;

  for (int i = 0; i < d; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    mp[a].push({c, b});
    st[b].insert(a);
  }

  vector<vector<int>> v(51);

  for (int i = 0; i < s; ++i) {
    int p, t;
    cin >> p >> t;

    auto pq = mp[p];
    while (!pq.empty() && pq.top().first < t) {
      v[p].push_back(pq.top().second);
      pq.pop();
    }
  }

  vector<int> prev;

  for (int i = 1; i < 51; ++i) {
    if (v[i].size()) {
      if (prev.size() == 0) {
        // first time
        prev = v[i];
        continue;
      }
      vector<int> tmp;
      sort(prev.begin(), prev.end());
      sort(v[i].begin(), v[i].end());
      set_intersection(prev.begin(), prev.end(), v[i].begin(), v[i].end(), back_inserter(tmp));
      prev = tmp;
    }
  }

  set<int> ans;
  for (int el : prev) { ans.merge(st[el]); }
  cout << ans.size() << '\n';
  return 0;
}

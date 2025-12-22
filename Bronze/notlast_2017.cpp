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
  freopen("notlast.in", "r", stdin), freopen("notlast.out", "w", stdout);

  int n;
  cin >> n;

  map<string, int> cnt;
  for (int i = 0; i < n; ++i) {
    string name;
    int p;
    cin >> name >> p;
    cnt[name] += p;
  }

  set<int> pro;
  map<int, vector<string>> mp;

  for (auto &[k, v] : cnt) {
    pro.insert(v);
    mp[v].push_back(k);
  }

  int el = cnt.size() == 7 ? *next(pro.begin()) : *pro.begin();
  if ((pro.size() == 1 && mp.size() == 7) || mp[el].size() > 1) {
    cout << "Tie" << '\n';
  } else {
    cout << mp[el].front() << '\n';
  }

  return 0;
}

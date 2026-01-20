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
  freopen("evolution.in", "r", stdin), freopen("evolution.out", "w", stdout);

  int n;
  cin >> n;
  map<string, int> cnt;
  vector<vector<string>> arr(n);

  for (int i = 0; i < n; ++i) {
    int sz;
    cin >> sz;

    vector<string> tmp;
    while (sz--) {
      string s;
      cin >> s;
      cnt[s]++;
      tmp.push_back(s);
    }

    arr[i] = tmp;
  }

  for (vector<string> &b : arr) {
    sort(b.begin(), b.end(), [&](string a, string c) { return cnt[a] > cnt[c]; });
  }

  sort(arr.begin(), arr.end(), [](vector<string> &a, vector<string> &b) { return (int)a.size() > (int)b.size(); });
  map<string, string> par;
  for (int i = 0; i < (int)arr.front().size(); ++i) {
    if (i == 0) par[arr[0][i]] = arr[0][i];
    else { par[arr[0][i]] = arr[0][i - 1]; }
  }

  bool ok = 1;

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < (int)arr[i].size(); ++j) {
      string p = arr[i][j];
      if (j >= 1) p = arr[i][j - 1];

      if (par.count(arr[i][j])) {
        if (par[arr[i][j]] != p) {
          ok = 0;
          break;
        }
      } else {
        par[arr[i][j]] = p;
      }

      if (j > 0) assert(arr[i][j] != arr[i][j - 1]);
    }

    if (!ok) break;
  }

  cout << (ok ? "yes" : "no") << endl;

  return 0;
}

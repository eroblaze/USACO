// @eroblaze
#include <bits/stdc++.h>
// #include "../PCH.h"
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

string l, r;
map<string, int> mp;

void dfs(string root, map<string, vector<string>> &adj, bool fnd_other, int curr) {
  bool you_are = (root == l || root == r) ? true : false;
  if (you_are) {
    mp[root] = curr;

    if (mp.count(l) && mp.count(r)) {
      string maxi, mini;
      if (mp[r] < mp[l]) {
        maxi = r, mini = l;
      } else {
        maxi = l, mini = r;
      }

      if (fnd_other) {
        int sz = max(mp[r], mp[l]) - min(mp[r], mp[l]);

        if (sz == 1) {
          cout << maxi << " is the mother of " << mini << endl;
        } else if (sz == 2) {
          cout << maxi << " is the grand-mother of " << mini << endl;
        } else {
          string s = "grand-mother";
          for (int i = 0; i < sz - 2; ++i) { s = "great-" + s; }
          cout << maxi << " is the " << s << " of " << mini << endl;
        }

      } else {
        int mxn = max(mp[r], mp[l]), mm = min(mp[r], mp[l]);

        if (mm > 1) {
          cout << "COUSINS" << endl;
        } else {
          if (mxn == mm) {
            cout << "SIBLINGS" << endl;
          } else if (mxn == 2) {
            cout << maxi << " is the aunt of " << mini << endl;
          } else {
            string s = "aunt";
            for (int i = 0; i < mxn - 2; ++i) { s = "great-" + s; }
            cout << maxi << " is the " << s << " of " << mini << endl;
          }
        }
      }
      exit(0);
    }

    fnd_other = 1;
  }

  for (string child : adj[root]) { dfs(child, adj, fnd_other, curr + 1); }
}

void dfs2(string root, map<string, vector<string>> &adj, int dist) {
  if (root == r || root == l) { mp[root] = dist; }
  for (string s : adj[root]) dfs2(s, adj, dist + 1);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("family.in", "r", stdin), freopen("family.out", "w", stdout);

  int n;
  cin >> n;
  cin >> l >> r;
  map<string, vector<string>> adj;

  for (int i = 0; i < n; ++i) {
    string left, right;
    cin >> left >> right;

    adj[left].push_back(right);
  }

  string lca;
  int mxn = 1e9;
  for (auto &[k, v] : adj) {
    dfs2(k, adj, 0);
    if (mp.count(r) && mp.count(l)) {
      int ret = mp[r] + mp[l];
      if (ret < mxn) {
        mxn = ret;
        lca = k;
      }
    }
    mp.clear();
  }

  if (lca.empty()) cout << "NOT RELATED" << endl;
  else { dfs(lca, adj, false, 0); }
  return 0;
}
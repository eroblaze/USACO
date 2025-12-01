// @eroblaze
#include <bits/stdc++.h>
// #include "../PCH.h"
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("backforth.in", "r", stdin), freopen("backforth.out", "w", stdout);

  vector<int> a(10), b(10);
  for (int i = 0; i < 10; ++i) cin >> a[i];
  for (int i = 0; i < 10; ++i) cin >> b[i];

  set<int> st;

  for (int i = 0; i < 10; ++i) {
    vector<int> a_tmp = a, b_tmp = b;

    int curr = 1000 - a_tmp[i];
    b_tmp.push_back(a_tmp[i]);

    a_tmp.erase(a_tmp.begin() + i);

    for (int j = 0; j < 11; ++j) {
      int v1 = b_tmp[j];
      a_tmp.push_back(v1);
      curr += v1;

      b_tmp.erase(b_tmp.begin() + j);

      for (int k = 0; k < 10; ++k) {
        int v2 = a_tmp[k];
        b_tmp.push_back(v2);
        curr -= v2;

        a_tmp.erase(a_tmp.begin() + k);

        for (int l = 0; l < 11; ++l) { st.insert(curr + b_tmp[l]); }

        a_tmp.insert(a_tmp.begin() + k, v2);
        b_tmp.erase(b_tmp.end() - 1);

        curr += v2;
      }

      b_tmp.insert(b_tmp.begin() + j, v1);
      a_tmp.erase(a_tmp.end() - 1);

      curr -= v1;
    }
  }

  cout << (int)st.size() << '\n';

  return 0;
}

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
  // freopen("whereami.in", "r", stdin), freopen("whereami.out", "w", stdout);

  int n, f;
  cin >> n >> f;
  string s;
  cin >> s;
  map<string, int> freq;
  for (int i = 0; i + 2 < n; ++i) freq[s.substr(i, 3)]++;

  map<string, map<string, int>> bad;
  for (int i = 0; i + 2 < n; ++i) {
    string tmp = s.substr(i, 3);

    if (tmp[1] == tmp[2] && tmp[0] != tmp[1]) {
      if (i - 2 >= 0) bad[tmp][s.substr(i - 2, 3)]++;
      if (i - 1 >= 0) bad[tmp][s.substr(i - 1, 3)]++;
      if (i + 3 < n) bad[tmp][s.substr(i + 1, 3)]++;
      if (i + 4 < n) bad[tmp][s.substr(i + 2, 3)]++;
    }
  }

  set<string> ans, ones;

  for (int i = 0; i + 2 < n; ++i) {
    string tmp = s.substr(i, 3);
    if (ans.count(tmp)) continue;

    if (f == 1) {
      if (tmp[1] == tmp[2]) {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
          if (ch == tmp[1]) continue;

          string ss = ch + tmp.substr(1);
          ans.insert(ss);
        }
      } else {
        if (tmp[0] == tmp[1]) {
          string ss = tmp.substr(0, 1) + tmp.substr(2, 1) + tmp.substr(2, 1);
          ones.insert(ss);
        } else if (tmp[0] == tmp[2]) {
          string ss = tmp.substr(0, 1) + tmp.substr(1, 1) + tmp.substr(1, 1);
          ones.insert(ss);
        } else {
          string ss = tmp.substr(0, 1) + tmp.substr(1, 1) + tmp.substr(1, 1);
          string ss2 = tmp.substr(0, 1) + tmp.substr(2, 2) + tmp.substr(2, 2);
          ones.insert(ss);
          ones.insert(ss2);
        }
      }
      continue;
    }

    if (tmp[1] == tmp[2] && tmp[0] != tmp[1]) {
      if (freq[tmp] >= f) ans.insert(tmp);
      else if (freq[tmp] == f - 1) {
        // try to find something that can work
        bool ok = 0;

        // *pp
        for (char ch = 'a'; ch <= 'z'; ++ch) {
          if (ch == tmp[0]) continue;

          string to_find = ch + tmp.substr(1);
          if (freq.count(to_find) && freq[to_find] > bad[tmp][to_find]) {
            ok = 1;
            break;
          }
        }

        // o*p
        for (char ch = 'a'; ch <= 'z'; ++ch) {
          if (ch == tmp[1]) continue;

          string to_find = tmp.substr(0, 1) + ch + tmp.substr(2);
          if (freq.count(to_find) && freq[to_find] > bad[tmp][to_find]) {
            ok = 1;
            break;
          }
        }

        // op*
        for (char ch = 'a'; ch <= 'z'; ++ch) {
          if (ch == tmp[2]) continue;

          string to_find = tmp.substr(0, 2) + ch;
          if (freq.count(to_find) && freq[to_find] > bad[tmp][to_find]) {
            ok = 1;
            break;
          }
        }

        if (ok) ans.insert(tmp);
      }
    }
  }

  for (string el : ones) ans.insert(el);
  cout << (int)ans.size() << '\n';
  for (string el : ans) cout << el << '\n';

  return 0;
}

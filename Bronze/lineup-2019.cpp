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
  freopen("lineup.in", "r", stdin), freopen("lineup.out", "w", stdout);

  int n;
  cin >> n;

  vector<pair<string, string>> order;

  for (int i = 0; i < n; ++i) {
    string f, l, tmp;
    cin >> f;
    cin >> tmp, cin >> tmp, cin >> tmp, cin >> tmp;
    cin >> l;

    order.push_back({f, l});
  }

  vector<string> arr = {"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", "Blue", "Bella", "Buttercup"};
  sort(arr.begin(), arr.end());

  do {
    bool ok = 1;

    for (pair<string, string> o : order) {

      for (int i = 0; i < 8; ++i) {
        if (arr[i] == o.first) {
          if (i == 0) {
            if (arr[1] != o.second) {
              ok = 0;
              break;
            }
          } else if (i == 7) {
            if (arr[6] != o.second) {
              ok = 0;
              break;
            }
          } else {
            if (!(arr[i - 1] == o.second) && !(arr[i + 1] == o.second)) {
              ok = 0;
              break;
            }
          }
        }
      }

      if (!ok) break;
    }

    if (ok) break;
  } while (next_permutation(arr.begin(), arr.end()));

  for (string s : arr) cout << s << '\n';

  return 0;
}

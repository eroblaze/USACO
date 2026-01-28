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
  freopen("taming.in", "r", stdin), freopen("taming.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int> fnd;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    arr[i] = tmp;
    if (tmp > 0) fnd.push_back(i);
  }
  assert(arr.front() == -1 || arr.front() == 0);

  bool ok = 1;
  for (int idx : fnd) {
    int curr = arr[idx];

    for (int i = idx - 1; i >= 0; --i) {
      if (arr[i] != curr - 1) {
        if (arr[i] != -1) {
          ok = 0;
          break;
        }
      }

      arr[i] = curr - 1;

      if (curr - 1 == 0) break;
      --curr;
    }

    if (!ok) break;
  }

  if (!ok) {
    cout << -1 << endl;
    exit(0);
  }

  int mini = 1, mxn = 1;
  for (int i = 1; i < n; ++i) {
    if (arr[i] == 0) {
      ++mini;
    }
    if (arr[i] == 0 || arr[i] == -1) ++mxn;
  }

  cout << mini << " " << mxn << endl;

  return 0;
}

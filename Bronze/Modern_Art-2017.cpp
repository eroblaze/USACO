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
  freopen("art.in", "r", stdin), freopen("art.out", "w", stdout);

  int n;
  cin >> n;

  vector<string> arr(n);
  map<char, int> first, last, height;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    arr[i] = s;
  }

  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    string s = arr[i];

    for (int j = 0; j < n; ++j) {
      if (s[j] == '0') continue;

      char curr = s[j];
      if (first.count(curr)) {
        first[curr] = min(first[curr], j);
      } else {
        cnt++;
        first[curr] = j;
      }

      last[curr] = max(last[curr], j);

      for (int k = i + 1; k < n; ++k) {
        if (arr[k][j] == curr) {
          height[curr] = max(height[curr], k);
        }
      }
    }
  }

  map<char, bool> wrong;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (arr[i][j] == '0') continue;

      char curr = arr[i][j];
      int start = first[curr], finish = last[curr];

      for (int l = i; l <= height[curr]; ++l) {
        string s = arr[l];
        for (int k = start; k <= finish; ++k) {
          if (s[k] != curr) wrong[s[k]] = 1;
        }
      }

      j = finish;
    }
  }

  cout << cnt - (int)wrong.size() << endl;

  return 0;
}

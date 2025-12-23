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
  // freopen("herding.in", "r", stdin), freopen("herding.out", "w", stdout);

  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    --tmp;
    a[i] = tmp;
  }

  vector<int> G, H;
  int first_G = -1, lst_G = -1, first_H = -1, lst_H = -1;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'G') {
      if (first_G == -1) first_G = i;
      lst_G = i;
    } else {
      if (first_H == -1) first_H = i;
      lst_H = i;
    }
  }

  if (a[first_G] >= lst_G) G.push_back(first_G);
  if (a[first_H] >= lst_H) H.push_back(first_H);

  assert(max(G.size(), H.size()) == 1);

  auto bs = [](vector<int> &seq, int val) -> int {
    int b = -1, sz = (int)seq.size();
    for (int k = (sz + 1) / 2; k >= 1; k /= 2) {
      while (b + k < sz && seq[b + k] <= val) b += k;
    }

    return (b != -1) ? seq[b] : -1;
  };

  int G_cnt = (int)G.size(), H_cnt = (int)H.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'G') {
      if ((int)G.size() && i == first_G) continue;
      if (bs(H, a[i]) > i) G.push_back(i), ++G_cnt;

    } else {
      if ((int)H.size() && i == first_H) continue;
      if (bs(G, a[i]) > i) H.push_back(i), ++H_cnt;
    }
  }

  cout << G_cnt * H_cnt << '\n';

  return 0;
}

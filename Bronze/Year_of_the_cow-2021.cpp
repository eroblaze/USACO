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
  // freopen("notlast.in", "r", stdin), freopen("notlast.out", "w", stdout);

  int n;
  cin >> n;

  map<string, int> go_back, go_forward;
  vector<string> years{"Ox",   "Tiger",  "Rabbit",  "Dragon", "Snake", "Horse",
                       "Goat", "Monkey", "Rooster", "Dog",    "Pig",   "Rat"};

  for (int i = 0; i < 12; ++i) {
    go_forward[years[i]] = i;
    go_back[years[i]] = 12 - i;
  }

  map<string, int> mp;
  map<string, string> born;
  born["Bessie"] = "Ox";

  // 1 -> subject
  // 4 -> previous/next
  // 5 -> year
  // 8 -> object
  for (int i = 0; i < n; ++i) {
    string subject, when, year, object;
    for (int j = 1; j <= 8; ++j) {
      if (j == 1) cin >> subject;
      else if (j == 4) cin >> when;
      else if (j == 5) cin >> year;
      else if (j == 8) cin >> object;
      else {
        string tmp;
        cin >> tmp;
      }
    }

    if (when == "next") {
      int diff = go_back[born[object]] - go_back[year];
      if (diff > 0) {
        mp[subject] = mp[object] - diff;
      } else if (diff == 0) mp[subject] = mp[object] - 12;
      else { mp[subject] = mp[object] - (go_back[born[object]] + go_forward[year]); }

    } else {
      if (object == "Bessie") mp[subject] = go_back[year];
      else {
        int diff = go_forward[year] - go_forward[born[object]];
        if (diff > 0) {
          mp[subject] = go_forward[born[object]] + go_back[year] + mp[object];
        } else if (diff == 0) mp[subject] = 12 + mp[object];
        else { mp[subject] = abs(diff) + mp[object]; }
      }
    }

    born[subject] = year;
  }

  cout << abs(mp["Elsie"]) << '\n';
  return 0;
}

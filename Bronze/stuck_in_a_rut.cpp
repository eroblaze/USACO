// @eroblaze
#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

const int inf = 1e9;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int n;
  cin >> n;

  vector<int> order;
  vector<pair<int, int>> east, north;
  map<int, int> dead;

  for (int i = 0; i < n; ++i) {
    char dir;
    int x, y;
    cin >> dir >> x >> y;

    order.push_back(x);
    if (dir == 'E') {
      east.push_back({x, y});
    } else {
      north.push_back({x, y});
    }
  }

  sort(east.begin(), east.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.first > b.first; });
  sort(north.begin(), north.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; });

  for (pair<int, int> &north_line : north) {
    int north_x, north_y;
    tie(north_x, north_y) = north_line;
    int died = inf;

    vector<tuple<int, int, int>> may_die;

    for (pair<int, int> &east_line : east) {
      int east_x, east_y;
      tie(east_x, east_y) = east_line;

      if (east_x < north_x && east_y > north_y && dead[east_x] == 0) {
        int me = east_y - north_y;
        int you = north_x - east_x;

        if (me < you) {
          // You may die
          may_die.push_back({east_x, you, east_y});
        } else if (you < me) {
          // I die
          died = min(died, me);
        }
      }
    }

    if (died != inf) dead[north_x] = died;

    for (tuple<int, int, int> &el : may_die) {
      int east_x, you, east_y;
      tie(east_x, you, east_y) = el;
      if (died + north_y > east_y) dead[east_x] = you;
    }
  }

  for (pair<int, int> &east_line : east) {
    int east_x, east_y;
    tie(east_x, east_y) = east_line;

    if (dead[east_x] == 0) {
      for (pair<int, int> &north_line : north) {
        int north_x, north_y;
        tie(north_x, north_y) = north_line;
        int me = north_x - east_x;
        int you = east_y - north_y;

        if (north_x > east_x && north_y < east_y && me > you && dead[north_x] + north_y > east_y) {
          dead[east_x] = me;
          break;
        }
      }
    }
  }

  for (int idx : order) {
    string ans = to_string(dead[idx]);
    if (ans == "0") ans = "Infinity";
    cout << ans << '\n';
  }

  return 0;
}

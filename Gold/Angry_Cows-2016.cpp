#include <bits/stdc++.h>
using namespace std;

#ifdef ERO_LOCAL
#include "algo/debug.h"
#else
#define dbg(...)
#endif

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  freopen("angry.in", "r", stdin), freopen("angry.out", "w", stdout);
  int n;
  cin >> n;
  vector<double> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  auto are_equal = [](double a, double b) -> bool { return abs(a - b) < 1e-9; };
  vector<double> pref(n), suff(n);
  auto can_use_right = [&](double location, double sz) -> bool {
    auto it = upper_bound(a.begin(), a.end(), location + sz);
    if (it == a.begin()) return 0;
    --it;
    int idx = it - a.begin();
    if (*it > location && suff[idx] < sz) {
      return 1;
    }
    return 0;
  };
  auto can_use_left = [&](double location, double sz) -> bool {
    auto it = lower_bound(a.begin(), a.end(), location - sz);
    if (it == a.end()) return 0;
    int idx = it - a.begin();
    if (*it < location && pref[idx] < sz) {
      return 1;
    }
    return 0;
  };
  for (int i = n - 2; i >= 0; --i) {
    // can we use suff[i+1] for a[i]?
    if (can_use_right(a[i], suff[i + 1])) {
      suff[i] = suff[i + 1];
      continue;
    }
    suff[i] = max(a[i + 1] - a[i], suff[i + 1] + 1);
  }
  for (int i = 1; i < n; ++i) {
    // can we use pref[i-1] for a[i]?
    if (can_use_left(a[i], pref[i - 1])) {
      pref[i] = pref[i - 1];
      continue;
    }
    pref[i] = max(a[i] - a[i - 1], pref[i - 1] + 1);
  }
  auto fn = [&](double location) -> double {
    auto it = lower_bound(a.begin(), a.end(), location);
    bool try_left = 0, try_right = 0;
    double add_left = 0.0, add_right = 0.0;
    int idx;
    if (it == a.end()) {
      --it;
      idx = n - 1;
      try_left = can_use_left(location, pref[idx]);
      if (try_left) return pref[idx];
      add_left = min(1.0, location - (*it));
      return max(location - (*it), pref[idx] + add_left);
    }
    if (are_equal(*it, location)) {
      idx = it - a.begin();
      return max(pref[idx], suff[idx]);
    }
    if (it == a.begin()) {
      idx = 0;
      try_right = can_use_right(location, suff[idx]);
      if (try_right) return suff[idx];
      add_right = min(1.0, (*it) - location);
      return max((*it) - location, suff[idx] + add_right);
    }
    idx = it - a.begin();
    try_right = can_use_right(location, suff[idx]);
    add_right = min(1.0, (*it) - location);
    double to_right = try_right ? suff[idx] : max((*it) - location, suff[idx] + add_right);
    --idx;
    try_left = can_use_left(location, pref[idx]);
    add_left = min(1.0, location - a[idx]);
    double to_left = try_left ? pref[idx] : max(location - a[idx], pref[idx] + add_left);
    return max(to_left, to_right);
  };

  double ans = MAXFLOAT, low = 0.0, high = a.back();
  for (int _ = 0; _ < 200; ++_) {
    double mid = low + (high - low) / 2.0;
    double first = fn(mid), second = fn(mid + 1e-2);
    if (first < second) {
      ans = min({ans, first, second});
      high = mid;
    } else if (first > second) {
      low = mid;
    } else {
      double right_ptr = mid + 2.0;
      while (right_ptr <= high) {
        second = fn(right_ptr);
        if (!are_equal(first, second)) break;
        right_ptr += 4;
      }
      ans = min({ans, first, second});
      if (first > second) {
        low = right_ptr;
      } else high = mid;
    }
  }
  cout << fixed << setprecision(1) << ans << endl;
  return 0;
}

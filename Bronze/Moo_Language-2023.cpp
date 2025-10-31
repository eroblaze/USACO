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

  int tt;
  cin >> tt;
  while (tt--) {
    int n, c, p;
    cin >> n >> c >> p;
    map<string, stack<string>> mp;
    bool last_ended_with_conj = 0;

    for (int i = 0; i < n; ++i) {
      string s, type;
      cin >> s >> type;

      mp[type].push(s);
    }

    const string N = "noun", T = "transitive-verb", I = "intransitive-verb", C = "conjunction";
    int k = 0; // k is the total number of words
    string ans;

    for (int i = 0; i >= 0; ++i) {
      // i represents how many transitive sentences we make
      if (mp[T].size() < i || mp[N].size() < i * 2) break;
      int c_cpy = c, p_cpy = p, i_cpy = i;
      int curr_k = 0;
      map<string, stack<string>> tmp = mp;

      vector<string> first;
      while (i_cpy--) {
        string s = tmp[N].top() + " " + tmp[T].top() + " ";
        tmp[N].pop(), tmp[T].pop();

        s += tmp[N].top();
        tmp[N].pop();

        first.push_back(s);
      }

      // real_first -> transitive, second -> intransitive
      vector<string> real_first;
      for (int j = 0; j < int(first.size()); ++j) {
        if (p_cpy <= 0) break;
        --p_cpy;

        if (!tmp[C].empty() && j + 1 < int(first.size())) {
          string conj = tmp[C].top();
          tmp[C].pop();
          real_first.push_back(first[j] + " " + conj + " " + first[j + 1]);

          curr_k += 7;
          ++j;
          last_ended_with_conj = 1;
          continue;
        }
        real_first.push_back(first[j]);
        curr_k += 3;
        last_ended_with_conj = 0;
      }

      vector<string> second;
      int left = min(tmp[N].size(), tmp[I].size());
      vector<string> second_nouns;

      while (left--) {
        second_nouns.push_back(tmp[N].top());
        string s = tmp[N].top() + " " + tmp[I].top();
        tmp[N].pop(), tmp[I].pop();

        second.push_back(s);
      }

      vector<string> real_second;
      int second_nouns_used = 0;
      string add_s;

      for (int j = 0; j < int(second.size()); ++j) {
        if (!tmp[C].empty()) {
          if (!last_ended_with_conj && !real_first.empty()) {
            string conj = tmp[C].top();
            tmp[C].pop();
            add_s += " " + conj + " " + second[j];

            curr_k += 3;
            last_ended_with_conj = 1;
            second_nouns_used += 1;
            continue;
          }
        }

        if (p_cpy <= 0) break;
        --p_cpy;

        if (!tmp[C].empty() && j + 1 < int(second.size())) {
          string conj = tmp[C].top();
          tmp[C].pop();
          real_second.push_back(second[j] + " " + conj + " " + second[j + 1]);

          second_nouns_used += 2;
          curr_k += 5;
          ++j;
          continue;
        }
        real_second.push_back(second[j]);
        curr_k += 2;
        second_nouns_used += 1;
      }

      for (; second_nouns_used < int(second_nouns.size()); ++second_nouns_used) {
        tmp[N].push(second_nouns[second_nouns_used]);
      }

      while (c_cpy-- && !real_first.empty() && !tmp[N].empty()) {
        real_first.back() += ", " + tmp[N].top();
        tmp[N].pop();

        curr_k++;
      }

      if (!real_first.empty()) real_first.back() += add_s;

      if (curr_k <= k) continue;
      k = curr_k;
      ans = "";

      for (int j = 0; j < int(real_first.size()); ++j) {
        if (j == 0) {
          ans += real_first[j] + ".";
          continue;
        }
        ans += " " + real_first[j] + ".";
      }

      for (int j = 0; j < int(real_second.size()); ++j) {
        if (ans.empty() && j == 0) {
          ans += real_second[j] + ".";
          continue;
        }
        ans += " " + real_second[j] + ".";
      }
    }

    cout << k << '\n';
    cout << ans << '\n';
  }
  return 0;
}

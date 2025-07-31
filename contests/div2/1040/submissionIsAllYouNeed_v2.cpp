#include <bits/stdc++.h>
using namespace std;

// we are finding smallest non negative number not present in the vector
auto mex(vector<int> V) -> int {
  unordered_set<int> st;
  for (auto val : V) {
    if (val >= 0)
      st.insert(val);
  }
  for (int i = 0;; ++i)
    if (!st.count(i))
      return i;
}

// we are returning the sum of the vector given
auto sum(vector<int> V) -> int {
  auto total{0};
  for (auto val : V)
    total += val;
  return total;
}

auto maxScore(vector<int> S) -> int {
  auto score{0};

  while (!S.empty()) {
    int best_gain = INT_MIN;
    int best_l = 0, best_r = 0;
    bool use_mex = true;

    int n = S.size();

    for (int l = 0; l < n; ++l) {
      vector<int> sub;
      for (int r = l; r < n; ++r) {
        sub.push_back(S[r]);

        int gain_mex = mex(sub);
        int gain_sum = sum(sub);

        if (gain_mex > best_gain) {
          best_gain = gain_mex;
          best_l = l;
          best_r = r;
          use_mex = true;
        }
        if (gain_sum > best_gain) {
          best_gain = gain_sum;
          best_l = l;
          best_r = r;
          use_mex = false;
        }
      }
    }

    // Add best gain to score
    score += best_gain;

    // Erase the selected subarray [best_l, best_r] from S
    S.erase(S.begin() + best_l, S.begin() + best_r + 1);
  }

  return score;
}

auto submission(int len, vector<int> S) -> int { return maxScore(S); }

auto main() -> int {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int len;
    cin >> len;

    vector<int> S(len);
    for (int j = 0; j < len; ++j) {
      cin >> S[j];
    }

    int result = submission(len, S);
    cout << "Submission " << i + 1 << ": result = " << result << '\n';
  }

  return 0;
}

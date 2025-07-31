#include <bits/stdc++.h>
using namespace std;

int n, s;

bool bfs_disallows_sum(const vector<int> &arr) {
  int maxSteps = 2 * n; // upper bound on total steps Alice can take
  set<pair<int, int>> visited;

  queue<tuple<int, int, int>> q; // index, current sum, steps
  q.push({0, arr[0], 0});
  visited.insert({0, arr[0]});

  while (!q.empty()) {
    auto [pos, curr_sum, steps] = q.front();
    q.pop();

    if (pos == n - 1 && curr_sum == s)
      return false; // Alice can reach s on some path

    if (steps >= maxSteps)
      continue;

    for (int d : {-1, 1}) {
      int next_pos = pos + d;
      if (next_pos >= 0 && next_pos < n) {
        int next_sum = curr_sum + arr[next_pos];
        if (visited.count({next_pos, next_sum}) == 0) {
          visited.insert({next_pos, next_sum});
          q.push({next_pos, next_sum, steps + 1});
        }
      }
    }
  }

  return true; // No path leads to sum s
}

void solve_case(vector<int> a) {
  // Try a few smart rearrangements
  vector<vector<int>> tries;

  vector<int> tmp = a;
  sort(tmp.begin(), tmp.end());
  tries.push_back(tmp); // ascending
  reverse(tmp.begin(), tmp.end());
  tries.push_back(tmp); // descending

  // Move all 2s to front, 0s to middle, etc.
  vector<int> count(3);
  for (int x : a)
    count[x]++;
  vector<int> special;

  for (int i = 0; i < count[2]; ++i)
    special.push_back(2);
  for (int i = 0; i < count[1]; ++i)
    special.push_back(1);
  for (int i = 0; i < count[0]; ++i)
    special.push_back(0);
  tries.push_back(special);

  for (int i = 0; i < count[0]; ++i)
    special.push_back(0);
  for (int i = 0; i < count[1]; ++i)
    special.push_back(1);
  for (int i = 0; i < count[2]; ++i)
    special.push_back(2);
  tries.push_back(special);

  // Try all of the above
  for (auto &candidate : tries) {
    if (bfs_disallows_sum(candidate)) {
      for (int i = 0; i < n; ++i)
        cout << candidate[i] << " \n"[i == n - 1];
      return;
    }
  }

  // Couldn't find a valid arrangement
  cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    cin >> n >> s;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    solve_case(a);
  }

  return 0;
}

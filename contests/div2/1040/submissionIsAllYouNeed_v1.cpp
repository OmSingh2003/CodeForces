#include <bits/stdc++.h>

auto submission(int len, const std::vector<int> &S) -> int {
  if (S.empty()) {
    return 0;
  }

  int total_sum = 0;
  int zero_count = 0;

  for (int x : S) {
    total_sum += x;
    if (x == 0) {
      zero_count++;
    }
  }

  return total_sum + zero_count;
}

auto main() -> int {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int len;
    std::cin >> len;

    std::vector<int> S(len);
    for (int j = 0; j < len; ++j) {
      std::cin >> S[j];
    }

    int result = submission(len, S);
    std::cout << result << '\n';
  }

  return 0;
}

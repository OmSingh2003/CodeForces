#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        vector<long long> points;
        points.push_back(0); 
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            points.push_back(a);
        }
        points.push_back(x);  
        sort(points.begin(), points.end());  

        long long required_tank = 0;
        for (int i = 1; i < points.size(); ++i) {
            required_tank = max(required_tank, points[i] - points[i - 1]);
        }

        cout << required_tank << endl;
    }
    return 0;
  }
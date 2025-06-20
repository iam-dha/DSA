#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); // tăng tốc I/O

    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].first >> movies[i].second;
    }

    stable_sort(movies.begin(), movies.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });

    int ans = 0, end_time = 0;
    for (int i = 0; i < n; ++i) {
        if (movies[i].first >= end_time) {
            ++ans;
            end_time = movies[i].second;
        }
    }

    cout << ans;
}

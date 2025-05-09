#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
int maxMap[N];

int bin_search(const vector<pair<pair<int, int>, int>> &v, int x)
{
    int l = 0, r = v.size() - 1, ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid].first.second < x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<pair<pair<int, int>, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b, p;
        cin >> a >> b >> p;
        pair<int, int> pr = make_pair(a, b);
        pair<pair<int, int>, int> temp = make_pair(pr, p);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), [](const pair<pair<int, int>, int> &p1, const pair<pair<int, int>, int> &p2)
         { return p1.first.second < p2.first.second; });
    vector<int> dp(n, 0);
    dp[0] = v[0].second;
    ans = dp[0];
    maxMap[0] = dp[0];
    for (int i = 1; i < n; i++)
    {
        int it = bin_search(v, v[i].first.first);
        if (it != -1)
        {
            if(dp[it] + v[i].second > maxMap[i - 1]){
                dp[i] = dp[it] + v[i].second;
                maxMap[i] = dp[i];
            }
        }
        else
        {
            maxMap[i] = dp[i] = max(maxMap[i - 1], v[i].second);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main()
{
    solve();
}

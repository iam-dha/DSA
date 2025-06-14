#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n, x;


// map<int, int> mp;
vector<int> dp;
vector<int> value;

int f(int x, int mmax){
    if(x < 0) return 0;
    if(x == 0) return 1;
    if(dp[x] != -1) return dp[x];
    for(int j = 0; j < n; j++){
        if(value[j] <= x && value[j] <= mmax){
            dp[x] = ((dp[x] % mod) + (f(x - value[j], value[j]) % mod))%mod;
        }
    }
    return dp[x];
}

int main(){
    cin >> n >> x;
    value.resize(n);
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        value[i] = tmp;
        // mp[tmp] = n / tmp;
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for(int coin = 0; coin < n; coin++){
        for(int j = value[coin]; j <= x; j++){
            dp[j] = (dp[j] + dp[j - value[coin]]) % mod;
        }
    }

    cout << dp[x];
}





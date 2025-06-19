#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int n, m;
vector<int>desc;



int main(){
    cin >> n >> m;
    desc.resize(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> desc[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    if(desc[1] == 0){
        for(int i = 1; i <= m; i++){
            dp[1][i] = 1;
        }
    }
    else{
        dp[1][desc[1]] = 1;
    }
    for(int i = 2; i <= n; i++){
        if(desc[i] == 0){
            for(int j = 1; j <= m; j++){
                if(j - 1 >= 1){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if(j + 1 <= m){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                }
            }
        }
        else{
            // for (int j = 1; j <= m; ++j) dp[i][j] = 0;
            int v = desc[i];
            if(v > 1){
                dp[i][v] =  (dp[i][v] + dp[i - 1][v - 1]) % mod;
            }
            dp[i][v] =  (dp[i][v] + dp[i - 1][v]) % mod;
            if(v < m){
                dp[i][v] = (dp[i][v] + dp[i - 1][v + 1]) % mod;
            }
            
        }
    }
    int res = 0;
    for(int i = 0; i <= m; i++){
        res = (res + dp[n][i]) % mod;
    }
    cout << res;
}



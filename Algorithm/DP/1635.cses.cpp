#include <bits/stdc++.h>

using namespace std;

int n, x;
const int mod = 1e9 + 7;
vector<int> value;
vector<int> dp (100);

int f(int i){
    if(i < 0) return 0;
    if(i == 0) return 1;
    if(dp[i] != -1) return dp[i];
    dp[i] = 0;
    for(int j = 0; j < n; j++){
        if(value[j] <= i){
            dp[i] = ((dp[i] % mod) + (f(i - value[j]) % mod))%mod;
        }
    }
    return dp[i];
}

int main(){
    cin >> n >> x;
    value.resize(n);
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }
    dp.assign(x + 1, -1);
    cout << f(x) << endl;
}


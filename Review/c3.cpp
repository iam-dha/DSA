#include <bits/stdc++.h>

using namespace std;

const int N = (1e6 + 7);

void solve(){
    int n; cin >> n;
    int even, odd; even = odd = 0;
    vector<int> oddNum;
    vector<int> evenNum;
    for(int i = 1; i <= n; i++){
        int temp; cin >> temp;
        if(temp % 2 == 0){
            evenNum.push_back(temp);
            even++;
        }
        else{
            oddNum.push_back(temp);
            odd++;
        }
    }
    vector<int> dp (n, 1);
    int ans = 0;
    for(int i = 0; i < even; i++){
        for(int j = 0; j < i; j++){
            if(evenNum[j] < evenNum[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    for(int i = 0; i < odd; i++){
        for(int j = 0; j < i; j++){
            if(oddNum[j] < oddNum[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}




int main(){
    solve();
}   


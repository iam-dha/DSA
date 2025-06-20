#include <bits/stdc++.h>

using namespace std;
int n, x; 
vector<int> price;
vector<int> pages;


int main(){
    cin >> n >> x;
    price.resize(n);
    pages.resize(n);
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }

    vector<int> dp(x + 1, 0); // Lỗi do khai báo arr[x] thì do cấp phát compile, x nhập khi runtime
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = x; j >= price[i]; j--){
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }
    cout << dp[x];
}



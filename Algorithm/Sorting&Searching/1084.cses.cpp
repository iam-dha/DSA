#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    vector<int> need;
    vector<int> price;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        need.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        price.push_back(x);
    }
    sort(need.begin(), need.end());
    sort(price.begin(), price.end());
    int i, j; i = j = 0;
    while(i < n && j < m){
        if(abs(need[i] - price[j]) <= k){
            ans++;
            i++;
            j++;
        }
        else{
            if(need[i] + k < price[j]){
                i++;
            }
            else{
                j++;
            }
        }
    }
    cout << ans;
}



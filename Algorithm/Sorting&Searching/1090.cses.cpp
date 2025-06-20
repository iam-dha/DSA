#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int ans = 0;
    vector<int> weight;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        weight.push_back(x);
    }
    sort(weight.begin(), weight.end());
    int l = 0, r = n - 1;
    while(l <= r){
        if(weight[l] + weight[r] <= k){
            ans++;
            l++;
            r--;
        }else{
            ans++;
            r--;
        }
    }
    cout << ans;
}




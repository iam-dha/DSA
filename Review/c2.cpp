#include <bits/stdc++.h>

using namespace std;

void solve(){
    int ans = INT_MIN;
    int n; cin >> n;
    int k; cin >> k;
    int arr[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    int l, r;
    l = r = 1;
    while(r <= n){
        while(arr[r] - arr[l] < k){
            r++;
        }
        ans = max(ans, (r - l));
        l++;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

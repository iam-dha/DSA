#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
int n;

struct ii {
    long long x, y, z;
};

ii a[100000];
long long dp[1000011];

bool compare(ii a, ii b){
    if(a.y == b.y){
        if(a.x == b.x){
            return a.z > b.z;
        }
        return a.x < b.x;
    }
    return a.y < b.y;
} 

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a + 1, a + n + 1, compare);
    long long ans = a[1].z;
    dp[1] = a[1].z;
    for(int i = 2; i <= n; i++){
        int l = 1, r = i - 1;
        int res = 0;
        while(l <= r){
            int mid = (l + r)/2;
            if(a[mid].y < a[i].x){
                res = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        dp[i] = a[i].z;
        if(res != 0){
            dp[i] += dp[res];
        }
        dp[i] = max(dp[i], dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    cout << ans;

}



int main(){
    solve();
}


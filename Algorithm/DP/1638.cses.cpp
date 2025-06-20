#include <bits/stdc++.h>

using namespace std;
int n;
const int mod = 1e9 + 7;

int main(){
    cin >> n;
    int arr[n + 1][n + 1];
    bool mp[n+1][n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char x; cin >> x;
            if(x == '*'){
                mp[i][j] = false;
            }
            else{
                mp[i][j] = true;
            }
        }
    }
    arr[1][1] = mp[1][1] ? 1 : 0;
    for (int i = 2; i <= n; i++) {
        arr[i][1] = (mp[i][1] && arr[i-1][1]) ? 1 : 0;
        arr[1][i] = (mp[1][i] && arr[1][i-1]) ? 1 : 0;
    }   
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            if(mp[i][j]){
                arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % mod;
            }
            else{
                arr[i][j] = 0;
            }
        }
    }
    cout << arr[n][n];
}


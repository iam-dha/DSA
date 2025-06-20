#include <bits/stdc++.h>

using namespace std;



int main(){
    int n; cin >> n;
    set<int> se;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(se.find(x) == se.end()){
            ans++;
            se.insert(x);
        }
    }
    cout << ans;
}




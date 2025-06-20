#include <bits/stdc++.h>

using namespace std;


int main(){
    int n; cin >> n;
    map<int, int> mark;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        mark[a]++;
        mark[b]--;
    }
    int ans = 0;
    int current = 0;
    for(auto c : mark){
        current += c.second;
        ans = max(ans, current);
    }
    cout << ans;
}


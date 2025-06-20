#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int n, a[N];


int main(){
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        int u = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        if(u != v.size()){
            v[u] = a[i];
        }
        else{
            v.push_back(a[i]);
        }
    }
    cout << v.size();
}




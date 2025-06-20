#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, m; cin >> n >> m;
    map<int, int> tickets;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        tickets[x]++;
    }
    vector<int> fund;
    for(int j = 0; j < m; j++){
        int x; cin >> x;
        fund.push_back(x);
    }
    for(int i = 0; i < m; i++){
        auto it = tickets.upper_bound(fund[i]);
        if(it == tickets.begin()){
            cout << -1 << endl;
        }
        else{
            --it;
            cout << it->first << endl;
            if(--(it->second) == 0){
                tickets.erase(it);
            }
        }
    }
}


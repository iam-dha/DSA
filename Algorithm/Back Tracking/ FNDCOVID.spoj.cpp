#include <bits/stdc++.h>

using namespace std;

int affected[100];
vector<int> f0;
vector<int> f1;
vector<int> f2;

int matrix[100][100];
int n, m;


void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int temp; cin >> temp;
            matrix[i][j] = temp;
        }
    }
    while(m--){
        int t; cin >> t;
        affected[t] = 0;
        f0.push_back(t);
    }
}

void solve(int k){
    int c1 = 0, c2 = 0;
    if(!f0.empty()){
        for(int victim : f0){
            for(int j = 1; j <= n; j++)
            if(matrix[victim][j]){
                affected[j] = 1;
                f1.push_back(j);
            }
        }
    }
    if(!f1.empty()){
        
    }
    cout << '#' << k << " " << c1 << " " << 2 << endl;
}

int main(){
    int t; cin >> t;
    for(int i = 1; i <= n; i++){
        solve(i);
    }
}


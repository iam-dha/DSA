#include <bits/stdc++.h>

using namespace std;

int n, K;
int d[30][30];
vector<bool> visited (30, false);
int f = 0, f_opt = INT_MAX, cmin = INT_MAX, load = 0;
int des[30];

void input(){
    des[0] = 0;
    cin >> n >> K;
    int biggest_des = 2 * n;
    for(int i = 0; i <= biggest_des; i++){
        for(int j = 0; j <= biggest_des; j++){
            int temp; cin >> temp;
            if(i != j) cmin = min(cmin, temp);
            d[i][j] = temp;
        }
    }
}

bool check(int v,int k){
    if(visited[v]) return false;
    if(v > n){
        if(!visited[v - n]) return false;
    }
    else{
        return !(load + 1 > K);
    }
    return true;
}

void updateBest(){
    f_opt = min(f_opt, f + d[des[2 * n]][0]);
}

void Try(int k){
    for(int v = 1; v <= 2*n; v++){
        if(check(v, k)){
            des[k] = v;
            f += d[des[k-1]][des[k]];
            visited[v] = true;
            if(v <= n){
                load++;
            }
            else load--;
            if(k == 2 * n){
                updateBest();
            }
            else{
                if((f + (2*n + 1 - k ) * cmin) < f_opt){
                    Try(k+1);
                }
            }
            visited[v] = false;
            f -= d[des[k-1]][des[k]];
            if(v <= n) load--;
            else load++;
        }
    }
}

int main(){
    input();
    Try(1);
    cout << f_opt;
    return 0;
}



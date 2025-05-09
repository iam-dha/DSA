#include <bits/stdc++.h>

using namespace std;

int n;
int arr[30];
int lb, ub, ans;
int sum = 0;
vector<bool>visited(30, false);

void input(){
    ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        arr[i] = tmp;
    }
    cin >> lb >> ub;
}

void backtrack(int k){
    for(int i = 0; i <= 1; i++){
        sum += i * arr[k];
        if(k < n - 1){
            if(sum > ub){
                sum -= i * arr[k];
                return;
            }
            backtrack(k + 1);
        }
        else{
            if(sum >= lb && sum <= ub){
                ans++;
            }
        }
        sum -= i * arr[k];
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    backtrack(0);
    cout << ans;
}


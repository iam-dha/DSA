#include <bits/stdc++.h>

using namespace std;

vector<bool>visited;
vector<vector<int>>ans;
vector<int>candidate;
int N;


bool check(int v, int k){
    if(visited[v]) return false;
    if(k == 0) return true;
    int temp = v % 2;
    return !(candidate[k - 1] % 2 == temp);
}

void backtrack(int k){
    for(int i = 1; i <= N; i++){
        if(check(i, k)){
            visited[i] = true;
            candidate[k] = i;
            if(k == N - 1){
                ans.push_back(candidate);
            }
            else{
                backtrack(k + 1);
            }
            visited[i] = false;
            candidate[k] = 0;
        }
    }
}

vector<vector<int>> permute(int n) {
    N = n;
    visited = vector<bool> (n + 1, false);
    candidate = vector<int> (n, 0);
    backtrack(0);
    return ans;
}



int main(){

}




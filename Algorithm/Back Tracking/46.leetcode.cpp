#include<bits/stdc++.h>

using namespace std;
vector<bool> visited (10, false);
vector<int> candidate;
vector<int> input;
vector<vector<int>> ans;
int n;

void Try(int k){
    for(int v = 0; v < n; v++){
        if(!visited[v]){
            visited[v] = true;
            candidate[k] = input[v];
            if(k == n - 1){
                ans.push_back(candidate);
            } 
            else{
                Try(k + 1);
            }
            visited[v] = false;
            candidate[k] = 0;
        }
    }
}




vector<vector<int>> permute(vector<int>& nums) {
    n = nums.size();
    input = nums;
    Try(0);
    return ans;
}


int main(){
    vector<int> nums = {1, 2, 3};
    permute(nums);
    return 0;
}










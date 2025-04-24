#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> candidate;
vector<vector<int>> ans;
vector<int> input;

void updateAns(){
    ans.push_back(candidate);
}

void Try(int k){
    for(int i = 0; i <= 1; i++){
        if(i == 1){
            candidate.push_back(input[k]);
        }
        if(k == n - 1){
            updateAns();
        }
        else{
            Try(k + 1);
        }
        candidate[k] = 0;
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    n = nums.size();
    input = nums;
    Try(0);
    return ans;
}








int main(){


    return 0;
}





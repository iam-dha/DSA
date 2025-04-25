#include <bits/stdc++.h>


using namespace std;

vector<int> candidate;
vector<vector<int>>ans;
vector<int> input;
unordered_map<int, int> countMap;
int n;

void Try(int k){
    for(auto &[value, cnt]: countMap){
        if(cnt > 0){
            countMap[value]--;
            candidate[k] = value;
            if(k == n - 1){
                ans.push_back(candidate);
            }
            else{
                Try(k + 1);
            }
            countMap[value]++;
            candidate[k] = 0;
        }
        
    }
}



vector<vector<int>> permuteUnique(vector<int>& nums) {
    input = nums;
    n = nums.size();
    candidate = vector<int> (n, 0);
    countMap.clear();
    ans.clear();
    for(int value: nums){
        countMap[value]++;
    }
    Try(0);
    return ans;
}


int main(){
    vector<int> nums = {1, 1, 2};
    auto t = permuteUnique(nums);
    for(auto x : t){
        for(auto c: x){
            cout << c << "--";
        }
        cout << endl;
    }
}




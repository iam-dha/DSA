#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> bitMap;
vector<int> arr;
int ans;


void cal(){
    int res = 0;
    cout << "-----------------" << endl;
    for(int i = 0; i < n; i++){
        cout << bitMap[i] << " " << arr[i] << endl;
        res = res ^ (arr[i] * bitMap[i]);
    }
    ans += res;
    cout << res << " " << ans << endl << "-----------------" << endl;
}

void Try(int k){
    for(int v = 0; v <= 1; v++){
        bitMap[k] = v;
        if(k == n - 1){
            cal();
        }else{
            Try(k + 1);
        }
        bitMap[k] = 0;
    }
}

int subsetXORSum(vector<int>& nums) {
    arr = nums;
    n = nums.size();
    bitMap = {20, 0};
    ans = 0;
    Try(0);
    return ans;
}

int main(){
    vector<int> input = {1,3};
    subsetXORSum(input);
    cout << ans;
}





#include<bits/stdc++.h>

using namespace std;
vector<string>ans;
vector<int>candidate;

void updateAns(int n){
    string temp = "";
    for(int i = 1; i <= n; i++){
        temp += to_string(candidate[i]);
    }
    ans.push_back(temp);
}

bool check(int v, int k){
    if(v == 1){
        return true;
    }
    else{
        if(candidate[k - 1] == 1){
            return true;
        }
    }
    return false;
}

void Try(int k, int n){
    for(int v = 0; v <= 1; v++){
        if(check(v, k)){
            candidate[k] = v;
            if(k == n){
                updateAns(n);
            }
            else{
                Try(k + 1, n);
            }
            candidate[k] = 0;
        }
    }
}

vector<string> validStrings(int n) {
    candidate = vector<int> (n + 1, 0);
    candidate[0] = 1;
    Try(1, n);
    return ans;
}




int main(){
    vector<string> ans = validStrings(3);
    for(string s: ans){
        cout << s << endl;
    }
    return 0;
}


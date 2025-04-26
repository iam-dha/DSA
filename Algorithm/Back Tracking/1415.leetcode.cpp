#include <bits/stdc++.h>

using namespace std;
// All Happy Strings
vector<char> basicSet;
vector<char> candidate;
int K;
string ans;

bool check(char c, int k){
    if(k == 1) return true;
    if(c == candidate[k - 1]) return false;
    return true;
}

void update(){
    string temp = "";
    for(int i = 1; i < candidate.size(); i++){
        temp += candidate[i];
    }
    ans = temp;
}

void backtrack(int k, int n){
    for(int i = 0; i <= 2; i++){
        char c = basicSet[i];
        if(check(c, k)){
            candidate[k] = c;
            if(k == n){
                K--;
                cout << K << endl;
                if(K == 0){
                    update();
                    return;
                }
            }
            else if(K != 0){
                backtrack(k + 1, n);
            }
            candidate[k] = 'd';
        }
    }
}


string getHappyString(int n, int k) {
    basicSet = vector<char> {'a', 'b', 'c'};
    candidate = vector<char> (n + 1, 'd');
    ans = "";
    K = k;
    backtrack(1, n);
    return ans;
}


string getHappyString_Better(int n, int k) {
    int sz=3*(1<<(n-1));
    if (k>sz) return "";
    auto [q, r]=div(k-1, 1<<(n-1));// k-1
    string s(n, ' ');
    s[0]='a'+q;
    bitset<9> bin(r);
    array<char, 2> xx[3]={{'b', 'c'}, {'a', 'c'}, {'a', 'b'}};
    for(int i=n-2; i>=0; i--){
        char idx=s[n-2-i]-'a';
        s[n-1-i]=(bin[i])?xx[idx][1]:xx[idx][0];
    }
    return s;
}
   



int main(){
    cout << getHappyString(3, 9);
}   






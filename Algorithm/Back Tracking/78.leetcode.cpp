#include<bits/stdc++.h>

using namespace std;

vector<int> timeBit (10, 0);
int c = 0;
int valid = 1;
vector<string> ans;

string time(){
    int hour = 0;
    int minute = 0;
    string ans = "";
    for(int i = 0; i < 4; i++){
        hour += (1<<(4 - i - 1)) * timeBit[i];
    }
    for(int i = 4; i < 10; i++){
        minute += (1<<(6 - i - 1 + 4)) * timeBit[i];
    }
    ans += to_string(hour) + ":";
    if(minute < 10){
        ans += "0" + to_string(minute);
    }
    else{
        ans += to_string(minute);
    }
    return ans;
}

bool check(int v, int pos){
    if(v == 1){
        if(c + 1 > valid){
            return false;
        }
    }
    int hour = 0, minute = 0;
    for(int i = 0; i < 4; i++) {
        int bit = (i == pos) ? v : timeBit[i];
        hour += bit << (3 - i);
    }
    for(int i = 4; i < 10; i++) {
        int bit = (i == pos) ? v : timeBit[i];
        minute += bit << (9 - i);
    }

    return (hour <= 11 && minute <= 59);
}

void Try(int k){
    for(int v = 0; v <= 1; v++){
        if(check(v, k)){
            timeBit[k] = v;
            if(v == 1){
                c++;
            }
            if(k == 9){
                if(c == valid){
                    ans.push_back(time());
                }
            }
            else{
                Try(k + 1);
            }
            if(v == 1) c--;
            timeBit[k] = 0;
        }
    }
}

vector<string> readBinaryWatch(int turnedOn) {
    valid = turnedOn;
    Try(0);
    return ans;
}






int main(){
    vector<string> hehe = readBinaryWatch(3);
    for(string temp : hehe){
        cout << temp << endl;
    }
}




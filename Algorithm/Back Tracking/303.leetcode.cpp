#include <bits/stdc++.h>

using namespace std;

class NumArray {
    public:
        vector<int> arr;
        NumArray(vector<int>& nums) {
            arr=nums;
            int n=nums.size();
            for(int i=1;i<n;i++){
                arr[i]=arr[i-1]+nums[i];
            }    
        }
        
    
        int sumRange(int left, int right) {
            if(left==0)
                return arr[right];
            return arr[right]-arr[left-1];
        }
    };
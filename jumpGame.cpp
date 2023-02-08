#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &nums,int idx,int n,vector<int> &dp){
        //base case
        if(idx >= n-1) return 0;
        
        if(dp[idx] != 10001) return dp[idx];
        
        int jumps=10001;
        for(int i=1; i <= nums[idx]; i++){
            jumps = min(jumps,1 + f(nums,idx + i,n,dp));
        }
        
        return dp[idx] = jumps;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> dp(n,10001);
        return f(nums,0,n,dp);
    }
};
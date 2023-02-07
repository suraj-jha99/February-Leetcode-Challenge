#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int> mp;
        int i=0,ans=0;
        for(int j=0; j<n; j++){
            mp[nums[j]]=j;//store last seen idx of each number

            if(mp.size() > 2){
 //remove the fruit whose last idx lies at leftmost postn in cur window
               int lastIdx=n-1;
               for(auto it: mp){
                   lastIdx = min(lastIdx,it.second);
               }
               i = lastIdx+1;
               mp.erase(nums[lastIdx]);
            }

            ans = max(ans,j-i+1);
        }

        return ans;
    }
};
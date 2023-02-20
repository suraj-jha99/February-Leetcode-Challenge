#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int tar) {
        int n=nums.size();
        int st=0,end=n-1;

        while(st <= end){
            int mid=st+(end-st)/2;

            if(nums[mid]==tar) return mid;
            if(nums[mid] > tar) end=mid-1;
            else st=mid+1;
        }

        return end+1;
    }
};
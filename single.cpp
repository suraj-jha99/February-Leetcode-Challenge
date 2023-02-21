#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //app 1 using xor
    int singleNonDuplicate(vector<int>& nums) {
        int xorval=0;
        for(int x: nums){
            xorval ^= x;
        }
        return xorval;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof=INT_MIN;
        int minpric=INT_MAX;
        
        for(int x: prices){
            minpric=min(minpric,x);
            maxprof=max(maxprof,x - minpric);
        }
        
        return maxprof;
    }
};
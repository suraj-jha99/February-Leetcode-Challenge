#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int rows) {
        int n=s.size();
        
        if(rows==1) return s;

        string ans="";
        int jumps = 2*(rows-1);
        for(int i=0; i<rows; i++){
            int idx = i; 
            while(idx < n){
                ans += s[idx];

                if(i != 0 && i != rows-1){
                    int nextIdx = idx + jumps - 2*i;

                    if(nextIdx < n) ans += s[nextIdx];
                }
                idx += jumps;
            }
        }

        return ans;
    }
};
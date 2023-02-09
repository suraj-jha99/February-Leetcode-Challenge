#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//app 2: O(n*m)
    long long distinctNames(vector<string>& s) {
        int n=s.size();

        //make an array of set
        unordered_set<string> st[26];

       //group words by initials [a to z]
        for(string &w: s){
            st[w[0] - 'a'].insert(w.substr(1));
        }

        long long ans=0;
        for(int i=0; i<26; i++){
            for(int j=i+1; j<26; j++){
                int mutual=0;
                //find mutual words 
                for(auto &word: st[i]){
                     if(st[j].count(word)) mutual++;
                }
                
// Valid names are only from distinct suffixes in both groups.
 // Since we can swap a with b and swap b with a to create two valid names, multiple answer by 2.
                long long combn = (st[i].size()-mutual)*(st[j].size()-mutual);
                ans += 2*combn;
            }
        }

        return ans;
    }
};
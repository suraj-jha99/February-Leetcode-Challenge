#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();

        vector<int> mp(26);
        for(int i=0; i<26; i++){
            mp[order[i]-'a']=i;
        }

        //compare each adjacent pair in words
        for(int i=0; i<n-1; i++){
            string cur=words[i];
            string next=words[i+1];
            for(int j=0; j<cur.length(); j++){
                //edge case e.g apple, app
                if(j >= next.length()) return false;

                //normal lexical condtn
                if(mp[cur[j]-'a'] > mp[next[j]-'a']) return false;

                if(mp[cur[j]-'a'] < mp[next[j]-'a']) break;
            }
        }

        return true;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //same as problem permutation in a string
        
        vector<int> ans;
        
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        
        int l1=s.size(),l2=p.size();
        
        if(l2>l1) return ans;
        
        int i=0,j=0;//pointers for our window
        //process our ist window of size p
        
        while(j < l2){
            phash[p[j]-'a']++;
            shash[s[j]-'a']++;
            
            j++;
        }
        j--;//to point to the end of our window
        
        while(j < l1){
            if(phash == shash){
                 ans.push_back(i);
            }
            
            j++;
            
            if(j != l1){
                shash[s[j]-'a']++;
                shash[s[i]-'a']--;
                
                i++;
            }
        }
        
        return ans;
    }
};
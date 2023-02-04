#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //using SLIDING WINDOW approach
        vector<int> s1hash(26,0);
        vector<int> s2hash(26,0);
        
        int l1=s1.length(),l2=s2.length();
        
        //base case
        if(l1 > l2) return false;
        
        int i=0,j=0;//i and j are two pointers for our window
        
    //processing first window of size of string 1
        while(j<l1){
            s1hash[s1[j]-'a']++;
            s2hash[s2[j]-'a']++;
            
            j++;//update pointer
        }
        
        j--;//to point right to the end of our window
        
        while(j<l2){
            
            if(s1hash == s2hash)
                return true;
            
            j++;//slide the end pt. of window and update the frequencies
            
            if(j != l2){
                s2hash[s2[j]-'a']++;
                s2hash[s2[i]-'a']--;//dropping one char..so,reduce the freq
                
                i++;//slide the st. point of window
            }
            
        }
        
        return false;//no anagram of s1 occurs in s2
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//app 2: memo
    int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        //base cases

        //s1 is exhausted --> s1 is empty
        if(i<0) return j+1;
        //s2 is exhausted --> s2 is empty
        if(j<0) return i+1;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return dp[i][j] = 0 + f(i-1,j-1,s1,s2,dp);
        }

        return dp[i][j] = 1 + min(
            f(i,j-1,s1,s2,dp),min(//insert
            f(i-1,j,s1,s2,dp),//delete
            f(i-1,j-1,s1,s2,dp)//replace
            )
        );

    }

    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m-1,n-1,word1,word2,dp);
    }
};
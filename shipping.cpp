#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //part of grp of prob on binary search
    
    //helper fun to find if current capacity of ship is feasible or not
    bool capacityOk(vector<int> &wt,int cap,int totalDays){
        int sum=0;
        int days=1;
        
        for(int x: wt){
            sum += x;
            if(sum > cap){
                days++;
                sum = x; //update sum for next slot
            }
        }
        
        return days <= totalDays;
    }
    
    int shipWithinDays(vector<int>& wt, int days) {
        //min. wt. capacity of ship
        int st=*max_element(wt.begin(),wt.end()); 
        //max. wt. cap. of ship is eq. to sum of wts.
        long long sum=0;
        for(int x: wt) sum += x;
        
        int end=sum;
        
        while(st <= end){
            int mid=st+(end-st)/2; //cur capacity of ship
            
            if(capacityOk(wt,mid,days)){
                end=mid-1;
            }
            
            else st=mid+1;    
        }
        
        return st; //dry run
    }
};
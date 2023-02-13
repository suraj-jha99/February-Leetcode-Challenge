#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/* algo: T.C : O(1)

let diff = high - low
1. bw two even no.s there are exactly diff/2 no.s bw them.
2. otherwise, there are always (diff/2)+ 1 no.s bw them.
*/
    int countOdds(int low, int high) {
        //both even
        if(low%2 == 0 && high%2 == 0){
            return (high-low)/2;
        }
        
        //else -> all other three case O->ODD,E->EVEN[OO,OE,EO]
        return (high-low)/2 + 1;
    }
};
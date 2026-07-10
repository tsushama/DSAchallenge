#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maximum(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculate(vector<int>& piles, int hourly){
        long long totalhrs = 0;

        for(int i = 0; i < piles.size(); i++){
            totalhrs += (piles[i] + hourly - 1) / hourly;   // ceil division
        }

        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = maximum(piles);
        int ans = high;

        while(low <= high){

            int mid = low + (high - low) / 2;

            long long req = calculate(piles, mid);

            if(req <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
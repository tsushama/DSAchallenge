class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
           unordered_map<int,unordered_set<int>> mp;
           for(auto &x:reservedSeats){
              int row=x[0];
              int seat=x[1];
              mp[row].insert(seat);
           }

           int result=(n-mp.size())*2;
           for(auto& [row, bookedseat] : mp){
               
                auto isavail=[&](int seat){
                    return bookedseat.find(seat)==bookedseat.end();
                };
                 
                bool grpA=isavail(2) && isavail(3) && isavail(4) && isavail(5);
                bool grpB=isavail(4) && isavail(5) && isavail(6) && isavail(7);
                bool grpC=isavail(6) && isavail(7) && isavail(8) && isavail(9);
                if(grpA && grpC){
                    result+=2;
                }
                else if(grpA || grpB || grpC){
                    result+=1;
                }
                
           }
           return result;
    }
};
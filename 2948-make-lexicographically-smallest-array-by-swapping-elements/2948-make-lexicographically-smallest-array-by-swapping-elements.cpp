class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
         int n=nums.size();
         vector<int> vec=nums;
         sort(vec.begin(),vec.end());
         int grpnum=0;
         unordered_map<int,int>numtogrp;
         numtogrp[vec[0]]=grpnum;
         unordered_map<int,list<int>>grptolist;
         grptolist[grpnum].push_back(vec[0]);
         for(int i=1;i<n;i++){
            if(abs(vec[i]-vec[i-1])>limit){
                grpnum+=1;
            }
            numtogrp[vec[i]]=grpnum;
            grptolist[grpnum].push_back(vec[i]);
         }

         vector<int> res(n);
         for(int i=0;i<n;i++){
            int num=nums[i];
            int grp=numtogrp[num];
            res[i]=*(grptolist[grp].begin());
            grptolist[grp].pop_front();       
        } 
        return res;
    }
};
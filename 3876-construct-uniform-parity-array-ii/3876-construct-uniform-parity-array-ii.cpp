class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int smalleven=INT_MAX,smallodd=INT_MAX;
        for(int i=0;i<n;i++){
               if(nums1[i]<smalleven && nums1[i]%2==0){
                smalleven=nums1[i];
               }
               else if(nums1[i]%2!=0 && nums1[i]<smallodd){
                smallodd=nums1[i];
               }
        }
        if(smallodd==INT_MAX || smalleven==INT_MAX) return true;
        if(smallodd>smalleven){
            return false;
        }
        return true;
    }
};
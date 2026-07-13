class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res;
        for(int i=1;i<9;i++){
            int num=i;
            int j=i+1;
            while(low<=high && j<=9){
                num=num*10+j;
                if(low<=num && num<=high){
                     res.push_back(num);
                }
                j++;
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
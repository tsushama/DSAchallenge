class Solution {
public:
    void reverseString(vector<char>& s) {
          vector<char> temp=s;
          int n=s.size();
          for(int i=0;i<n;i++){
            temp[(n-i-1)%n]=s[i];
          }
          for(int i=0;i<n;i++){
            s[i]=temp[i];
          }
    }
};
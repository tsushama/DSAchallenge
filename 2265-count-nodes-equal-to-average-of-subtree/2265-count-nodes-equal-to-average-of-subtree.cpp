/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res=0;
    int findsum(TreeNode* root,int &cnt){
        if(root==NULL) return 0;
        cnt++;
        int lsum=findsum(root->left,cnt);
        int rsum=findsum(root->right,cnt);
        return lsum+rsum+root->val;
    }
    void solve(TreeNode* root){
        if(root==NULL) return;
         int cnt=0;
         int sum=findsum(root,cnt);
         if(root->val==sum/cnt){
            res+=1;
         }
         solve(root->left);
         solve(root->right);

    }
    int averageOfSubtree(TreeNode* root) {
          solve(root);
          return res;
    }
};
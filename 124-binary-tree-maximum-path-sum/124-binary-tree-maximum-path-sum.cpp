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
int ans=INT_MIN;
int check(TreeNode* r){
if(r==NULL) return 0;

    int val1=check(r->left);
    int val2=check(r->right);
    
    ans=max(ans,r->val);
    if(r->left&&r->right) ans=max(ans,r->val+val1+val2);
    
    
    if(r->left) {
        ans=max(ans,r->val+val1);
         ans=max(ans,val1);
    }
    if(r->right) {
        ans=max(ans,val2);
        ans=max(ans,r->val+val2);
    }
    return max(r->val ,r->val+max(val1,val2));
    
}
int maxPathSum(TreeNode* root) {
    if(root==NULL) return 0;
    
    check(root);
    return ans;
}

};
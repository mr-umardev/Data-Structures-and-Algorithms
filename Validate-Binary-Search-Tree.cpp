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
    bool isValidBST(TreeNode* root) {
        return check(root,-2e10,2e10);
    }
    private:
    bool check(TreeNode* root,long long min_val, long long max_val){
        if(root==nullptr){
            return true;
        }
        if(root->val<=min_val || root->val>=max_val){
            return false;
        }
        return check(root->left,min_val,root->val) && check(root->right,root->val,max_val);
    }
};
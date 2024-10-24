class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return (root1 == root2)?1:
        (!root1 || !root2 || root1->val != root2->val)?0:
        (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
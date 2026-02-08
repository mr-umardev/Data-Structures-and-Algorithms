1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    bool isBalanced(TreeNode* root) {
15        if(root==nullptr){
16            return true;
17        }
18        int leftdepth=getHeight(root->left);
19        int rightdepth=getHeight(root->right);
20        int maxdepth=(1+max(leftdepth,rightdepth));
21        if(abs(leftdepth-rightdepth)<=1 && isBalanced(root->left) && isBalanced(root->right)){
22            return true;
23        }
24        return false;
25    }
26    int getHeight(TreeNode* root){
27        if(root==nullptr){
28            return 0;
29        }
30        int leftdepth=getHeight(root->left);
31        int rightdepth=getHeight(root->right);
32        return max(leftdepth,rightdepth)+1;
33    }
34};
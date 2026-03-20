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
    unordered_map<int,int>mp;
    int preIndex = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int inStart, int inEnd){
     if(inStart > inEnd) return NULL;
     int rootVal = preorder[preIndex++];
     TreeNode* root = new TreeNode(rootVal);
      int index = mp[rootVal];
      root->left = build(preorder,inorder,inStart,index-1);
      root->right = build(preorder,inorder,index+1,inEnd);

      return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i =0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return build(preorder,inorder,0,inorder.size()-1);
    }
};
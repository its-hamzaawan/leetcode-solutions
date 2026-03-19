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
    int postIdx;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int inStart, int inEnd){
    

     if(inStart > inEnd) return NULL;
     int rootVal = postorder[postIdx--]; // tracking root in postorder
     TreeNode* root = new TreeNode(rootVal);
     int index = mp[rootVal]; // now we know the boundary of left and right subtree
    root->right=  build(inorder,postorder,index+1,inEnd);
    root->left=  build(inorder,postorder,inStart,index-1);

    return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int n = inorder.size();
      postIdx = n-1;
       for(int i =0;i<n;i++){
        mp[inorder[i]] = i;
       }      
     return build(inorder,postorder,0,n-1);
    }
};
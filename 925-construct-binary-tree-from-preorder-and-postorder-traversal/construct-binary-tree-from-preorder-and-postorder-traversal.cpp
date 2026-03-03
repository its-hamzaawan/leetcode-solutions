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

    TreeNode* build(vector<int>& pre, vector<int>& post,int prestart,int preend, int poststart, int postend){
        
       if(prestart > preend) return NULL;

       //creating root
       TreeNode* root = new TreeNode(pre[prestart]);
       // if only one node then eturn
       if(prestart == preend) return root;

       // next element in the preorder is left subtree root

       int leftRoot = pre[prestart+1];
       // find left in postorder
       int idx = poststart;
       while(post[idx] != leftRoot) idx++;

       // number of nodes in left subtree
       int leftSize = idx-poststart+1;

       //build leftSubtree
       root->left = build(pre,post,prestart+1,prestart+leftSize,poststart,idx);
       // build rightsubtree
       root->right = build(pre,post,prestart+leftSize+1,preend,idx+1,postend-1);
       return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1);
    }

    };

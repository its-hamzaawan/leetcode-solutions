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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        // search in left and right side

        if(key < root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right=deleteNode(root->right,key);
        }
        else{ // found... now deleting
              

              // having no child
              if(root->left == NULL && root->right == NULL)
              return NULL; // attaching null with root

              // having one child
              if(root->left == NULL) return root->right; // attaching right to root
              else if(root->right==NULL) return root->left; // attaching left to root

              // having two children

              TreeNode* succ = root->right;
              while(succ->left!=NULL){
                succ=succ->left;
              }
              root->val = succ->val;
              root->right = deleteNode(root->right,succ->val);
        }
             return root;
    }
};
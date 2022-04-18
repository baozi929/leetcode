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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> tmpStack;
        TreeNode* curNode = root;
        TreeNode* tmpNode = nullptr;
        
        while(curNode || !tmpStack.empty()){
            if(curNode){
                tmpStack.push(curNode);
                curNode = curNode->left;
            }
            else{
                curNode = tmpStack.top();
                result.emplace_back(curNode->val);
                tmpStack.pop();
                curNode = curNode->right;
            }
        }

        return result;
    }
};
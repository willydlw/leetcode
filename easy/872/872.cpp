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

#include <iostream>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::cout << getLeafVal(root1) << "\n";
        return true;
    }

    int getLeafVal(TreeNode *root)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            return root->val;
        }

        return getLeafVal(root->left);
        return getLeafVal(root->right);
    }
};



void runTests(void)
{
    {   /* Example1
            Input: 
                root1 = [3,5,1,6,2,9,8,null,null,7,4]
                root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
            Output: true
        */
        TreeNode root1(3);
        TreeNode root2(3);
        Solution s;
        if(s.leafSimilar(&root1, &root2))
        {
            std::cout << "Program not complete\n";
        }
    }
}



int main(void)
{
    runTests();
    return 0;
}
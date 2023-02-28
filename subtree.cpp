#include<bits/stdc++.h>
using namespace std;

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
    string serialise(TreeNode* root,unordered_map<string,int> &map,vector<TreeNode*> &dupNodes){
        //base case
        if(root==NULL)
            return "x";
        
        string left=serialise(root->left,map,dupNodes);
        string right=serialise(root->right,map,dupNodes);
        
        string subtree= to_string(root->val) + "," + left + "," + right;
        
        //add this subtree in map
        map[subtree]++;
        
        //check in map
        if(map[subtree]==2)
            dupNodes.push_back(root);
        
        return subtree;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> map;
        vector<TreeNode*> dupNodes;
        
        string str = serialise(root,map,dupNodes);
       // cout<<str;
        
        return dupNodes;
    }
};
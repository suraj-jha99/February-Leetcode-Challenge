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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        
        vector<vector<int>> res;
        deque<TreeNode*> nodes;
        
        nodes.push_back(root);
        bool reverse=true;
        
        while(!nodes.empty()){
            
            int cnt=nodes.size();
            vector<int> ans;
            deque<TreeNode*> dq;
            
            for(int i=0;i<cnt;i++){
                
                TreeNode *front=nodes.front();
                ans.push_back(front->val);
                nodes.pop_front();
                
                if(reverse){
                    if(front->left) dq.push_front(front->left);
                    if(front->right) dq.push_front(front->right);
                }
                else{
                    if(front->right) dq.push_front(front->right);
                    if(front->left) dq.push_front(front->left);
                }
            }
            
            //insert nodes
            nodes.insert(nodes.end(),dq.begin(),dq.end());
            res.push_back(ans);
            
            //toggle the rev var
            reverse=!reverse;
            
        }
        return res;
    }
};
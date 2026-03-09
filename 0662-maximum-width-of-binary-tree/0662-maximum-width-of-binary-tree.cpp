class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        long long ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long start=q.front().second;
            long long end=q.back().second;
            ans=max(ans,end-start+1);
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                long long index=node.second-start;
                if(node.first->left) q.push({node.first->left,2*index+1});
                if(node.first->right) q.push({node.first->right,2*index+2});
            }
        }
        return ans;
    }
};
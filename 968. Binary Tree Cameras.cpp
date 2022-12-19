class Solution {
public:
    int ans;
    int dfs(TreeNode* root)
    {
        if(root==NULL)return 1;

        int left=dfs(root->left);
        int right=dfs(root->right);

        if(left==0 || right==0)
        {
            ans++;
            return 2;//set camera
        }
        else if(left==2 || right==2)return 1;// monitor
        else return 0;//nothing

        return -1;

    }
    int minCameraCover(TreeNode* root) {

        if(dfs(root)==0)ans++;
        return ans;
    }
};

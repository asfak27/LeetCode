class Solution {
public:
    vector<int>g[30001];
    int subtree[30001];
    int dp[30001];
    int N;
    void dfs(int node,int par)
    {
        subtree[node]=1;
        for(int i=0;i<g[node].size();i++)
        {
            int child=g[node][i];
            if(par!=child)
            {
                dfs(child,node);
                subtree[node]+=subtree[child];
                dp[node]+=dp[child]+subtree[child];
            }
        }
    }
    void dfs1(int node,int par)
    {
        subtree[node]=1;
        for(int i=0;i<g[node].size();i++)
        {
            int child=g[node][i];
            if(par!=child)
            {
                dp[child]=(N-subtree[child])+dp[node]-subtree[child];
                dfs1(child,node);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& ed) {
        
        int i,j,k;
        N=n;
        for(i=0;i<n-1;i++)
        {
            g[ed[i][0]].push_back(ed[i][1]);
            g[ed[i][1]].push_back(ed[i][0]);
        }
        
        dfs(0,-1);
        dfs1(0,-1);
        vector<int>ans;
        for(i=0;i<n;i++)ans.push_back(dp[i]);
        
        return ans;
    }
};

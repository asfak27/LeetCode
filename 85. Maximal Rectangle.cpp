class Solution {
public:
vector<int>nextsmallerelement(vector<int>&a,int n)
    {
        stack<int>st;
        st.push(-1);
        vector<int>v(n);
        for(int i=n-1;i>=0;i--)
        {
            int curr=a[i];
            while(st.top()!=-1 && a[st.top()]>=curr)
            {
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    vector<int>prevsmallerelement(vector<int>&a,int n)
    {
        stack<int>st;
        st.push(-1);

        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            int curr=a[i];
            while(st.top()!=-1 && a[st.top()]>=curr)
            {
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    int largestRectangleArea(vector<int>&a) {
        int n=a.size();
        vector<int>next(n);
        next=nextsmallerelement(a,n);

        vector<int>prev(n);
        prev=prevsmallerelement(a,n);
        
        int area=INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(next[i]==-1)
            {
                next[i]=n;
            }
            int l=a[i];
            int b=next[i]-prev[i]-1;
            int x=l*b;
            area=max(area,x);
        }
        return area; 
    }
    int maximalRectangle(vector<vector<char>>& a) {

        int ans=INT_MIN;

        vector<int>v(a[0].size(),0);

        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                if(a[i][j]=='1')
                {
                    v[j]++;
                }
                else v[j]=0;
            }
            ans=max(ans,largestRectangleArea(v));
        }
        return ans;
        
    }
};

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int dp[101][101][101];
    int helper(int i, int j, int size, vector<vector<int>> &arr, int k){
        if(i>=size || j>=size || k<0){ 
            return 0;
        }
        if(i==size-1 && j==size-1 && k==arr[i][j]){
            return 1;
        }
        if(i==size-1 && j==size-1 && k!=arr[i][j]){
            return 0;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int path1=helper(i+1, j, size, arr, k-arr[i][j]);
        int path2=helper(i, j+1, size, arr, k-arr[i][j]);
        return dp[i][j][k]=path1+path2;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        memset(dp, -1, sizeof dp);
        return helper(0,0,n,arr,k);
    }
};



//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends
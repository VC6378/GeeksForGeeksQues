//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
       public:
        int solve(int n,vector<int>&dp){
            // cout<<n<<" ";
            if(n==1 || n==0){
                return n;
            }
            
            if(dp[n]!=-1){
               // cout<<"hello";
                return dp[n];
            }
           
            int a=solve(n/2,dp);
            int b=solve(n/3,dp);
            int c=solve(n/4,dp);
            return dp[n]=max(a+b+c,n);
            
        }
        int maxSum(int n)
        {
            //code here.
            vector<int>dp(n+1,-1);
          return  solve(n,dp);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
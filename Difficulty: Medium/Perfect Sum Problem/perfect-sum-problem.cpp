//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = (int)(1e9+7);
	int f(int ind, int sum, int arr[], vector<vector<int>> &dp){
	    if(ind==0){
	        if(sum==0 and arr[ind]==0) return 2;
	        else if(sum==0 or arr[ind]==sum) return 1;
	        else return 0;
	    }
	    
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    
	    int nottaken = f(ind-1,sum,arr,dp)%mod;
	    int taken = 0;
	    if(arr[ind]<=sum) taken = f(ind-1,sum-arr[ind],arr,dp)%mod;
	    
	    return dp[ind][sum] = (taken%mod+nottaken%mod)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	    return f(n-1,sum,arr,dp);
        // Your code goes here
	}
	  
};




//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
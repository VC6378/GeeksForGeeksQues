//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
    vector<int> f(int arr[],int n,int sum){
        bool dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    dp[i][j]=false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        vector<int> ans;
        for(int i=0;i<sum+1;i++){
            if(dp[n][i]==true){
                ans.push_back(i);
            }
        }
        return ans;
    }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    int mini=INT_MAX;
	    vector<int> v=f(arr,n,sum);
	    for(int i=0;i<=v.size()/2;i++){
	        mini=min(mini,abs(sum-2*v[i]));
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int f(vector<int> &height,int ind,vector<int>&dp){
        if(ind==0){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int left=f(height,ind-1,dp)+abs(height[ind]-height[ind-1]);
        int right=INT_MAX;
        if(ind>1) right=f(height,ind-2,dp)+abs(height[ind]-height[ind-2]);
        return dp[ind]=min(left,right);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        return f(height,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends
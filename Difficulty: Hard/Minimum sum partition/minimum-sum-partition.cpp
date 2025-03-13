//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int target = sum;
        vector<vector<bool>> dp(n+1,vector<bool>(target+1));
        for(int i=0;i<=target;i++){
            dp[0][i]=false;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i=0;i<=target;i++){
            if(dp[n][i]){
                ans = min(ans,abs(target-2*i));
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
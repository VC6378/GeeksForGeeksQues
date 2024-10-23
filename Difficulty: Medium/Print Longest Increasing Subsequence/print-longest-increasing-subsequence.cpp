//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        int ans=-1;
        int lastind=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
                if(dp[i]>ans){
                    ans=dp[i];
                    lastind=i;
                }
            }
        }
        
        vector<int> s;
        s.push_back(arr[lastind]);
        while(hash[lastind]!=lastind){
            lastind=hash[lastind];
            s.push_back(arr[lastind]);
        }
        reverse(s.begin(),s.end());
        return s;
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
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
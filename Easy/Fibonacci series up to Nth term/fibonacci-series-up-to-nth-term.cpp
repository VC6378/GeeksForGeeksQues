//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        vector<int> ans;
        int mod=1e9+7;
        ans.push_back(0);
        ans.push_back(1);
        for(int i=2;i<=n;i++){
            int next=(ans[i-1]+ans[i-2])%mod;
            ans.push_back(next);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
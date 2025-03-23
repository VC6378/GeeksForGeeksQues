//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int f(vector<int> &dp,string digits,int ind,int n){
        if(ind>=n) return 1;
        if(dp[ind]!=-1) return dp[ind];
        if(digits[ind]=='0') return 0;
        int first = f(dp,digits,ind+1,n);
        int sec = 0;
        if(ind+1<n && stoi(digits.substr(ind,2))<=26){
            sec = f(dp,digits,ind+2,n);
        }
        return dp[ind] = first+sec;
    }
  
    int countWays(string &digits) {
        // Code here
        int n=digits.size();
        vector<int> dp(n,-1);
        return f(dp,digits,0,n);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string solve(string s, int r){
        if(r==0) return s;
        string ans="";
        for(int i=0;i<=(s.size()/2);i++){
            if(s[i]=='0') ans+="01";
            else ans+="10";
        }
        return solve(ans,r-1);
        
    }
    
    char nthCharacter(string s, int r, int n) {
        //code here
        string a = solve(s,r);
        return a[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
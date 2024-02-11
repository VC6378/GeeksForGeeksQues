//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long ans=0;
        int cnt=1;
        int mod=1e9+7;
        for(int i=1;i<=n;i++){
            long long prod=1;
            
            for(int j=1;j<=i;j++){
                prod=(prod*cnt)%mod;
                cnt++;
            }
            ans=(ans+prod)%mod;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
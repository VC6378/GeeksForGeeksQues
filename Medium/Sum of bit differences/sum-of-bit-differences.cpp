//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    
    long long sumBitDifferences(int arr[], int n) {
        // code here
        
        
        vector<vector<int>> f(31,vector<int>(2,0));
        
        for(int i=0; i<n; i++){
            
            for(int j=30; j>=0; j--){
                if(arr[i] & (1<<j)) f[j][1]++;
                else f[j][0]++;
            }
        }
        
        long long ans=0;
        
        for(int i=0; i<n; i++){
            
            for(int j=30; j>=0; j--){
                
                if(arr[i] & (1<<j)) ans+= f[j][0];
                else ans+= f[j][1];
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
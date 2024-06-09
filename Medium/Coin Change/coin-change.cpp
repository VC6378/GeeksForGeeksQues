//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int tabular(int v[],int k,int n){
    vector<vector<long long int>>ans(n+1,vector<long long int>(k+1,1LL*(-1)));
    // base caase
    for(int i=0;i<=k;i++){
        ans[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        ans[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            long long int a=0,b=0;
            if(i-1>=0&&j-v[i-1]>=0)a=ans[i][j-v[i-1]];
            if(i-1>=0)b=ans[i-1][j];
            ans[i][j]=a+b;
        }
    }
    return ans[n][k];

}
    long long int count(int v[], int n, int k) {
        return tabular(v,k,n);
        // code here.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int LCS(string str,int n,string str1,int m,vector<vector<int>> &dp){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str[i-1]==str1[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

int minDeletions(string str, int n) { 
    //complete the function here 
    string str1=str;
    reverse(str1.begin(),str1.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    int hehe=LCS(str,n,str1,n,dp);
    int result=n-hehe;
    return result;
} 
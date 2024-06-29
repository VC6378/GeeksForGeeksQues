//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    int palindromicPartition(string str)
    {
        
        memset(dp,-1,sizeof(dp));
        return f(str,0,str.length()-1);
        // code here
    }
    
    
    int f(string &s,int i,int j){
        if(i>=j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int left,right;
            if(dp[i][k]!=-1){
                left=dp[i][k];
            }
            else{
                left=f(s,i,k);
                dp[i][k]=left;
            }
            
            if(dp[k+1][j]!=-1){
                right=dp[k+1][j];
            }
            else{
                right=f(s,k+1,j);
                dp[k+1][j]=right;
            }
            
            int temp=left+right+1;
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
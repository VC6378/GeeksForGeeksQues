//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[205][205][2];
    int solve(string s,int i, int j, bool istrue){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(istrue){
                return (s[i]=='T');
            }
            else{
                return (s[i]=='F');
            }
        }
        if(t[i][j][istrue]!=-1){
            return t[i][j][istrue];
        }
        int ans=0;
        for(int k=i+1;k<=j-1;k+=2){
            int lt,lf,rt,rf;
            if(t[i][k-1][1]!=-1){
                lt=t[i][k-1][1];
            }
            else{
                lt=solve(s,i,k-1,1);
                t[i][k-1][1]=lt;
            }
            if(t[i][k-1][0]!=-1){
                lf=t[i][k-1][0];
            }
            else{
                lf=solve(s,i,k-1,0);
                t[i][k-1][0]=lf;
            }
            if(t[k+1][j][1]!=-1){
                rt=t[k+1][j][1];
            }
            else{
                rt=solve(s,k+1,j,1);
                t[k+1][j][1]=rt;
            }
            if(t[k+1][j][0]!=-1){
                rf=t[k+1][j][0];
            }
            else{
                rf=solve(s,k+1,j,0);
                t[k+1][j][0]=rf;
            }
            if(s[k]=='&'){
                if(istrue){
                    ans=(ans+lt*rt)%1003;
                }
                else{
                    ans=(ans+(lf*rt)+(lf*rf)+(lt*rf))%1003;
                }
            }
            else if(s[k]=='|'){
                if(istrue){
                    ans=(ans+(lt*rt)+(lt*rf)+(lf*rt))%1003;
                }
                else{
                    ans=(ans+(lf*rf))%1003;
                }
            }
            else if(s[k]=='^'){
                if(istrue){
                    ans=(ans+(lf*rt)+(lt*rf))%1003;
                }
                else{
                    ans=(ans+(lt*rt)+(lf*rf))%1003;
                }
            }
        }
        t[i][j][istrue]=ans;
        return ans;
    }
    int countWays(int n, string s){
        memset(t,-1,sizeof(t));
        int ans=solve(s,0,n-1,1);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
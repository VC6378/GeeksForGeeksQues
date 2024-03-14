//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        int byrows[n][n];
        int bycol[n][n];
        
        for(int i=0;i<n;i++){
            int row=0;
            for(int j=0;j<n;j++){
                if(a[i][j]=='X'){
                    row++;
                }
                else{
                    row=0;
                }
                byrows[i][j]=row;
            }
        }
        
        for(int i=0;i<n;i++){
            int col=0;
            for(int j=0;j<n;j++){
                if(a[j][i]=='X'){
                    col++;
                }
                else{
                    col=0;
                }
                bycol[j][i]=col;
            }
        }
        
        int res=0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int side=min(byrows[i][j],bycol[i][j]);
                while(side>res){
                    if(byrows[i-side+1][j]>=side && bycol[i][j-side+1]>=side){
                        res=side;
                    }
                    else{
                        side--;
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends
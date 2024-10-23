//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool f(vector<vector<int>>&dp,vector<int> &arr,int target,int ind){
        if(target==0) return true;
        if(ind==arr.size()){
            if(target==0) return true;
            return false;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool take=false;
        if(arr[ind]<=target){
            take=f(dp,arr,target-arr[ind],ind+1);
        }
        bool nottake = f(dp,arr,target,ind+1);
        return dp[ind][target]=(take || nottake);
    }
  
    bool isSubsetSum(vector<int> arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(dp,arr,sum,0);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}

// } Driver Code Ends
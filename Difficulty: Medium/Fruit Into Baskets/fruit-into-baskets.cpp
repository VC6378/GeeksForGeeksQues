//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int n=arr.size();
        int ans=0;
        int i=0;
        int j=0;
        unordered_map<int,int> mp;
        int maxi=0;
        if(n==0 or n==1 or n==2) return n;
        while(j<n){
            mp[arr[j]]++;
            if(mp.size()<2){
                j++;
            }
            if(mp.size()==2){
                maxi=max(maxi,j-i+1);
                j++;
            }
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0){
                        mp.erase(arr[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
			 void powerSet(int ind, vector<string> &ans, string &result, string feed){
	        if(ind>=feed.size()){
	            if(result.size()>0){
	                ans.push_back(result);
	            }
	            return;
	        }
	        
	        result.push_back(feed[ind]);
	        powerSet(ind+1, ans, result, feed);
	        result.pop_back();
	        powerSet(ind+1,ans,result,feed);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string result;
		    powerSet(0,ans,result,s);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
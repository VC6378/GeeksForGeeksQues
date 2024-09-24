//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int> mpp(26,0);
        for(char ch:p){
            mpp[ch-'a']++;
        }
        
        int cnt=p.size();
        int i=0;
        int j=0;
        int n=s.length();
        if(cnt>n) return "-1";
        int mini=INT_MAX;
        int sp=0;
        while(j<n){
            if(mpp[s[j]-'a']>0) cnt--;
            mpp[s[j]-'a']--;
            
            while(cnt==0){
                int currsize=j-i+1;
                if(currsize<mini){
                    mini=currsize;
                    sp=i;
                }
                
                mpp[s[i]-'a']++;
                if(mpp[s[i]-'a']>0){
                    cnt++;
                }
                i++;
            }
            j++;
        }
        
        return mini==INT_MAX?"-1":s.substr(sp,mini);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
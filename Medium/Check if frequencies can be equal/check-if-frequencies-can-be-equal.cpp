//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
{
    unordered_map<char, int> map;
    int freq = 0;
    
    for(char ch: s) if(++map[ch] > freq) freq = map[ch];
    if(map.size() == 1) return 1;
 
    bool flag = true;
    for(auto it: map){
        if(it.second == 1) continue;
        if(it.second != freq){
            flag = false;
            break;
        }
    }
    if(flag) return 1;
    
    flag = true;
    for(auto it: map){
        if(it.second == freq){
            if(flag) flag = false;
            else return 0;
        }
        else if(it.second != freq-1) return 0;
    }
    return 1;
}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends
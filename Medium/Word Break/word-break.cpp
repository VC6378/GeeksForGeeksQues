//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:

    int f(int ind,string temp,string &s,unordered_set<string> &st){
        if(ind==s.size()) return 0;
        temp+=s[ind];
        if(ind==s.size()-1){
            return st.find(temp)!=st.end();
        }
        int op1=0;
        int op2=0;
        if(st.find(temp)!=st.end()){
            op1=f(ind+1,"",s,st);
        }
        op2=f(ind+1,temp,s,st);
        return op1||op2;
    }
    

    int wordBreak(int n, string s, vector<string> &dict) {
        //code here
        unordered_set<string> st;
        for(auto it:dict){
            st.insert(it);
        }
        
        return f(0,"",s,st);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends
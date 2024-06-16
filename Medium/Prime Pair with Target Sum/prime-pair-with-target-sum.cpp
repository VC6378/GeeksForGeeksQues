//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
    vector<bool> seive(int n){
        vector<bool> isPrime(n+1,true);
        isPrime[0]=isPrime[1]=false;
        for(int p=2;p*p<=n;p++){
            if(isPrime[p]){
                for(int i=p*p;i<=n;i+=p){
                    isPrime[i]=false;
                }
            }
        }
        return isPrime;
    }
  
    vector<int> getPrimes(int n) {
        // code here
        vector<bool> prime=seive(n);
        if(prime[n-2]) return {2,n-2};
        if(prime[n-3]) return {3,n-3};
        for(int i=2;i<(n/2);i++){
            if(prime[i] && prime[n-i]) return {i,n-i};
        }
        return {-1,-1};
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans;
        ans.push_back(0);
       for(int i=1;i<=n;i++){
           int t=help(i);
           ans.push_back(t);
       }
       return ans;
    }
    private:
    int help(int n){
        if(n<=3) return n;
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
                if(isprime(i)) return i;
            }
        }
        return n;
    }
    bool isprime(int n){
        if(n<=3) return true;
        for(int i=2;i<n/2;i++){
            if(n%i==0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends
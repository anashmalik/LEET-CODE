//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int> fr;
        for(int i=0;i<n;i++){
           fr[arr[i]]++;
        }
        int mi=INT_MAX;
        int ans=0;
        for(auto i=fr.begin();i!=fr.end();i++){
            int e=i->first;
            int f=i->second;
            if(f<mi){
                mi=f;
                ans=e;
            }
            else if(f==mi&&e>ans) ans=e;
        }
       return ans; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends
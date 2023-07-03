//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int i=0,j=n-1,m=INT_MIN;
        int t[n];
        int l[n];
        t[0]=arr[0];
        l[n-1]=arr[n-1];
       for(i=1;i<n;i++){
        t[i]=min(arr[i],t[i-1]);
        l[n-1-i]=max(l[n-i],arr[n-i-1]);
       }
       i=0;
       j=0;
       while(i<n&&j<n){
           if(t[i]<=l[j]){
               m=max(m,j-i);
               j++;
           }
           else i++;
       }
        return m;
    }
    

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
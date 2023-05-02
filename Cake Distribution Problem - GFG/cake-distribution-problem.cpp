//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    int mi=INT_MAX,hi=0,l=N,ans;
    while(N--){
        mi=min(sweetness[N],mi);
        hi+=sweetness[N];
    }
    while(mi<=hi){
        int mid = (hi+mi)/2;
        if(pro(mid,sweetness,K)){
            ans=mid;
            mi=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
    }
bool pro(int m,vector<int>& arr,int k){
    int per=0,sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>=m){
            per++;
            sum=0;
        }
    }
    return per>=k+1;
}
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends
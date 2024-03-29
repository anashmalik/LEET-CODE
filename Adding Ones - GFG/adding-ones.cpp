//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
   void update(int a[], int n, int u[], int k)
{
    int prefixSum[n];  // Array to store prefix sums
    memset(prefixSum, 0, sizeof(prefixSum));

    for (int i = 0; i < k; i++) {
        int j = u[i];
        prefixSum[j - 1]++;
    }

    for (int i = 1; i < n; i++) {
        prefixSum[i] += prefixSum[i - 1];
    }

    for (int i = 0; i < n; i++) {
        a[i] += prefixSum[i];
    }
}

};

//{ Driver Code Starts.
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n]={0}, updates[k]={0};
		for(int i = 0; i < k; i++)
		cin>>updates[i];
		Solution ob;
		ob.update(a, n, updates, k);
		
		for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
		
		cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
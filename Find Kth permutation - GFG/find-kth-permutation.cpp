//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        string ans;
        int i=1;
        while(i<=n) {
            char s[1];
             sprintf(s,"%d",i);
            ans.push_back(s[0]);
            i++;
        }
        k--;
        while(k--) next_permutation(ans.begin(), ans.end());
        //cout<<ans;
        return ans;
    }      
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
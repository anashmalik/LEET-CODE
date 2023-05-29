//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> d, string p) {
        // code here
        vector<string> ans;
        for(int i=0;i<N;i++){
            string r;
            for(int j=0;j<d[i].length();j++){
                if(isupper(d[i][j])){
                    r.push_back(d[i][j]);
                }
            }
            if(p==r.substr(0,p.length())){
                ans.push_back(d[i]);
            }
        }
        if(ans.size()==0) ans.push_back("-1");
        return ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
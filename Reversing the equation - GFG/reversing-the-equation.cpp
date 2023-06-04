//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        { string ans;
           for(int i=s.length()-1;i>=0;i--){
               if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*') ans.push_back(s[i]);
               else if(isdigit(s[i])){
                   string p;
               while(isdigit(s[i])){
                  p=s[i]+p;
                   i--;
               }
                   ans.append(p);
                   i++;
               }
           }
           return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
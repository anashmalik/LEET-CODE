//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int nextHappy(int N){
        // code here
        while(true){
            if(help(++N)) break;
        }
        return N;
    }
    int help(int n){
        while(n>=7){
            int t=0;
            while(n){
                int i=n%10;
                t+=i*i;
                n/=10;
            }
            n=t;
        }
        if(n==1) return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> addOperators(string S, int target) {
        int n=S.length();
        vector<string> re;
        string ans="";
        char q=S[0];
        ans.push_back(S[0]);
        maker(S,ans,re,target,1,n,q);
        return re;
    }
    void maker(string s ,string re,vector<string> &ans,int tar, int i,int n,char q){
        if(i==n){
            if(evaluate(re)==tar){
                ans.push_back(re);
                
            }
            return;
        }
        if(i>n) return;
        if((re[re.length()-1]=='+')||(re[re.length()-1]=='-')||(re[re.length()-1]=='*')){
            re.push_back(s[i]);
            q=s[i];
            maker(s,re,ans,tar,i+1,n,q);
        }
        else{
            string te=re,yt=re,mm=re;
            re.push_back('+');
            te.push_back('-');
            yt.push_back('*');
             maker(s,re,ans,tar,i,n,q);
              maker(s,te,ans,tar,i,n,q);
               maker(s,yt,ans,tar,i,n,q);
               if(q!='0'){
                   mm.push_back(s[i]);
            maker(s,mm,ans,tar,i+1,n,q);
               }

            
        }
        
        
    }
    

int precedence(char op){
	if(op == '+'||op == '-')
	return 1;
	if(op == '*'||op == '/')
	return 2;
	return 0;
}

int applyOp(int a, int b, char op){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

int evaluate(string tokens){
	int i;
	stack <int> values;
	
	stack <char> ops;
	
	for(i = 0; i < tokens.length(); i++){
		
		if(tokens[i] == ' ')
			continue;
		
		else if(tokens[i] == '('){
			ops.push(tokens[i]);
		}
		
		else if(isdigit(tokens[i])){
			int val = 0;
			while(i < tokens.length() &&
						isdigit(tokens[i]))
			{
				val = (val*10) + (tokens[i]-'0');
				i++;
			}
			
			values.push(val);
			
			
			i--;
		}
		else if(tokens[i] == ')')
		{
			while(!ops.empty() && ops.top() != '(')
			{
				int val2 = values.top();
				values.pop();
				
				int val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			
			if(!ops.empty())
			ops.pop();
		}
		
		else
		{
			while(!ops.empty() && precedence(ops.top())
								>= precedence(tokens[i])){
				int val2 = values.top();
				values.pop();
				
				int val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			ops.push(tokens[i]);
		}
	}
	while(!ops.empty()){
		int val2 = values.top();
		values.pop();
				
		int val1 = values.top();
		values.pop();
				
		char op = ops.top();
		ops.pop();
				
		values.push(applyOp(val1, val2, op));
	}
	return values.top();
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {   Node* temp=head;
    vector<int> re,k;
        while(temp!=NULL){
            re.push_back(temp->data);
            //cout<<temp->data<<"\t";
            temp=temp->next;
        }
        
        int t=re.size(),i;
        if(t==1){
            return head;
        }
        k=re;
        Node* ans= new Node(re[t-1]-re[0]);
        Node* s=ans;
        for(i=1;i<(re.size()/2);i++){
            re[i]= re[t-i-1]-re[i];
            Node* w=new Node(re[i]);
            s->next=w;
            s=s->next;
        }
        int j=i;
        if(t%2==0){
            j--;
        }
        for(i;i<t;i++){
            re[i]=k[j];
            j--;
            Node* w=new Node(re[i]);
            s->next=w;
            s=s->next;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends
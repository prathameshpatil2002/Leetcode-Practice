//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverse(struct Node* head){
        if(!head || !head->next){
            return head;
        }
        
        struct Node* p = head, *c = head->next , *t = NULL;
        head->next = NULL;
        while(c){
            t = c->next;
            c->next = p;
            p = c;
            c = t;
        }
        return p;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if(!first ||!second){
            return NULL;
        }
        
        struct Node* revf = reverse(first);
        struct Node* revs = reverse(second);
        struct Node* ret = NULL, *retT = NULL;
        
        
        int c = 0;
        
        while(revf&&revs){
            int res = revs->data + revf->data + c;
            
            struct Node* n = new struct Node(res%10);
            
            c = res/10;
            
            if(ret == NULL){
                ret = n;
                retT = n;
            }
            else{
                retT->next = n;
                retT = n;
            }
            
            revs = revs->next;
            revf = revf->next;
        }
        
        while(revf){
            int res = revf->data + c;
            
            struct Node* n = new struct Node(res%10);
            
            c = res/10;
            
            if(ret == NULL){
                ret = n;
                retT = n;
            }
            else{
                retT->next = n;
                retT = n;
            }
            revf = revf->next;
        }
        while(revs){
            int res = revs->data + c;
            
            struct Node* n = new struct Node(res%10);
            
            c = res/10;
            
            if(ret == NULL){
                ret = n;
                retT = n;
            }
            else{
                retT->next = n;
                retT = n;
            }
            revs = revs->next;
        }
        
        if(c>0){
            struct Node* n = new struct Node(c);
            if(ret == NULL){
                ret = n;
                retT = n;
            }
            else{
                retT->next = n;
                retT = n;
            }
        }
        
        retT->next = NULL;
        return reverse(ret);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
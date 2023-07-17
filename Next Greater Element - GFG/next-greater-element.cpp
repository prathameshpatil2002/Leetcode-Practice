//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ret(n);
        
        stack<long long>s;
        for(int i=n-1; i>=0; i--){
            if(s.empty()){
                ret[i] = -1;
                s.push(arr[i]);
            }
            else{
                while(!s.empty()){
                    if(s.top()<=arr[i]){
                        s.pop();
                    }else{
                        break;
                    }
                }
                if(!s.empty()){
                    ret[i] = s.top();
                }
                else{
                    ret[i] = -1;
                }
                s.push(arr[i]);
            }
        }
        
        return ret;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
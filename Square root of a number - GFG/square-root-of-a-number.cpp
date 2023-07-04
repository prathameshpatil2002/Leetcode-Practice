//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long l = 1;
        long long r = x;
        
        while(l<=r){
            long long mid = l+(r-l)/2;
            
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid > x){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return r;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends
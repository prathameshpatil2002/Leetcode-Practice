class Solution {
public:
    int maxInHistogram(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                int height=arr[st.top()];
                st.pop();
                int width;
                if(st.empty())  width=i;
                else     width=i-st.top()-1;
                maxi=max(maxi,(height*width));
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // not able to solve 
        // learning solution
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        int area=0;
        vector<int> hist(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')    hist[j]+=1;
                else    hist[j]=0;
            }
            area=max(area,maxInHistogram(hist));
        }
        return area;
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
            return {1};
        }
        
        if(rowIndex==1){
            return {1,1};
        }
        vector<int>v(rowIndex+1,0);
        v[0] = 1;
        v[1] = 1;
        v[rowIndex] = 1;
        
        for(int i=2;i<=rowIndex; i++){
            int l = 0,r = 1;
            int k = 1;
            vector<int>temp = v;
            while(r<rowIndex){
                v[k++] = temp[l]+temp[r];
                l++;
                r++;
            }
        }
        return v;
    }
};
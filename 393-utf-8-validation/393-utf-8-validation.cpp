class Solution {
public:
    bool validUtf8(vector<int>& data) {
        vector<bitset<8>>v;
        for(auto it : data){
            bitset<8>v1(it);
            cout<<v1<<"\n";
            v.push_back(v1);
        }
        
        int i = 0;
        int n = v.size();
        while(i<n){
            int count = 0;
            for(int k=7; k>=0; k--){
                if(v[i][k]==0){
                    break;
                }
                else{
                    count++;
                }
            }
            if(count>=5){
                return false;
            }
            if(count==0){
                i++;
                continue;
            }
            else if(count==1){
                return false;
            }
            else{
                int j=i+1;
                count--;
                while(j<n){
                    if(count==0){
                        break;
                    }
                    else if(v[j][7]==1&&v[j][6]==0){
                        count--;
                        j++;
                    }
                    else{
                        return false;
                    }
                }
                if(count!=0){
                    return false;
                }
                i = j;
            }
        }
        
        return true;
    }
};
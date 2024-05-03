class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>SumArrayOne,SumArrayTwo;
        long long sum = 0;
        for(int i=0; i<version1.length(); i++){
            if(version1[i]=='.'){
                SumArrayOne.push_back(sum);
                sum = 0;
            }
            else{
                sum = sum*10 + version1[i]-'0';
            }
        }
        SumArrayOne.push_back(sum);
        sum = 0;
        for(int i=0; i<version2.length(); i++){
            if(version2[i]=='.'){
                SumArrayTwo.push_back(sum);
                sum = 0;
            }
            else{
                sum = sum*10 + version2[i]-'0';
            }
        }
        SumArrayTwo.push_back(sum);
        sum = 0;
        if(SumArrayTwo.size()>SumArrayOne.size()){
          while(SumArrayTwo.size()!=SumArrayOne.size()){
              SumArrayOne.push_back(0);
          }
        }
        else if(SumArrayTwo.size()<SumArrayOne.size()){
             while(SumArrayTwo.size()!=SumArrayOne.size()){
              SumArrayTwo.push_back(0);
          }
        }
        
            for(int i=0; i<SumArrayTwo.size(); i++){
                if(SumArrayTwo[i]>SumArrayOne[i]){
                    return -1;
                }
                else if(SumArrayTwo[i]<SumArrayOne[i]){
                    return 1;
                }
            }
           
        return 0;
    }
};
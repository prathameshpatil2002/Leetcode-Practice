class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        map<int,int>m;
        for(int i=0; i<n;i++){
            int power = 0;
            int num = 0;
            reverse(nums[i].begin(),nums[i].end());
            for(auto it : nums[i]){
                num = num + pow(2,power)*(it-'0');
                power++;
            }
            m[num]++;
        }
        for(int i=0; i<65536; i++){
            if(m[i] == 0){
                if(i==0){
                    string s = "";
                    while(n){
                        s.push_back('0');
                        n--;
                    }
                    return s;
                }
                 string s = "";
                 int power = 0;
                while(i){
                    int rem = i%2;
                    i /= 2;
                    s.push_back(rem+'0');
                }
                while(s.size()!=n){
                    s.push_back('0');
                }
                reverse(s.begin(),s.end());
                return s;
            }
        }
        
        return "10000000000000000";
        
    }
};
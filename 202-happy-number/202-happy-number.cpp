class Solution {
public:
    bool isHappy(int n) {
        int ans=0;
        set<int> s;
        while(n>0){
            if (n/10==0){
                ans+=pow((n%10),2);
                n=ans;
                if (ans==1)
                    return true;
                if (find(s.begin(),s.end(),ans)!=s.end())
                    return false;
                s.insert(ans);
                ans=0;
                continue;
            }
            ans+=pow((n%10),2);
            n/=10;
        }
        return false;
    }
};
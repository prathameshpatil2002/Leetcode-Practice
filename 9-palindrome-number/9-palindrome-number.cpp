class Solution {
public:
    bool isPalindrome(int x) {
      
     int temp=x;
     long long rev=0;
        while(x>0){
            int l=x%10;
            rev=(rev*10)+l;
            x=x/10;
        }
      if(temp==rev){
        return 1;
      }
    else{
        return 0;  
    }
     
    }
};
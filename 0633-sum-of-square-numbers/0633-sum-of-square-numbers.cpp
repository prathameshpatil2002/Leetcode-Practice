class Solution {
public:
    bool judgeSquareSum(int c) {
        long  l = 0 , r = sqrt(c);
        while( l <= r)
        {
            long x = l * l , y = r * r ;
            if ( x + y < c)  l++ ;
            else if ( x + y  > c)  r-- ;
            else return true ;
        }
            return false;
    }
};
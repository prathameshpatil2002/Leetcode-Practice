class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);
        int l = 0,h = 31;
        while(l<h){
            int t  = b[l];
            b[l] = b[h];
            b[h] = t;
            l++;
            h--;
        }
        return b.to_ulong();
        
    }
};
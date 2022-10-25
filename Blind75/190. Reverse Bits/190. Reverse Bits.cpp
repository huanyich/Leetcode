class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int count = 32;
        while(count--){
            res<<=1;
            if(n%2==1) res+=1;
            else res+=0;
            n>>=1;
        }
        return res;
        
    }
};

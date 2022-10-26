class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            unsigned carry = (a&b);
            a = (a^b); // a^b is the number without carry
            b = carry<<1;
        }
        return a;
    }
};


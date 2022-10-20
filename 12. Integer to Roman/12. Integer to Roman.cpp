class Solution {
public:
    
    string intToRoman(int num) {
        string res="";
        int count;
        //deal with 1000 first
        count = num/1000;
        num%=1000;

        for(int i=0; i<count; i++) res+="M";
        //deal with 100
        count = num/100;
        num%=100;

        if(count==4) res+="CD";
        else if(count==5) res+="D";
        else if(count==9) res+="CM";
        else{
            if(count<4) for(int i=0; i<count; i++) res+="C";
            if(count>5){
                res+="D";
                for(int i=0; i<count-5; i++) res+="C";
            }
        }
        count = num/10;
        num%=10;

        if(count==4) res+="XL";
        else if(count==5) res+="L";
        else if(count==9) res+="XC";
        else{
            if(count<4) for(int i=0; i<count; i++) res+="X";
            if(count>5){
                res+="L";
                for(int i=0; i<count-5; i++) res+="X";
            }
        }
        if(num==4) res+="IV";
        if(num==5) res+="V";
        if(num==9) res+="IX";
        else{
            if(num<4) for(int i=0; i<num; i++) res+="I";
            if(num>5){
                res+="V";
                for(int i=0; i<num-5; i++) res+="I";
            }
        }
        
        return res;
    }
};

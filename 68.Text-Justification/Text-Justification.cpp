class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;
        for(int i=0; i<n; i++){
            int currLength = 0;
            int j = i;
            while(j < n && currLength <= maxWidth){
                if(currLength==0){ // just start a new line
                    currLength+=words[j].size();
                }else{
                    currLength += 1 + words[j].size();
                }
                j++;
            }
            // when break the condition
            j--;
            if(currLength > maxWidth){
                currLength -= 1+words[j].size();
                j--;
            }
            if(j!=n-1){
                res.push_back(helper(words, maxWidth, i, j));
            }else{ // its the last line
                string curr = "";
                //[i..j]
                curr+=words[i];
                for(int k=i+1; k<=j; k++){
                    curr+=" "+words[k];
                }
                int needSpace = maxWidth - curr.size();
                curr+= addSpace(needSpace);
                res.push_back(curr);
            }
            i = j;
        }
        return res;
    }
    
    string addSpace(int n){
        string ret = "";
        for(int i=0; i<n; i++){
            ret+=" ";
        }
        return ret;
    }
    
    string helper(vector<string>& words, int maxWidth, int a, int b){
        if(a==b){ // corner case
            return words[a]+addSpace(maxWidth - words[a].size());
        }
        
        int sum = 0; //calcualte the words size
        for(int i=a; i<=b; i++){
            sum+=words[i].size();
        }
        string ret = "";
        int space = (maxWidth - sum)/(b-a);
        int extraSpace = maxWidth - space*(b-a) - sum;
        for(int i=a; i<a+extraSpace; i++){
            ret+=words[i]+addSpace(space + 1);
        }
        for(int i=a+extraSpace; i<b; i++){
            ret+=words[i] + addSpace(space);
        }
        ret+=words[b];
        return ret;
    }
    
    
    
};




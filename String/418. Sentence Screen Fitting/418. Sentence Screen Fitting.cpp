class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int wordCount = 0;
        int n = sentence.size();
        unordered_map<int, int> Map;

        for(int i=0; i<rows; i++){
            int start = wordCount%n; // now starts at this index
            if(Map.count(start)){
                wordCount+=Map[start];
            }else{
                int currWordCount = 0;
                for(int j=start,len=0; len<cols; j = (j+1)%n, currWordCount++){
                    if(len + sentence[j].size() > cols){
                        break;
                    }else{
                        len+=sentence[j].size()+1; // add one more space to it
                    }
                }
                wordCount+=currWordCount;
                Map[start] = currWordCount;
            }
        }


        return wordCount/n;
    }


};

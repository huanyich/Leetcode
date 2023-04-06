Intuition
To keep track of the number of words that can fit in a single row starting from a new row with sentence[index]. This way, whenever we have a new row, we can easily find out how many words will fit in it.

We can use a variable called "wordCount" to record the total number of words that can fit on the screen. When iterating through each row, we first calculate the starting index of the sentence, which will be wordCount % n (where n is the width of the screen). We then check if we have already calculated the number of words that can fit for this starting index by looking it up in a Map. If it has not been calculated yet, we start the calculation.

The finally answer will be wordCount%n because this equivalent to how many times all the sentences has go through.

Approach
Dynamic Programming

Complexity
Time complexity: O(n*rows)
Space complexity: O(n)

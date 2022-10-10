Sliding Window Solution:  
**keep track of the global most obvious characater.    

use a HashMap to track the current window characters' frequency.  
Use the length - freq > k to determine if we already use more than k switches.  
maintain the answer integer.  

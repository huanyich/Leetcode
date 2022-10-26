Consider the properity of remainder,  
if  a%k='?' that means that if previous exist a prefix sum also has a remainder '?',  
we could use curr_sum - previous prefix sum to make the remainder 0.

******So the idea is to use prefix sum and hashmap********
Use hash map to store every remainder as the key and the first position as the value.
make sure that i-j>1, when we create a hashmap, make sure to Add(0,0) first, that will be the base.

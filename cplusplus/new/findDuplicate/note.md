how to do:  
Not trivial if you don't know the method to find a cycle inside of a linked list.  
Knowing that, this question is extremly easy.  
The method:
Two pointers, one fast and one slow.  
Move the fast one two steps at a time and the slow one, one step.  
When they meet, reset one of them.  
Now move both at the same speed, they will meet at the entry point of the cycle.  
The duplicate is the index of that entry point, because there are two numbers that point to that entry point.  
While the pointers, are the numbers in the slots.

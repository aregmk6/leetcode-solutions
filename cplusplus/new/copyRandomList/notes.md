My original way:
We can use an hash map to mark addresses that where already copied, so we won't copy them twice.  
In addition, using recursion will make it fast.  

Another interesting way I saw in the solutions:
You can edit the original, to help you with keeping track, and then fix the changes, and that allows for no hash map usage.

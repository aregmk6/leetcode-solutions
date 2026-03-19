# Problems
## Reverse k-nodes
* recursion is very useful here. Which is basically the same as using a stack or queue, but with less space usage.
* to do it with no extra space, just look at this, lets say you want to reverse 1->2->3. You think about it like 3->2->1. Ok. but look at it
in another way: 1<-2<-3. This is very easy to do with pointers.
* cleanest method of doing so is to use a dummy node.

## group anagrams
* you can sort the strings and than sort the array.
* you can also use a hash map, while the hash key is either the sorted string or the histogram of the string. Histogram is faster.
* interesting way to create a hash, is to use the built in hash of a string, and just converting the histogram into a string, with some
delimiting character, for example "$".

# algorthims
## binary search
* it's better to use mid = left + (right - left) / 2, instead of mid = (right + left) / 2, to avoid overflow for very large intergers. This is
also true for Merge Sort.
* choose a search range invariant, closed or half open. If it's closed you give "right = size - 1", if it's half open you give "right = size".
For the next iterations, you do "right = mid - 1" and "right = mid" respectivly. For left, they are both "left = mid + 1". To understand if
we need "<" or "<=", run an exmple on an array of size 1. For a closed, you will have left = right = 0, so you must have "<=", or it won't go
into the while loop, it won't go into an endless loop, because it that iteration left and right will update and cross each other. For a half
open loop it will be "<".

## Merge Sort
* you send left and right *indexes* and calc mid according to them.

## Quick Sort
* partition, putting the selected pivot on the right, with left and right pointers. right will point at the *first* item that is smaller than
the pivot, and left will point at the *first* item that is bigger than the pivot. When the left and right pointers go past each other, we are
done. Swap the pivot with the item at the left pointer.
* for partition, if we get an equal to the pivot element we should *stop* and swap. Because assume we have an array of equal elements. This way left and right will meet in the middle, putting the pivot at the middle, which is perfect for quick sort.

## KMP
* KMP pattern matching algorithm for linear time matching.
* Build LPS array... *TODO*


# data structure basics
## heaps
* the first non leaf is at floor(n/2) - 1.

## linked lists
* having a parent pointer follow an iterator is very simply done with assigning the parent to the iterator, before moving the iterator.

## hash table
* a classic string hash function is a polynomial hash function.

# ways of thinking about things
* It's good to think about arrays, their elements and the indices like so:
```
                                     elements:  [ 1 , 2 , 3 , 4 ]
                                     indicies:  0   1   2   3   4
```
basically, the commas are the indices and the elements are between the indices. Therefore the element is to the *right* of the index.
This way, it's easier to think about a partition, because the index at the partition, really defines a partition, because the index lays between
the elements.

# smart tricks
* if you care about which array is bigger, and you're working with two arrays, you can just check which is bigger, and call the function again
  with the parameters reversed if the one you need is not the small one. This is only relevent if you're working with only two parameteres.
* check for overflow with simple algebra: a + b > max <=> a > max - b.
* using a dummy node for edge cases in problems that need to change things about a linked list.
* things in which you need to reverse, it's usefull to use a stack, queue or just recursion.
* you can return two arrays, by the other one being one of the parameters. They give you a pointer to a pointer, when that first pointer is the
address at which the array needs to go. You must allocate that array and return it at that address. To return it, you dereference the ** pointer
given to you, and put in the array you created.


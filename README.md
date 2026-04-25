# TODO 
[ ] - try to solve the Evaluate Reverse Polish Notation problem with recursion.

# Problems
## Print in Order
* If you don't broadcast the signal you will get a deadlock.
* why? Well, if thread 2 and 3 already hit the Cond.wait(). And only now thread 1 comes and calls signal. Thread 3 (not 2) wakes up, and only it
(bacause it's a signal) and tries to continue but doesn't because the condition is not met yet and goes back to sleep. Thread 3 is waiting for 
thread 2, but it's asleep, and there is no thread that exists to signal it.

## Print Foo Bar 
* Use *two* channels instead of busy waiting.

## 3 sum
* do the two sum, after the hook point.
* if the current hook number is the same as the previous, just skip it.
* if the current left number is the same as the previous, just skip it.
* the reason that is enough to avoid dups is because you sort the array first!
* also, in the inner loop, when you find a sum, and continue, you do left++ *and* right--, why? Because if you found a hook + left + right = sum
, and you only decrease left (or only increase right), then you can get a dup sum, because if sum and left stay the same, there is only one
option to get the sum again, which is the same right as before.
* you underastimated this question, sketch it out first.

## biggest area of water
* these kinds of problems are usually solved with two pointers, when you need to figure out when to move each one.
* in this case, move the one that is pointing at the shorter wall.

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

## longest consecutive subsequence
* using a hash *set* (only keys). Putting in all the values. Going through the values, checking if it's the first number in a possible
consecutive sequence, if so, then start looking for all of the other numbers in the sequence and counting them. 
* because you check if it's the first element and only then you start iterating on a sequence, then it won't allow for counting a sequence
twice.

## Evaluate Reverse Polish Notation
* to solve with recursion go from right to left. In general for recursion, it's often easier to start from the end.

## generate paranthesis
* Using two helper argumetns for each paran type. 
* Add a conditional for adding a closing bracket.
* Use a shared string to prevent copying.

## divide two integers
* handle two edge cases of INT_MIN divided by 1 and -1.
* before doing the division, move to an unsigned int domain.

# algorthims
## quick sort 
* you stop when there are two elements.
* partition and then call recursivaly.

## partition
* pivot is the last element.
* two pointers i = -1, and j = 0.
* Repeat until j <= len - 2 (second to last element).
* increment j:
    * if arr[j] < pivot: 
        * increment i
            * swap arr[i] and arr[j]
* swap arr[i+1] and arr[len-1]

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

## Boyer - Moores voting algorithm
* You have a candidate and votes. When votes == 0, you set candidate = array[i] and increment votes. As soon as array[i] != candidate, you
decrement votes.
* This way you get rid of the numbers that are not majority numbers.
* if it's promissed that it exists, we don't even need a second pass.


# data structure basics
## heaps
* the first non leaf is at floor(n/2) - 1.

## linked lists
* having a parent pointer follow an iterator is very simply done with assigning the parent to the iterator, before moving the iterator.

## hash table
* a classic string hash function is a polynomial hash function.

## LPS array
* *TODO*

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
* to solve with recursion go from the end to the beginning, it's often eaiser. Like you would do DP, you start from the end and build backwards.


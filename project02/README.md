Project 02: lsort
===================

1. What is complexity of each of the sorting modes (ie. STL, QSORT, MERGE, QUICK)? For each method, briefly explain the best, average, and worst case complexities of the 
sorting mode in terms of Big-O notation.

(Big O complexities listed from best to worst)

STL: O(nlogn), O(nlogn), O(n^2)

QSORT: O(nlogn), O(nlogn), O(n^2)

MERGE: O(nlogn), O(nlogn), O(nlogn)

QUICK: O(nlogn), O(nlogn), O(n^2)

The STL and QSORT algorithms rely on the behind the scenes implementations of sorting algorithms for their complexity. The standard C++ 
implementations use quicksort which dictates their complexity. The Quicksort algorithm will almost always be O(nlogn). The only case when
quicksort will be worse than O(nlogn) is when an incredibly terrible pivot is chosen. The choosing of the pivot is crucial to the complexity of the algorithm. If the first value is chosen 
as the pivot (which it was in a lot of the examples I saw) then an already sorted list, or close to sorted list is an efficiency nightmare because the pivot is smaller
than most of the values. This means that the recursive call will have to sort close to (n-1) elements which is bad efficiency. In order to improve the likelihood of 
picking a good pivot, three random values should be chosen from the array and the middle value of these three should be the pivot. It helps avoid the problematic scenario
of simply picking the first value in the array and ensures that quicksort stays at its average complexity.

In Merge sort the division is trivial and the "conquer" (aka combine) is complicated. For the division merge sort splits the array of elements to be sorted
into two equal halves which are separately sorted. This leaves the "conquer" phase with two halves of a total array which are sorted separately. Merge sort then
creates a temporary array. In order to "conquer" it compares the first values of each half of the original array and places the smaller value first in temp array. 
It repeats this process of comparing the first values until temp array is filled at which point the entire thing is sorted and it is copied back to the original 
array. Due to the nature of the split function which repeatedly halves the input, the complexity becomes logn (since computer is in base 2 and the algorithm splits
input in half repeatedly). To bring everything back together in the conquer stage requires looking at all elements atleast once for the comparisons and this adds the
n complexity making it n * logn. 


This is a simple implementation of the Unix [sort] utility that works on
[singly-linked lists].

[sort]: http://man7.org/linux/man-pages/man1/sort.1.html
[singly-linked lists]: https://en.wikipedia.org/wiki/Linked_list#Singly_linked_lists

Project 04 - Key-Value Store II
===============================

1. Unordered: Insert - Worst: O(n)		Average: O(n)
   Unordered: Search - Worst: O(1)		Average: O(1)
   The difference in Worse and average complexity is due to the potential that multiple values be hashed to the same key in the unsorted_map. If this were to happen
   searching for the proper mapping location could take up to O(n). In the case of insertion the same is true because if a location is already occupied it could take 
   up to O(n) to find a new location (if chaining is not used in the hash implementation). There can also be rehashing once a table is past its load balance which 
   requires rehashing all values. This is the worst case, but in most cases insertion will require one easy hash to find a key and no rehashing.
   
   Chained: Insert - Worst: O(1)		Average: O(1)
   Chained: Search - Worst: O(n)	    Avarage: O(N/M) Where N = number of keys and M = number of addresses in array
   The average and worst case are different because in the worst case all the values will hash to the same array address and a list will
   form that is as long as all the entries. In this case searching and removing will in the worst case require traversing the entire linked
   list of all the values. Insert will not be affected since the values are simply added to the head of the linked list when they map to that 
   address. In the average case (which will be the case if a good hash function is used) the N number of values will map evenly across the number
   of memory address producing lists that are N/M in length.
   
   Open: Insert - Worst: O(n)		Average: 1/2(1 + 1/(1-alpha)) Where alpha is the load factor
   Open: Search - Worst: O(n)		Average: 1/2(1 + 1/(1-alpha)) Where alpha is the load factor
   The worst and average cases are differenct because in linear probing the more full the array gets the longer it will most likely 
   take to find an open slot for a value (unless they are all perfectly mapped to one place in the table through the hash function). 
   The average case shows that the more full the array becomes the worse the time complexity gets. The worst case is for times when
   the array is one away from being filled and the entire array is probed before finding an open slot. (At this point however it must
   be noted that the average time complexity equation will be so close to O(n) that it is essentially O(n). The avearage case equation
   accounts for the situation when worst case will occur). 
   
2. 

**Chart for UNSORTED, SORTED, BST, TREAP, & UNORDERED**


| Backend     | NITEMS    | PADLENGTH |Insert Time(s)| Search Time(s)|
|-------------|-----------|-----------|--------------|---------------|
|  UNSORTED   |  10       |    1      |  5.2231e-05  |  9.799e-06    |  
|  UNSORTED   |  100      |    1      |  0.000349541 |  0.000244527  |  
|  UNSORTED   |  1000     |    1      |  0.0211449   |  0.0202336    |  
|  UNSORTED   |  10000    |    1      |  2.14837     |  2.13223      |  
|  UNSORTED   |  100000   |    1      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  1000000  |    1      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  10000000 |    1      |  INFINITY    |  INFINITY     |
|   SORTED    |  10       |    1      |  5.1035e-05  |    1.0293e-05 |
|   SORTED    |  100      |    1      |  0.000468796 |   0.000368428 |
|   SORTED    |  1000     |    1      |  0.0308719   |     0.0295809 |
|   SORTED    |  10000    |    1      |  3.23089     |     3.12148   |
|   SORTED    |  100000   |    1      |  380.319     |    363.845    |
|   SORTED    |  1000000  |    1      |  INFINITY    |  INFINITY     |
|   SORTED    |  10000000 |    1      |  INFINITY    |  INFINITY     |
|     BST     |  10       |    1      |  4.8009e-05  |    9.834e-06  |
|     BST     |  100      |    1      |  0.000294721 |   0.000120452 |
|     BST     |  1000     |    1      |  0.00336944  |    0.0014883  |
|     BST     |  10000    |    1      |  0.0440093   |    0.0184816  |
|     BST     |  100000   |    1      |  0.501552    |    0.206969   |
|     BST     |  1000000  |    1      |  5.83301     |    2.41154    |
|   RBTREE    |  10       |    1      |  5.6872e-05  |  1.0656e-05   |  
|   RBTREE    |  100      |    1      |  0.00028397  |  0.000106768  |  
|   RBTREE    |  1000     |    1      |  0.0030801   |  0.0012842    |  
|   RBTREE    |  10000    |    1      |  0.0355368   |  0.014482     |  
|   RBTREE    |  100000   |    1      |  0.433192    |  0.188095     |  
|   RBTREE    |  1000000  |    1      |  4.60778     |  1.90998      |  
|   RBTREE    |  10000000 |    1      |  54.5552     |  21.9338      |  
|    TREAP    |  10       |    1      |  0.000155417 |  1.0785e-05   |  
|    TREAP    |  100      |    1      |  0.00104776  |  0.000142584  |
|    TREAP    |  1000     |    1      |  0.0109307   |  0.00230644   | 
|    TREAP    |  10000    |    1      |  0.136035    |  0.0369662    |  
|    TREAP    |  100000   |    1      |  1.44763     |  0.439591     |
|    TREAP    |  1000000  |    1      |  16.2047     |  5.26178      |  
|    TREAP    |  10000000 |    1      |  INFINITY    |  INFINITY     |
|  UNORDERED  |  10       |    1      |  4.2177e-05  |  1.9016e-05   |  
|  UNORDERED  |  100      |    1      |   0.00016344 |  0.00010013   |  
|  UNORDERED  |  1000     |    1      |  0.0012322   |  0.00096255   |  
|  UNORDERED  |  10000    |    1      |   0.01096    |  0.0095157    |  
|  UNORDERED  |  100000   |    1      |   0.11902    |    0.11583    |  
|  UNORDERED  |  1000000  |    1      |    1.4056    |    1.2679     |  
|  UNORDERED  |  10000000 |    1      |   18.264     |    13.225     | 

**Chart for OPEN & CHAINED**


| Backend     | NITEMS    | PADLENGTH |  LOADFACTOR |     Insert Time(s)     |     Search Time(s)     |
|-------------|-----------|-----------|-------------|------------------------|------------------------|
|  OPEN       |  10       |    1      |     0.5     |      2.4652e-05        |       8.512e-06        |
|  OPEN       |  10       |    1      |     0.6     |      2.0136e-05        |       7.591e-06        |
|  OPEN       |  10       |    1      |     0.7     |      1.9734e-05        |       7.813e-06        |
|  OPEN       |  10       |    1      |     0.8     |      2.0121e-05        |       8.012e-06        |
|  OPEN       |  10       |    1      |     0.9     |      2.0475e-05        |       7.826e-06        |
|  OPEN       |  10       |    1      |     1.0     |      2.096e-05         |       7.854e-06        |
|  OPEN       |  100      |    1      |     0.5     |      0.00011029        |       0.00012514       |
|  OPEN       |  100      |    1      |     0.6     |      0.00010801        |       0.00012486       |
|  OPEN       |  100      |    1      |     0.7     |      0.00011379        |       0.00013017       |
|  OPEN       |  100      |    1      |     0.8     |      0.00010824        |       0.00012612       |
|  OPEN       |  100      |    1      |     0.9     |      0.00014227        |       0.00013189       |
|  OPEN       |  100      |    1      |     1.0     |      0.00012645        |       0.00014506       |
|  OPEN       |  1000     |    1      |     0.5     |      0.00011029        |       0.00012514       |
|  OPEN       |  1000     |    1      |     0.6     |      0.0011269         |       0.0061919        |
|  OPEN       |  1000     |    1      |     0.7     |      0.0011499         |       0.0062174        |
|  OPEN       |  1000     |    1      |     0.8     |      0.0011926         |       0.0060323        | 
|  OPEN       |  1000     |    1      |     0.9     |      0.0011197         |       0.0061825        |
|  OPEN       |  1000     |    1      |     1.0     |      0.0017217         |       0.0082789        |
|  OPEN       |  10000    |    1      |     0.5     |      0.00011029        |       0.00012514       |
|  OPEN       |  10000    |    1      |     0.6     |      0.01251           |         1.4866         |
|  OPEN       |  10000    |    1      |     0.7     |      0.013201          |         1.4938         |
|  OPEN       |  10000    |    1      |     0.8     |      0.013409          |         1.4838         |
|  OPEN       |  10000    |    1      |     0.9     |      0.012511          |         1.4419         |
|  OPEN       |  10000    |    1      |     1.0     |      0.055512          |         1.983          |
|  OPEN       |  100000   |    1      |     0.5     |      0.12903           |          inf           |
|  OPEN       |  100000   |    1      |     0.6     |      0.12526           |          inf           |
|  OPEN       |  100000   |    1      |     0.7     |      0.12465           |          inf           |
|  OPEN       |  100000   |    1      |     0.8     |      0.12692           |          inf           |
|  OPEN       |  100000   |    1      |     0.9     |      0.12862           |          inf           |
|  OPEN       |  100000   |    1      |     1.0     |      1.5515            |          inf           |
|  OPEN       |  1000000  |    1      |     0.5     |      1.6885            |          inf           |
|  OPEN       |  1000000  |    1      |     0.6     |      1.7778            |          inf           |
|  OPEN       |  1000000  |    1      |     0.7     |      1.7141            |          inf           |
|  OPEN       |  1000000  |    1      |     0.8     |      1.7118            |          inf           |
|  OPEN       |  1000000  |    1      |     0.9     |      1.7222            |          inf           |
|  OPEN       |  1000000  |    1      |     1.0     |      41.016            |          inf           |
|  OPEN       |  1000000  |    1      |     0.5     |      23.192            |          inf           |
|  OPEN       |  10000000 |    1      |     0.6     |      23.046            |          inf           |
|  OPEN       |  10000000 |    1      |     0.7     |      22.463            |          inf           |
|  OPEN       |  10000000 |    1      |     0.8     |      23.794            |          inf           |
|  OPEN       |  10000000 |    1      |     0.9     |      22.859            |          inf           |
|  OPEN       |  10000000 |    1      |     1.0     |      inf               |          inf           |
|  CHAINED    |  10       |    1      |     0.5     |      5.2877e-05        |       9.006e-06        |
|  CHAINED    |  10       |    1      |     0.75    |      4.4616e-05        |       8.798e-06        |
|  CHAINED    |  10       |    1      |     1.0     |      4.2948e-05        |       8.687e-06        |
|  CHAINED    |  10       |    1      |     5.0     |      4.0634e-05        |       9.667e-06        |
|  CHAINED    |  10       |    1      |     10.0    |      3.4747e-05        |       9.2253e-05       |
|  CHAINED    |  10       |    1      |     100.0   |      0.00010195        |       9.79e-06         |
|  CHAINED    |  100      |    1      |     0.5     |      0.00021339        |       7.5022e-05       |
|  CHAINED    |  100      |    1      |     0.75    |      0.00022279        |       7.8977e-05       |
|  CHAINED    |  100      |    1      |     1.0     |      0.00022919        |       7.8865e-05       |
|  CHAINED    |  100      |    1      |     5.0     |      0.00028363        |       8.2394e-0        |
|  CHAINED    |  100      |    1      |     10.0    |      0.00028455        |       8.7234e-05       |
|  CHAINED    |  100      |    1      |     100.0   |      0.00020236        |       9.8398e-05       |
|  CHAINED    |  1000     |    1      |     0.5     |      0.0019231         |       0.00080638       |
|  CHAINED    |  1000     |    1      |     0.75    |      0.0017513         |       0.00074955       |
|  CHAINED    |  1000     |    1      |     1.0     |      0.0018749         |       0.0007849        |
|  CHAINED    |  1000     |    1      |     5.0     |      0.0023767         |       0.00078054       |
|  CHAINED    |  1000     |    1      |     10.0    |      0.0024848         |       0.00085531       |
|  CHAINED    |  1000     |    1      |     100.0   |      0.0034296         |       0.0010196        |
|  CHAINED    |  10000    |    1      |     0.5     |      0.024435          |       0.0077486        |
|  CHAINED    |  10000    |    1      |     0.75    |      0.023627          |       0.0079324        |
|  CHAINED    |  10000    |    1      |     1.0     |      0.023218          |       0.0085089        |
|  CHAINED    |  10000    |    1      |     5.0     |      0.022148          |       0.0085116        |
|  CHAINED    |  10000    |    1      |     10.0    |      0.023065          |       0.0088814        |
|  CHAINED    |  10000    |    1      |     100.0   |      0.032186          |       0.011194         |
|  CHAINED    |  100000   |    1      |     0.5     |      0.25861           |       0.097132         |
|  CHAINED    |  100000   |    1      |     0.75    |      0.25083           |       0.09229          |
|  CHAINED    |  100000   |    1      |     1.0     |      0.25396           |       0.099491         |
|  CHAINED    |  100000   |    1      |     5.0     |      0.34496           |       0.11             |
|  CHAINED    |  100000   |    1      |     10.0    |      0.35832           |       0.11736          |
|  CHAINED    |  100000   |    1      |     100.0   |      0.35207           |       0.14009          |
|  CHAINED    |  1000000  |    1      |     0.5     |      2.6091            |       1.013            |
|  CHAINED    |  1000000  |    1      |     0.75    |      2.6255            |       1.0209           |
|  CHAINED    |  1000000  |    1      |     1.0     |      2.7145            |       1.1278           |
|  CHAINED    |  1000000  |    1      |     5.0     |      4.0022            |       1.4699           |
|  CHAINED    |  1000000  |    1      |     10.0    |      4.1162            |       1.4994           |
|  CHAINED    |  1000000  |    1      |     100.0   |      5.8245            |       2.0267           |
|  CHAINED    |  10000000 |    1      |     0.5     |      40.318            |       12.619           |
|  CHAINED    |  10000000 |    1      |     0.75    |      37.516            |       11.713           |
|  CHAINED    |  10000000 |    1      |     1.0     |      39.368            |       12.311           |
|  CHAINED    |  10000000 |    1      |     5.0     |      38.766            |       15.481           |
|  CHAINED    |  10000000 |    1      |     10.0    |      45.023            |       inf              |
|  CHAINED    |  10000000 |    1      |     100.0   |      inf               |       inf              |

3. Frequencies
books used: War and Peace, Metamorphosis, and Don Quixote

| Backend     | Text                  | File Size | Elasped Time  |     Memory      |
|-------------|-----------------------|-----------|---------------|-----------------|                 
| SORTED	  | warandpeace.txt		  | 3.2M	  | 5:38.21       | 3.941406 Mbytes |
| UNSORTED	  | warandpeace.txt 	  | 3.2M      | 1:03.94		  | 3.941406 Mbytes |
| BST		  | warandpeace.txt 	  | 3.2M	  | 0:01.96		  | 4.671875 Mbytes |
| RBTREE 	  | warandpeace.txt       | 3.2M      | 0:01.90       | 5.039062 Mbytes | 
| TREAP       | warandpeace.txt       | 3.2M      | 0:03.28       | 4.687500 Mbytes |
| UNORDERED	  | warandpeace.txt 	  | 3.2M	  | 0:09.49       | 4.925781 Mbytes |
| CHAINED	  | warandpeace.txt       | 3.2M      | 0:00.57       | 23.07031 Mbytes |
| OPEN        | warandpeace.txt       | 3.2M      | 1:29.50       | 8.851562 Mbytes |
|-------------|-----------------------|-----------|---------------|-----------------|
| SORTED	  | Metamorphosis.txt	  | 139K	  | 0:02.41       | 1.742188 Mbytes |
| UNSORTED	  | Metamorphosis.txt	  | 139K      | 0:00.78		  | 1.742188 Mbytes |
| BST		  | Metamorphosis.txt	  | 139K	  | 0:00.09		  | 1.882812 Mbytes |
| RBTREE 	  | Metamorphosis.txt	  | 139K      | 0:00.08       | 1.957031 Mbytes |
| TREAP       | Metamorphosis.txt	  | 139K      | 0:00.15       | 1.902344 Mbytes |
| UNORDERED   | Metamorphosis.txt	  | 139K	  | 0:00.41       | 1.968750 Mbytes |
| CHAINED 	  | Metamorphosis.txt	  | 139K      | 0:00.08       | 4.179688 Mbytes |
| OPEN        | Metamorphosis.txt	  | 139K      | 0:02:40       | 2.257812 Mbytes |
|-------------|-----------------------|-----------|---------------|-----------------|
| SORTED	  | DonQuixote.txt	      | 2.1M	  | 4:32.58       | 5.468750 Mbytes |
| UNSORTED	  | DonQuixote.txt	      | 2.1M      | 1:01.20		  | 5.468750 Mbytes |
| BST		  | DonQuixote.txt	      | 2.1M	  | 0:01.39		  | 5.996094 Mbytes |
| RBTREE 	  | DonQuixote.txt	      | 2.1M      | 0:01.40       | 6.507812 Mbytes |
| TREAP       | DonQuixote.txt	      | 2.1M      | 0:02.46       | 6.011719 Mbytes |
| UNORDERED	  | DonQuixote.txt   	  | 2.1M	  | 0:09.64       | 6.488281 Mbytes |
| CHAINED	  | DonQuixote.txt        | 2.1M      | 0:01.09       | 42.62500 Mbytes |
| OPEN        | DonQuixote.txt   	  | 2.1M      | 4:27.86       | 15.50000 Mbytes |
|-------------|-----------------------|-----------|---------------|-----------------|

4. Out of the new backend implementations chained and unordered consistently performed better than open. Although open works at the beginning of 
an input, it progressively gets worse moving towards O(n) with every additional entry. This was especially evident when performing the frequency 
tests. Chained outperformed unordered every time, but both chained and unordered were significantly faster than open. The File Sizes in the frequencies
test greatly impacted the runtime. The jump from 139K to the larger megabyte files showed an extreme slow down in runtime for all three backends. The open
backend performed similarly to sorted and got much worse with increased file size. 

Increasing NITEMS showed a linear increase for unordered. Multiplying NITEMS by 10 resulted in an output time that was greater by a factor of 10. The same
was true for open and chained when looking at tests of the same load factor and different NITEMS. Having a low load factor was important for open hashing because
it helped prevent scenarios when the array was nearly full and insertion took forever to find an open bucket. The load factor had less effect on chained since 
insertion was simply done in the linked list of the bucked the value was mapped to. But having a lower load factor helped search because it prevented extremely 
long lists.

If I were to choose a backend to implement I would definitely NOT choose open. It's runtime becomes far too poor for large inputs and it does extremely poorly
as soon as the array nears being full. I would choose chained. Even though the search time sometimes suffers if too many values are in a bucket, it is by far the 
fastest for insertion. Since the map could be very useful for processing large files it is crucial to have easy insertion and the linked list style insertion provides
the best performance. 

Contributions: Brittany did unordered, 1 and 4 of the README, Maggie did open, Collin did chained, and everyone ran tests
on their own backend for questions 2 and 3. 

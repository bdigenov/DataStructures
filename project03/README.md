Project 03 - Key-Value Store I
==============================

NOTE: Shreya gave an extension to turn this in by Friday November 4th

**1.** What is complexity of each of the map backends (ie. Unsorted, Sorted, BST, RBTree, Treap)? For each implementation, briefly explain the best, average, and worst case complexities of inserting and searching using the particular method in terms of Big-O notation.

**Unsorted:** 
Insert- W: 1 A: 1 B: 1 (These are all one because unsorted you can insert wherever you want) 
Search- W: n (if value is last one in unsorted array and all values are checked) A: n B: 1 (if the first value you search is the one you're looking for)

**Sorted:** 
Insert- W: n (if you have to iterate through all of the numbers to find the correct place) A: 1 B: 1 (if the first place you find is the correct place)
Search- W: n A: 1 B: 1 (for the same reaosns as above)

**BST:** 
Insert- W: n (if inserted in ascending order and linked list is created with no balance) A: logn (Average we assume tree is decently balanced for BST) B: logn (perfectly balanced tree)
Search- W: n (same reason as above) A: logn (because it is assumed the tree will be fairly balanced) 
B: logn (for perfectly balanced tree)

**RBTree:**
Insert- W: logn A: logn B: logn (Same reasons as above)
Search- W: logn A: logn B: logn (Same reasons as above)

Treap:
Insert- W: n (if tree for some reason balances horribly based on priority and all values are placed in ascending order) A: logn (most likely tree will balance fairly evenly) B: logn (perfectly balanced tree)
Search- W: n A: logn B: logn
(For same reasons as treap insert)

**2.** Benchmarks for all 5 Backends when NITEMS is 10, 100, 1000, 10000, 100000, 1000000, 10000000 and PADLENGTH is 1, 2, 4, 8.

| Backend     | NITEMS    | PADLENGTH | Insert Time  | Search Time   |
|-------------|-----------|-----------|--------------|---------------|
|  UNSORTED   |  10       |    1      |  5.2231e-05  |  9.799e-06    |  
|  UNSORTED   |  10       |    2      |  4.6397e-05  |  9.74e-06     |  
|  UNSORTED   |  10       |    4      |  4.9489e-05  |  1.1105e-05   |  
|  UNSORTED   |  10       |    8      |  5.1345e-05  |  1.2569e-05   |  
|  UNSORTED   |  100      |    1      |  0.000349541 |  0.000244527  |  
|  UNSORTED   |  100      |    2      |  0.000379679 |  0.000260141  |  
|  UNSORTED   |  100      |    4      |  0.000396906 |  0.000271543  |  
|  UNSORTED   |  100      |    8      |  0.000438725 |  0.000297553  |  
|  UNSORTED   |  1000     |    1      |  0.0211449   |  0.0202336    |  
|  UNSORTED   |  1000     |    2      |  0.0217202   |  0.0198577    |  
|  UNSORTED   |  1000     |    4      |  0.0217048   |  0.0203166    |  
|  UNSORTED   |  1000     |    8      |  0.0227868   |  0.0218183    |  
|  UNSORTED   |  10000    |    1      |  2.14837     |  2.13223      |  
|  UNSORTED   |  10000    |    2      |  2.16879     |  2.16314      |  
|  UNSORTED   |  10000    |    4      |  2.29258     |  2.27675      |  
|  UNSORTED   |  10000    |    8      |  2.1747      |  2.17542      | 
|  UNSORTED   |  100000   |    1      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  100000   |    2      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  100000   |    4      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  100000   |    8      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  1000000  |    1      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  1000000  |    2      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  1000000  |    4      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  1000000  |    8      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  10000000 |    1      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  10000000 |    2      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  10000000 |    4      |  INFINITY    |  INFINITY     |
|  UNSORTED   |  10000000 |    8      |  INFINITY    |  INFINITY     |

 |   SORTED    |  10       |    1      |  5.1035e-05   |    1.0293e-05 |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  10       |    2      |  4.6461e-05   |    1.1578e-05 |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  10       |    4      |  4.9408e-05   |    1.3329e-05 |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  10       |    8      |  5.2319e-05   |    1.4375e-05 |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  100      |    1      |  0.000468796  |   0.000368428 |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  100      |    2      |  0.000502756  |   0.000376201 |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  100      |    4      |  0.000516278  |   0.000374841 |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  100      |    8      |  0.000546638  |   0.000392269 |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  1000     |    1      |  0.0308719    |     0.0295809 |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  1000     |    2      |  0.030598     |     0.0296858 |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  1000     |    4      |  0.0314505    |     0.0305297 |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  1000     |    8      |  0.0322193    |    0.0306813  |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  10000    |    1      |  3.23089      |     3.12148   |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  10000    |    2      |  3.15938      |    3.15931    |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  10000    |    4      |  3.13243      |    3.13749    |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  10000    |    8      |  3.13989      |    3.11758    |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  100000   |    1      |  380.319      |    363.845    |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  100000   |    2      |  334.642      |    327.571    |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  100000   |    4      |  330.972      |    329.632    |
 |-------------|-----------|-----------|---------------|---------------|
 |   SORTED    |  100000   |    8      |  352.851      |     339.969   |
 |-------------|-----------|-----------|---------------|---------------|
 | Backend     | NITEMS    | PADLENGTH | Insert Time   | Search Time   |
 | SORTED      | ALL NITEMS PAST THIS POINT HAD TIMES OF INFINITY      |
 
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  10       |    1      |  4.8009e-05   |    9.834e-06  |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  10       |    2      |  4.4512e-05   |    1.0715e-05 |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  10       |    4      |  4.8473e-05   |    1.1844e-05 |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  10       |    8      |  4.9615e-05   |    1.3023e-05 |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  100      |    1      |  0.000294721  |   0.000120452 |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  100      |    2      |  0.000301534  |   0.000131227 |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  100      |    4      |  0.000327875  |   0.000137269 |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  100      |    8      |  0.000371498  |   0.000150392 |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  1000     |    1      |  0.00336944   |    0.0014883  |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  1000     |    2      |  0.00358238   |    0.00158019 |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  1000     |    4      |  0.00383225   |    0.00170145 |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  1000     |    8      |  0.00414502   |    0.00181303 |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  10000    |    1      |  0.0440093    |    0.0184816  |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  10000    |    2      |  0.0437632    |    0.0186393  |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  10000    |    4      |  0.0458503    |    0.0200428  |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  10000    |    8      |  0.0499675    |    0.021314   |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  100000   |    1      |  0.501552     |    0.206969   |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  100000   |    2      |  0.51417      |    0.219661   |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  100000   |    4      |  0.540232     |    0.229044   |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  100000   |    8      |  0.600995     |    0.263022   |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  1000000  |    1      |  5.83301      |    2.41154    |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  1000000  |    2      |  5.95735      |    2.13433    |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  1000000  |    4      |  6.26748      |    2.71434    |
 |-------------|-----------|-----------|---------------|---------------|
 |     BST     |  1000000  |    8      |  6.77658      |    2.87995    |

|   RBTREE    |  10       |    1      |  5.6872e-05  |  1.0656e-05   |  
|   RBTREE    |  10       |    2      |  6.833e-05   |  1.1222e-05   |  
|   RBTREE    |  10       |    4      |  6.1642e-05  |  1.2338e-05   |  
|   RBTREE    |  10       |    8      |  6.4992e-05  |  1.4828e-05   |  
|   RBTREE    |  100      |    1      |  0.00028397  |  0.000106768  |  
|   RBTREE    |  100      |    2      |  0.000290243 |  0.000115557  |  
|   RBTREE    |  100      |    4      |  0.000327511 |  0.000130454  |  
|   RBTREE    |  100      |    8      |  0.000350837 |  0.000141777  |  
|   RBTREE    |  1000     |    1      |  0.0030801   |  0.0012842    |  
|   RBTREE    |  1000     |    2      |  0.00320053  |  0.00132107   |  
|   RBTREE    |  1000     |    4      |  0.00340084  |  0.00146958   |  
|   RBTREE    |  1000     |    8      |  0.0037431   |  0.00158008   |  
|   RBTREE    |  10000    |    1      |  0.0355368   |  0.014482     |  
|   RBTREE    |  10000    |    2      |  0.0371674   |  0.0157514    |  
|   RBTREE    |  10000    |    4      |  0.0414962   |  0.0175029    |  
|   RBTREE    |  10000    |    8      |  0.0435627   |  0.0186216    |  
|   RBTREE    |  100000   |    1      |  0.433192    |  0.188095     |  
|   RBTREE    |  100000   |    2      |  0.433621    |  0.191566     |  
|   RBTREE    |  100000   |    4      |  0.481096    |  0.211112     |  
|   RBTREE    |  100000   |    8      |  0.501173    |  0.225313     |  
|   RBTREE    |  1000000  |    1      |  4.60778     |  1.90998      |  
|   RBTREE    |  1000000  |    2      |  5.16452     |  2.18649      |  
|   RBTREE    |  1000000  |    4      |  5.2311      |  2.22976      |  
|   RBTREE    |  1000000  |    8      |  5.74829     |  2.48008      |  
|   RBTREE    |  10000000 |    1      |  54.5552     |  21.9338      |  
|   RBTREE    |  10000000 |    2      |  54.5541     |  21.796       |
|   RBTREE    |  10000000 |    4      |  58.2177     |  24.1443      |
|   RBTREE    |  10000000 |    8      |  58.6901     |  24.8803      |

|    TREAP    |  10       |    1      |  0.000155417 |  1.0785e-05   |  
|    TREAP    |  10       |    2      |  0.000141045 |  1.1341e-05   |  
|    TREAP    |  10       |    4      |  0.000142296 |  1.2581e-05   |  
|    TREAP    |  10       |    8      |  0.000148911 |  1.502e-05    |  
|    TREAP    |  100      |    1      |  0.00104776  |  0.000142584  |  
|    TREAP    |  100      |    2      |  0.00103594  |  0.000149618  |  
|    TREAP    |  100      |    4      |  0.00105012  |  0.000169336  |  
|    TREAP    |  100      |    8      |  0.0010984   |  0.000192494  |  
|    TREAP    |  1000     |    1      |  0.0109307   |  0.00230644   |  
|    TREAP    |  1000     |    2      |  0.0108622   |  0.00222559   |  
|    TREAP    |  1000     |    4      |  0.0118054   |  0.00259448   |  
|    TREAP    |  1000     |    8      |  0.0115207   |  0.00245784   |  
|    TREAP    |  10000    |    1      |  0.136035    |  0.0369662    |  
|    TREAP    |  10000    |    2      |  0.128772    |  0.0331748    |  
|    TREAP    |  10000    |    4      |  0.140954    |  0.0441821    |  
|    TREAP    |  10000    |    8      |  0.140441    |  0.041394     |  
|    TREAP    |  100000   |    1      |  1.44763     |  0.439591     |  
|    TREAP    |  100000   |    2      |  1.43712     |  0.412791     |  
|    TREAP    |  100000   |    4      |  1.49784     |  0.462585     |  
|    TREAP    |  100000   |    8      |  1.51726     |  0.487571     |  
|    TREAP    |  1000000  |    1      |  16.2047     |  5.26178      |  
|    TREAP    |  1000000  |    2      |  17.0413     |  5.78442      |  
|    TREAP    |  1000000  |    4      |  16.3149     |  5.37476      |  
|    TREAP    |  1000000  |    8      |  21.5126     |  7.98529      |
|    TREAP    |  10000000 |    1      |  INFINITY    |  INFINITY     |  
|    TREAP    |  10000000 |    2      |  INFINITY    |  INFINITY     |  
|    TREAP    |  10000000 |    4      |  INFINITY    |  INFINITY     |  
|    TREAP    |  10000000 |    8      |  INFINITY    |  INFINITY     |



**3.** Frequencies
books used: War and Peace, Metamorphosis, and Don Quixote

| Backend     | Text                  | File Size | Elasped Time  |
|-------------|-----------------------|-----------|---------------|
| SORTED	  | warandpeace.txt		  | 3.2M	  | 5:38.21       |
| UNSORTED	  | warandpeace.txt 	  | 3.2M      | 1:03.94		  |
| BST		  | warandpeace.txt 	  | 3.2M	  | 0:01.96		  |
| RBTREE 	  | warandpeace.txt       | 3.2M      | 0:01.90       |
| TREAP       | warandpeace.txt       | 3.2M      | 0:03.28       |
|-------------|-----------------------|-----------|---------------|
| SORTED	  | Metamorphosis.txt	  | 139K	  | 0:02.41       |
| UNSORTED	  | Metamorphosis.txt	  | 139K      | 0:00.78		  |
| BST		  | Metamorphosis.txt	  | 139K	  | 0:00.09		  |
| RBTREE 	  | Metamorphosis.txt	  | 139K      | 0:00.08       |
| TREAP       | Metamorphosis.txt	  | 139K      | 0:00.15       |
|-------------|-----------------------|-----------|---------------|
| SORTED	  | DonQuixote.txt	      | 2.1M	  | 4:32.58       |
| UNSORTED	  | DonQuixote.txt	      | 2.1M      | 1:01.20		  |
| BST		  | DonQuixote.txt	      | 2.1M	  | 0:01.39		  |
| RBTREE 	  | DonQuixote.txt	      | 2.1M      | 0:01.40       |
| TREAP       | DonQuixote.txt	      | 2.1M      | 0:02.46       |
|-------------|-----------------------|-----------|---------------|

**4**. After you have performed your benchmarks: (1) Discuss the relative performance of each map implementation and try to explain the differences, (2) What effect did NITEMS, PADLENGTH, and File Size have on the performance of each backend in your experiments?, (3) In your opinion, which map backend is the best? Justify your conclusion by examining the trade-offs for the chosen backend and based on your experimental results.  (4) In addition to the questions, please provide a brief summary of each individual group members contributions to the project.

The map implementation that was the best at performing was the RB tree.  This could perhaps be because is uses the C++ container map, which is implemented as an RB tree and is self balancing.  The worst case for rb trees is the same as the average case, which could be why it generally performed fairly well.  The worst ones at performing were unsorted, sorted and bst.  Unsorted couldn't handle the input once NITEMS reached 100000.  This is also apparent in the file size results of the sorted implementation on the file sizes:  as the file size got bigger, the elapsed time was significantly longer and the sorted algorithm took the longest out of everything.  Whereas, with rb tree, it stayed relatively the same despite file size.  Additionally, the binary search tree algorithms for each file size in frequencies was fairly comparable.  

In our opinion, the red black tree map end is the best.  The tradeoffs for that back end include each node has the extra bit that indicates its color, which could potentially take up too much memory if there is a lot of data.  The RBTREEE, however, was the fastest of the frequencies test and was the only map_bench test to not eventually time out as infinity.  So when deciding on an algorithm, we believe RBTREE is the most effective because of its speed and despite its memory usage issues.

Regarding group contributions, Maggie worked on unsorted, sorted and red black tree.  Collin debugged and finished sorted, did bst, and wrote frequencies.  Brittany did treap and wrote map_bench.  We all worked on the README.md.  



























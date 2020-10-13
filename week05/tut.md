Question 1
===========
(Splay trees)
Show how a splay tree would be constructed if the following values were inserted into an initially empty tree in the order given:

Search time: O(n)
Insertion Time: O(n)

5  3  8  7  4

Algorithm Pseudocode from Lectures:
```c
insertSplay(tree,item):
|  Input  tree, item
|  Output tree with item splay-inserted
|
|  if tree is empty then return new node containing item
|  else if item=data(tree) then return tree
|  else if item < data(tree) then
|  |  if left(tree) is empty then
|  |     left(tree) = new node containing item
|  |  else if item < data(left(tree)) then
|  |        // Case 1: left-child of left-child
|  |     tll = insertSplay(tll),item)
|  |     tree = rotateRight(tree)
|  |  else  // Case 2: right-child of left-child
|  |     tlr = insertSplay(tlr,item)
|  |     left(tree) = rotateLeft(left(tree))
|  |  end if
|  |  return rotateRight(tree)
|  else if item > data(tree) then
|  |  if right(tree) is empty then
|  |     right(tree) = new node containing item
|  |  else if item < data(right(tree)) then
|  |        // Case 3: left-child of right-child
|  |     trl = insertSplay(trl,item)
|  |     right(tree) = rotateRight(right(tree))
|  |  else  // Case 4: right-child of right-child
|  |     trr = insertSplay(trr,item)
|  |     tree = rotateLeft(tree)
|  |  end if
|  |  return rotateLeft(tree)
|  end if
```

InsertSplay(t,5)
```
    5
```

InsertSplay(t,3)
```
    3
     \
      5
```
Maintain a stack of rotations operations with direction opposite to the traversed tree direction.

InsertSplay(t,8)
```
    8
   /
   3
    \
     5
```

InsertSplay(t,7)
```
    7
   / \
   3  8
   \
    5

```

InsertSplay(t,4)
```
    4
   / \
   3  7 
      / \
     5   8
```

Let t be your answer to part (a), and consider the following sequence of operations:

SearchSplay(t, 7);
```
    4
   / \
   3  7 
      / \
     5   8
Becomes:
    7
   / \
   4  8 
  / \  
 3   5   

```
SearchSplay(t, 8);
```
    4
   / \
   3  7 
      / \
     5   8
Becomes:
    8
   /
   4  
  / \
  3  7   
     /
    5

```
SearchSplay(t, 6);

When searched value is not in the tree, rotate closest value to the top
```
    4
   / \
   3  7 
      / \
     5   8

    5
   / \
   4  7 
  /     \
 3       8
```

Question 2
===========
(AVL trees)

Show how an AVL tree would be constructed if the following values were inserted into an initially empty tree in the order given:

12  10  8  6  4  2

Search time: O(logn)
Insertion Time: O(logn)

AVL Insertion Algorithm
```c
insertAVL(tree,item):
|  Input  tree, item
|  Output tree with item AVL-inserted
|
|  if tree is empty then
|     return new node containing item
|  else if item = data(tree) then
|     return tree
|  else
|  |  if item < data(tree) then
|  |     left(tree) = insertAVL(left(tree),item)
|  |  else if item > data(tree) then
|  |     right(tree) = insertAVL(right(tree),item)
|  |  end if
|  |  LHeight = height(left(tree))
|  |  RHeight = height(right(tree))
|  |  if (LHeight - RHeight) > 1 then
|  |     if item > data(left(tree)) then
|  |        left(tree) = rotateLeft(left(tree))
|  |     end if
|  |     tree=rotateRight(tree)
|  |  else if (RHeight - LHeight) > 1 then
|  |     if item < data(right(tree)) then
|  |        right(tree) = rotateRight(right(tree))
|  |     end if
|  |     tree=rotateLeft(tree)
|  |  end if
|  |  return tree
|  end if
```
Cases:
AVL Insertion:
1. Insert at the leaf
2. Look at grandparent node (2 roots up from current) and check if it is height balanced. If not, perform following rotations

LL: perform single right rotation
```
    G
   / \
  P   t_1
 / \
C  t_2
```

LR: perform left rotation -> right rotation
RL: perform right rotation -> left rotation
RR: perform left rotation

(LL) means that the child is accessible by saying grandparent->left->left, same for R meaning right.


Question Answers

InsertAVL(12)
```
12
```

InsertAVL(10)
```
   12
  /
 10
```

InsertAVL(8)
```
    12
   /
  10
 /
8
Becomes:

        10
        / \
       8  12
    
```

InsertAVL(6)
```
        10
        / \
       8  12
      /
     6
```

InsertAVL(4)
```
        10
        / \
       6  12
      / \
     4   8

```

InsertAVL(2)
```
         6
        / \
       4  10
      /  /  \
     2   8  12
```

LR Case (Insert 5)
```
        10
        / \
       6  12
      / 
     4
      \
       5  
Becomes:
        10
        / \
       5  12
      / \
     4   6
```

Question 3
===========
(2-3-4 trees)

Show how a 2-3-4 tree would be constructed if the following values were inserted into an initially empty tree in the order given:

2-3-4 Tree Nodes:

2 Node: 1 Value, 2 subtrees
3 Node: 2 values, 3 subtrees s1 < v1, v1 < s2 < v2, s3 > v2
4 Node: 3 values, 4 subtrees s1 < v1, v1 < s2 < v2, v2 < s3 < v3, s4 > v3

1  2  3  4  5  8  6  7  9  10
Tree after values are inserted:
```


                           +-----+
                           |  4  +-----+
                     +-----+     |      \
                    /      +-----+       \
                   /                      \
                  /                  +-----+------+
              +--+--+                |     |      |
              |     |                |  6  |   8  |
              |  2  |             +--+     |      |
              |     |            /   +-----+------+
           +--+-----+          +/          |       \
          /         +          /           +        +-----+------+
         /           \      +-+--+     +--+-+       |     |      |
     +--+--+      +---+--+  | 5  |     | 7  |       |  9  |  10  |
     |     |      |      |  |    |     |    |       |     |      |
     |  1  |      |  3   |  +----+     +----+       +-----+------+
     |     |      |      |
     +-----+      +------+


```

Once you have built the tree, count the number of comparisons needed to search for each of the following values in the tree:

1  7  9  13

```
1: three comparisons (4, 2, 1)
7: four comparisons (4, 6, 8, 7)
9: four comparisons (4, 6, 8, 9)
13: Five comparisons (4, 6, 8, 9, 10)

```

Question 4
===========
Splay tree search moves the found node (or a near neighbour) to the root. AVL trees do not do this. What are the advantages/disadvantages of each strategy?

Splay Tree disadvantages:
- Time complexity:
  - Search O(n)
    - Insertion O(n)
    - When it is a degenerate tree
- Splay tree is not necessarily balanced

Splay Tree advantages:
- Low search/insertion cost when search terms are highly correlated.
- Example:
    - Search for 4 - 5 - 6 in a splay tree 4 will be moved to top, 5 and 6 are close to 4 in the tree, so will not need a lot of operations to search for it.
- Splay operations can be applied to any existing tree (even non-splay trees).

Example real world:
    Search engine:
        Search terms are correlated, so it is a good fit for a splay tree.
        

AVL Trees advantages:
    Always balanced:
    Time complexity:
        O(logn) search and insert always

AVL Trees disadvantages:
    O(logn) search and insert ALWAYS
    AVL operations only work on AVL trees, non AVL trees must be converted to AVL trees.

Example real world:
    Databases: 
        - Actually use Red-Black Trees, but same principle applies
        - Large amounts of data that we want to search through in some kind of order. Not correlated.
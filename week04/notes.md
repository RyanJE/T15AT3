3.

Rotations:
Root Node: root
Children: l, r
Left rotations:

1. Keep track of r->left, called tmp
2. r->left becomes root
3. root->right becomes tmp
4. r becomes the new root

Visually:
```
	root                                                          r
       /   \                                                        /  \
      l     r         Perform left rotation on root ------>       root  r_right
           /  \						    /  \
      r_left r_right                                             l   r_left
```
Right rotations:

1. Keep track of l->right, called tmp
2. l->right becomes root
3. root->left becomes tmp
4. l becomes the new root

Visually:
```
	root                                                          l
       /   \                                                        /  \
      l     r         Perform right rotation on root ------>     l_left root
     /  \						                  /  \
 l_left l_right                                                    l_right  r
```


4.

AVL:

Perfectly balanced tree:
- Takes in an AVL tree
- ALL operations have O(logn) complexity for best and worst case
- In certain cases can be less efficient to insert nodes into tree than other trees as the rebalance operation needs to be performed each time.


AVL Insertion:
1. Insert at the leaf
2. Look at grandparent node (2 roots up from current) and check if it is height balanced. If not, perform following rotations

LL: perform single right rotation
LR: perform left rotation -> right rotation
RL: perform right rotation -> left rotation
RR: perform left rotation

(LL) means that the child is accessible by saying grandparent->left->left, same for R meaning right.

3. Move up one grandparent or end if on root
```

            8
        /       \
        3        9
      /   \
    2      5
```
       

Splay:

Most recently accessed node should always be the root
Insertion operation:
    - Newest node always rotated to top of tree.
Search Operation:
    - Node that you search or closest node must always rotated to top of tree.

Worst cases:
search for the smallest value in tree followed by largest
non-correlated data, or anti-correlated data
- Do not use splay trees when search patterns are random or anti-correlated, example:
	search 1 -> search 100000000 -> search -100000000000 -> etc.

Best cases:
- When you have highly correlated search patterns
- Clumped data: search 1 -> search 2 etc.

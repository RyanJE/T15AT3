Week 10
=========

Q1.

a. Since a key can be any number in an unsigned int, the best way to denote a noItem value is to reserve a particular number (i.e. 0). So if an item hashes to 0, we hardcode a case where any hash == 0 is instead == 1.
b. Reserve an integer as per part a. Choose a number that we know wont be a key (from a hardcoded case or otherwise) and choose that as our NoItem value.

c. Since strings are pointers to char (char*), denote a NoItem value as NULL.

Q2.

Worst Case:

Link list of length 2N
Example hash function: Hash(x) = 0

Structure: Single linked list of size 2N at key 0, empty chains elsewhere.

Best Case:

Hashes are evenly distributed amongst keys. Therefore every key will be associated with a chain (list) of length 2.

Average searching in best case hash table:

Steps:
1. Hash the value, get back a key
2. Access the hash table at the index given by the key
3. Compare first value in chain to our search value
4. If equal, end algorithm else continue on
5. Compare second value in chain to our search value
6. If Equal, end, else end

average is 1 + 2 / 2 = 1.5

Q3.

a. Separate Chaining
h(x) = x%11 

         35
 ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^
 |   |   |   |   |   |   |   |   |   |   |
 22      24          27
 ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^
 |   |   |   |   |   |   |   |   |   |   |
 11  N   13  N   15  16  N   29  19   20  N
 ^   ^   ^   ^   ^   ^   ^   ^   ^   ^   ^
 |   |   |   |   |   |   |   |   |   |   |
[0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10]

b. linear probing
NoItem value is 0

[11|22|35|24|15|16|27|29|19|20|13]
[0|1|2|3|4|5|6|7|8|9|10]


c. double hashing
Linear hashing except we increment our probe by h_2(x) = (x%3) + 1, by y

[11|22|35|24|15|16|27|29|19|20|13]
[0|1|2|3|4|5|6|7|8|9|10]


Q4.
h(x) = x%10
[0|1|2|3|4|5|6|7|8|0]

[20|10|7|3|14|15|6|17|33|5]

Q5.

```c
int hash(char *key, int N)
{
	int h = 0;
	char *c;
	for (c = key; *c != '\0'; c++)
		h = h + *c;
	return h % N;
}
```
This hash function is deriving an integer value associated with a string by sums up all ascii value of characters then key is (sum)%N

Q6.
S  O  R  T  I  I  S 
83 79 82 84 73 73 83



Q7.
Skipped


Q8.

Process for deleting:

1. Delete the root note, then make the bottom most right node the new root.
2. Compare the root node against the largest of the two child nodes. 
3. If root node is greater than the greatest child then end algo, we have a heap.
Else swap the two greatest and new root, recursively perform step 2 onwards on the new child.

        5
    /      \
    4      4
   / 
  3   

```
Heap h;
Item it;
h = newHeap(10);

insert(h, 10);
insert(h,  5);
insert(h, 15);
insert(h , 3);
insert(h, 16);
insert(h, 13);
insert(h,  6);
it = delete(h);

insert(h,  2);
it = delete(h);

it = delete(h);
it = delete(h);
it = delete(h);
it = delete(h);
```

Converting between tree and array
1. Create an array of length treeNumNodes(tree) + 1
2. At root node, assign array[1] = value(root)
3. set i = 1
4. While we havent explored the tree:
    array[2*i] = value(root->left)
    array[2*i + 1] = value(root->right)

    recursively call function with i = 2*i
    recursively call function with i = 2*i + 1

Children of 2i are 2(2i), 2(2i) + 1

        10
     /      \
    5       6
   / \
  1  2

[0, 10, 5, 6, 1, 2]
     
Q9.

Trie insertion algorithm.
1. Start at the beginning of the string to insert, and the root of the trie.
2. If the first letter is not in the trie, add the first letter as a node and every subsequent letter as a sequence of nodes. Mark the final letter node.
3. Continue through each letter until we reach the end of the string. 
4. Whatever the node corresponding to the last letter is, mark it as an end node.

Q10.

Add a substring of a word that already exists in the trie.
example for the tute trie.

Q11.

This question uses the same trie algorithm to insert each of the words into the trie.

Q12.

Case 1:
    The end of the deleted string has children:
        unmark the end node of the deleted string

Case 2:
    The end of the deleted string has no children:
        Delete every node and traverse up to the parent until we reach a node that has at least onesubtree (other than the deleted one) and/or is a marked node.
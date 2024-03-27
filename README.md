# Binary Trees

### What is a binary tree?

- A binary tree is a hierarchical data structure consisting of nodes where each node has at most two children, referred to as the left child and the right child.
- Nodes in a binary tree are connected by edges, with one node being designated as the root of the tree.
Each node in a binary tree can have either zero, one, or two children.

### Difference between a binary tree and a Binary Search Tree (BST):

- A binary tree is a general tree structure where nodes can be arranged in any order.
- A Binary Search Tree (BST) is a specific type of binary tree where the values of nodes in the left subtree are less than or equal to the value of the parent node, and the values of nodes in the right subtree are greater than the value of the parent node.
- In a BST, this property holds true for every node in the tree, making it efficient for searching, insertion, and deletion operations.

### Possible gain in terms of time complexity compared to linked lists:

- Binary trees can offer significant improvements in time complexity compared to linked lists for certain operations, such as searching, insertion, and deletion.
- For example, in a balanced binary search tree, the time complexity for these operations is O(log n), whereas in a linked list, it is O(n).
- This improvement is achieved by leveraging the hierarchical structure of binary trees, which allows for more efficient searching and manipulation of data.

### Depth, height, and size of a binary tree:

- The depth of a node in a binary tree is the number of edges on the path from the root node to that node.
- The height of a binary tree is the maximum depth of any node in the tree, i.e., the longest path from the root node to a leaf node.
- The size of a binary tree is the total number of nodes in the tree.

### Different traversal methods to go through a binary tree:

- Preorder traversal: Visit the root node, then recursively traverse the left subtree, and finally recursively traverse the right subtree.
- Inorder traversal: Recursively traverse the left subtree, visit the root node, and then recursively traverse the right subtree.
- Postorder traversal: Recursively traverse the left subtree, recursively traverse the right subtree, and then visit the root node.
- Level-order traversal (also known as breadth-first traversal): Visit nodes level by level, starting from the root node and moving from left to right at each level.

### Types of binary trees:

- **Complete binary tree:** A binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
- **Full binary tree:** A binary tree in which every node has either zero or two children (no node has only one child).
- **Perfect binary tree:** A binary tree in which all internal nodes have exactly two children, and all leaf nodes are at the same level.
- **Balanced binary tree:** A binary tree in which the heights of the two subtrees of any node differ by at most one. Balancing ensures that the tree remains relatively shallow and maintains efficient time complexity for operations.
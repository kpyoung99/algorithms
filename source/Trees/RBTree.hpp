<<<<<<< HEAD
#pragma once
#include <iostream>

/** Red-Black Node Class */
class Node {
 private:
  // A 1 is a red link and a 0 is a black link
  int data;
  bool color;
  Node* left;
  Node* right;

 public:
  ~Node() {}

  Node(int data = 0, bool color = true) : data(data), color(color) {
    left = right = nullptr;
  }

  friend class RBTree;
};

/** Red-Black Tree Class */
class RBTree {
 private:
  Node* root;

  /** insert(int data, Node* n)
   * Recursively places data at the correct position in the subtree
   * rooted at n, preserving the RBTree properties.
   * Returns the Node containing data at the call that creates the node,
   * and returns n at every other call.
   * Does nothing if the data is already in the subtree.
   */
  Node* insert(int data, Node* n);
  Node* rotateRight(Node* node);
  Node* rotateLeft(Node* node);
  void flipColors(Node* node);
  Node* fix(Node* temp);
  Node* moveRedLeft(Node* temp);
  Node* moveRedRight(Node* temp);

  /** search(int data, Node* n)
   * Recursively searches for data in the subtree rooted at n, returning
   * true if the data is found and false otherwise.
   */
  bool search(int data, Node* n);

  /** remove(int data, Node* n)
   * Recursively searches for data in the subtree rooted at n, removing it
   * if it exists and preserving the BST properties.
   * Returns...
   *   nullptr if data was not found or n was a leaf.
   *   the pointer to the child if n has only one child.
   *   the pointer to the right child (successor) if n has two children.
   */
  Node* remove(int data, Node* n);

  /** height(Node* n)
   * Recursively determines the height of the subtree rooted at n.
   */
  int height(Node* n);

  /** clear(Node* n)
   * Recursively deletes the entire subtree rooted at n.
   */
  void clear(Node* n);

  /** preorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using a pre-order traversal.
   */
  void preorder(Node* n, std::ostream& oss);

  /** inorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using an in-order traversal.
   */
  void inorder(Node* n, std::ostream& oss);

  /** postorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using a post-order traversal.
   */
  void postorder(Node* n, std::ostream& oss);

  Node* deleteMax(Node* temp);
  Node* deleteMin(Node* temp);

  int min(Node* subtree, bool first);

 public:
  RBTree() { root = nullptr; };
  ~RBTree();

  /** insert(int data)
   * Inserts the given data into the tree.
   * Does nothing if the data is already in the tree.
   */
  void insert(int data);

  /** is_empty()
   * Returns true if the tree is empty and false otherwise
   */
  bool is_empty() { return !root; };

  /** search(int data)
   * Searches the tree for the given data, returning true if the data
   * is found and false otherwise.
   */
  bool search(int data) { return search(data, root); }

  /** remove(int data)
   * Removes the given data from the tree, provided it exists.
   */
  void remove(int data) { remove(data, root); }

  /** height()
   * Determines and returns the height of the tree.
   * Returns -1 if the tree is empty.
   */
  int height();

  /** clear()
   * Removes every element from the tree.
   */
  void clear();

  /** preorder()
   * Prints the contents of the tree to the ostream using a pre-order
   * traversal.
   */
  void preorder(std::ostream& oss = std::cout);

  /** inorder()
   * Prints the contents of the tree to the ostream using an in-order
   * traversal.
   */
  void inorder(std::ostream& oss = std::cout);

  /** postorder()
   * Prints the contents of the tree to the ostream using a post-order
   * traversal.
   */
  void postorder(std::ostream& oss = std::cout);

  void deleteMax();

  void deleteMin();
};
=======
#pragma once
#include <iostream>
#include "Node.hpp"

/** Red-Black Tree
 * Go to the link below for details about certain methods (e.g. rotateRight):
 * https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf
 */
class RBTree {
 private:
  Node* root;

  /** insert(int data, Node* n)
   * Recursively places data at the correct position in the subtree
   * rooted at n, preserving the RBTree properties.
   * Returns the Node containing data at the call that creates the node,
   * and returns n at every other call.
   * Does nothing if the data is already in the subtree.
   *
   * Inputs:
   * @param data: integer to be added to the tree
   * @param n: Node to root the subtree
   *
   * Outputs:
   * A pointer to a node for use in recursion
   *
   * Side Effects:
   * Inserts the value data into its appropriate place within the tree
   *
   * Examples:
   * RBTree test;
   * test.insert(1, root)
   *
   * Runtime:
   * O(log n)
   */
  Node* insert(int data, Node* n);

  /** rotateRight(Node* node)
   * Performs the "rotate right" operation on node, as described in the link
   * above.
   * Returns the node at the same position after rotation (node->left)
   *
   * Inputs:
   * @param n: Node to root the subtree
   *
   * Outputs:
   * A pointer to a node for use in other helper functions for maintaining
   * balance in the tree
   *
   * Side Effects:
   * Performs the rotate right functionality to aid in balancing the tree on
   * node n
   *
   * Runtime:
   * O(?)
   */
  static  Node* rotateRight(Node* node);

  /** rotateLeft(Node* node)
   * Performs the "rotate left" operation on node, as described in the link
   * above.
   * Returns the node at the same position after rotation (node->right)
   *
   * Inputs:
   * @param n: Node to root the subtree
   *
   * Outputs:
   * A pointer to a node for use in other helper functions for maintaining
   * balance in the tree
   *
   * Side Effects:
   * Performs the rotate left functionality to aid in balancing the tree on node
   * n
   *
   * Runtime:
   * O(?)
   */
  static Node* rotateLeft(Node* node);

  /** flipColors(Node* node)
   * Flips the colors of node and its children.
   *
   * Inputs:
   * @param n: Node to root the subtree
   *
   * Side Effects:
   * Performs the flip colors functionality to aid in balancing the tree on node
   * n
   *
   * Runtime:
   * O(1)
   */
  static void flipColors(Node* node);

  /** fix(Node* node)
   * Combines rotateRight, rotateLeft, and flipColors to restore RBTree
   * properties, as described in the link above.
   * Returns the node at the same position in the tree after fixing.
   *
   * Inputs:
   * @param n: Node to root the subtree
   *
   * Outputs:
   * A pointer to a node for use in other helper functions for maintaining
   * balance in the tree
   *
   * Side Effects:
   * Performs the fix functionality to perform rotate right rotate left or flip
   * colors as necessary to restore balance to the tree
   *
   * Runtime:
   * O(?)
   */
  Node* fix(Node* temp);

  /** moveRedLeft(Node* temp)
   * Performs the "move red left" operation on temp, as described in the link
   * above.
   * Returns the node at the same position in the tree after alteration.
   *
   * Inputs:
   * @param n: Node to root the subtree
   *
   * Outputs:
   * A pointer to a node for use in other helper functions for maintaining
   * balance in the tree
   *
   * Side Effects:
   * Performs the move red left functionality to aid in balancing the tree on
   * node n
   *
   * Runtime:
   * O(?)
   */
  Node* moveRedLeft(Node* temp);

  /** moveRedRight(Node* temp)
   * Performs the "move red right" operation on temp, as described in the link
   * above.
   * Returns the node at the same position in the tree after alteration.
   *
   * Inputs:
   * @param n: Node to root the subtree
   *
   * Outputs:
   * A pointer to a node for use in other helper functions for maintaining
   * balance in the tree
   *
   * Side Effects:
   * Performs the move red right functionality to aid in balancing the tree on
   * node n
   *
   * Runtime:
   * O(?)
   */
  Node* moveRedRight(Node* temp);

  /** search(int data, Node* n)
   * Recursively searches for data in the subtree rooted at n, returning
   * true if the data is found and false otherwise.
   *
   * Inputs:
   * @param data: integer to be search for in the tree
   * @param n: Node to root the subtree
   *
   * Outputs:
   * True if the value of data is present in the subtree rooted at n
   * False otherwise
   *
   * Examples:
   * RBTree test;
   * test.insert(1, root)
   * test.search(1, root) == 1
   * test.search(2, root) == 0
   *
   * Runtime:
   * O(log n)
   */
  static  bool search(int data, Node* n);

  /** remove(int data, Node* n)
   * Recursively searches for data in the subtree rooted at n, removing it
   * if it exists and preserving the RBTree properties.
   * Returns...
   *   nullptr if data was not found or n was a leaf.
   *   the pointer to the child if n has only one child.
   *   the pointer to the right child (successor) if n has two children.
   *
   * Inputs:
   * @param data: integer to be removed from the tree
   * @param n: Node to root the subtree
   *
   * Outputs:
   * A pointer to a node for use in recursion
   *
   * Side Effects:
   * Removes the value data from the tree
   *
   * Examples:
   * RBTree test;
   * test.insert(1, root)
   * test.remove(1, root)
   * test.search(1, root) == 0
   *
   * Runtime:
   * O(log n)
   */
  Node* remove(int data, Node* n);

  /** removeMax(Node* temp)
   * Removes the node with the largest key from the subtree rooted at temp.
   * Returns nullptr if temp was removed and temp otherwise.
   *
   * Inputs:
   * @param n: Node to root the subtree
   *
   * Outputs:
   * A pointer to a node for use in recursion
   *
   * Side Effects:
   * Removes the largest value from the subtree rooted at n
   *
   * Examples:
   * RBTree test;
   * test.insert(1, root)
   * test.insert(2, root)
   * test.insert(3, root)
   * test.removeMax(root)
   * test.search(3, root) == 0
   *
   * Runtime:
   * O(log n)
   */
  Node* removeMax(Node* temp);

  /** removeMin(Node* temp)
   * Removes the node with the smallest key from the subtree rooted at temp.
   * Returns nullptr if temp was removed and temp otherwise.
   *
   * Inputs:
   * @param n: Node to root the subtree
   *
   * Outputs:
   * A pointer to a node for use in recursion
   *
   * Side Effects:
   * Removes the smallest value from the subtree rooted at n
   *
   * Examples:
   * RBTree test;
   * test.insert(1, root)
   * test.insert(2, root)
   * test.insert(3, root)
   * test.removeMin(root)
   * test.search(1, root) == 0
   *
   * Runtime:
   * O(log n)
   */
  Node* removeMin(Node* temp);

  /** height(Node* n)
   * Recursively determines the height of the subtree rooted at n.
   *
   * Inputs:
   * @param n: Node to root the subtree
   *
   * Outputs:
   * The height of the subtree rooted at n
   *
   * Examples:
   * RBTree test;
   * test.insert(1, root)
   * test.height(root) == 1
   *
   * Runtime:
   * O(?)
   */
  static  int height(Node* n);

  /** clear(Node* n)
   * Recursively deletes the entire subtree rooted at n.
   *
   * Inputs:
   * @param data: integer to be added to the tree
   *
   * Side Effects:
   * Removes every node from the subtree rooted at n
   *
   * Examples:
   * RBTree test;
   * test.insert(1, root)
   * test.clear(root)
   * test.search(1, root) == 0
   *
   * Runtime:
   * O(?)
   */
  static  void clear(Node* n);

  /** preorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using a pre-order traversal.
   *
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   *
   * Side Effects:
   * Prints a preorder traversal of the tree to the given stream
   *
   * Runtime:
   * O(?)
   */
  static  void preorder(Node* n, std::ostream& oss);

  /** inorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using an in-order traversal.
   *
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   *
   * Side Effects:
   * Prints a inorder traversal of the tree to the given stream
   *
   * Runtime:
   * O(?)
   */
  static  void inorder(Node* n, std::ostream& oss);

  /** postorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using a post-order traversal.
   *
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   *
   * Side Effects:
   * Prints a postorder traversal of the tree to the given stream
   *
   * Runtime:
   * O(?)
   */
  static  void postorder(Node* n, std::ostream& oss);

  /** isRed(Node* n)
   * Checks if n is red. A null pointer is defined to not be red.
   *
   * Inputs:
   * @param data: integer to be added to the tree
   * @param n: Node to root the subtree
   *
   * Outputs:
   * True if n is a red node
   * False otherwise
   *
   * Runtime:
   * O(1)
   */
  static  bool isRed(Node* n);

  /** min(Node* subtree)
   * Finds the value of the minimum key in the subtree rooted at subtree and
   * returns it.
   *
   * Inputs:
   * @param subtree: Node to root the subtree
   *
   * Outputs:
   * The value of the smallest number in the right subtree of subtree
   *
   * Runtime:
   * O(log n)
   */
  static  int min(Node* subtree);

  /** max(Node* subtree)
   * Finds the value of the maximum key in the subtree rooted at subtree and
   * returns it.
   *
   * Inputs:
   * @param subtree: Node to root the subtree
   *
   * Outputs:
   * The value of the largest number in the right subtree of subtree
   *
   * Runtime:
   * O(log n)
   */
  static  int max(Node* subtree);

 public:
  /** Constructors */
  RBTree() { root = nullptr; };

  /** Destructors */
  ~RBTree();

  /** insert(int data)
   * Inserts the given data into the tree.
   * Does nothing if the data is already in the tree.
   *
   * Inputs:
   * @param data: integer to be added to the tree
   *
   * Side Effects:
   * Inserts the value data into its appropriate place within the tree
   *
   * Examples:
   * RBTree test;
   * test.insert(1)
   *
   * Runtime:
   * O(log n)
   */
  void insert(int data);

  /** is_empty()
   * Returns true if the tree is empty and false otherwise
   *
   * Outputs:
   * True if the tree is empty
   * False otherwise
   *
   * Examples:
   * RBTree test
   * test.is_empty() == 1
   * test.insert(1)
   * test.is_empty() == 0
   *
   * Runtime:
   * O(log n)
   */
  bool is_empty() { return !root; };

  /** search(int data)
   * Searches the tree for the given data, returning true if the data
   * is found and false otherwise.
   *
   * Inputs:
   * @param data: integer to be search for in the tree
   *
   * Outputs:
   * True if the value of data is present in the subtree rooted at n
   * False otherwise
   *
   * Examples:
   * RBTree test;
   * test.insert(1)
   * test.search(1) == 1
   * test.search(2) == 0
   *
   * Runtime:
   * O(log n)
   */
  bool search(int data) { return search(data, root); }

  /** min()
   * Finds the minimum key in the tree and returns it.
   *
   * Outputs:
   * The value of the smallest number in the tree
   *
   * Runtime:
   * O(log n)
   */
  int min() { return min(root); }

  /** max()
   * Finds the maximum key in the tree and returns it.
   *
   * Outputs:
   * The value of the largest number in the tree
   *
   * Runtime:
   * O(log n)
   */
  int max() { return max(root); }

  /** remove(int data)
   * Removes the given data from the tree, provided it exists.
   *
   * Inputs:
   * @param data: integer to be removed from the tree
   *
   * Side Effects:
   * Removes the value data from the tree
   *
   * Examples:
   * RBTree test;
   * test.insert(1)
   * test.remove(1)
   * test.search(1) == 0
   *
   * Runtime:
   * O(log n)
   */
  void remove(int data) { root = remove(data, root); }

  /** removeMin()
   * Removes the minimum key from the tree
   *
   * Outputs:
   * A pointer to a node for use in recursion
   *
   * Side Effects:
   * Removes the smallest value from the tree
   *
   * Examples:
   * RBTree test;
   * test.insert(1)
   * test.insert(2)
   * test.insert(3)
   * test.removeMin()
   * test.search(1) == 0
   *
   * Runtime:
   * O(log n)
   */
  void removeMin();

  /** removeMax()
   * Removes the maximum key from the tree
   *
   * Outputs:
   * A pointer to a node for use in recursion
   *
   * Side Effects:
   * Removes the largest value from the tree
   *
   * Examples:
   * RBTree test;
   * test.insert(1)
   * test.insert(2)
   * test.insert(3)
   * test.removeMax()
   * test.search(3) == 0
   *
   * Runtime:
   * O(log n)
   */
  void removeMax();

  /** height()
   * Determines and returns the height of the tree.
   * Returns -1 if the tree is empty.
   *
   * Outputs:
   * The height of the tree
   *
   * Examples:
   * RBTree test;
   * test.insert(1)
   * test.height() == 1
   *
   * Runtime:
   * O(?)
   */
  int height();

  /** clear()
   * Removes every element from the tree.
   *
   * Side Effects:
   * Removes every node from the subtree rooted at n
   *
   * Examples:
   * RBTree test;
   * test.insert(1, root)
   * test.clear(root)
   * test.search(1, root) == 0
   *
   * Runtime:
   * O(?)
   */
  void clear();

  /** preorder()
   * Prints the contents of the tree to the ostream using a pre-order
   * traversal.
   *
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   *
   * Side Effects:
   * Prints a preorder traversal of the tree to the given stream
   *
   * Runtime:
   * O(?)
   */
  void preorder(std::ostream& oss = std::cout);

  /** inorder()
   * Prints the contents of the tree to the ostream using an in-order
   * traversal.
   *
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   *
   * Side Effects:
   * Prints a inorder traversal of the tree to the given stream
   *
   * Runtime:
   * O(?)
   */
  void inorder(std::ostream& oss = std::cout);

  /** postorder()
   * Prints the contents of the tree to the ostream using a post-order
   * traversal.
   *
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   *
   * Side Effects:
   * Prints a postorder traversal of the tree to the given stream
   *
   * Runtime:
   * O(?)
   */
  void postorder(std::ostream& oss = std::cout);
};
>>>>>>> upstream/master

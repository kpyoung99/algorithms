#pragma once
#include <iostream>

/** Node Class
 * These are the building blocks of the trie.
 */
class Node {
 private:
  Node* children[26];
  int value;
  bool end_of_word;

 public:
  Node(int d, bool eow) : value(d), end_of_word(eow) {
    for (int i = 0; i < 26; ++i) children[i] = nullptr;
  }
  ~Node() {}

  friend class Trie;
};

/** Trie (Prefix Tree)
 * A class that stores strings and associated ints as a tree of letter nodes,
 * where each path down the tree contains the letters of a string or substring.
 * The value associated with the string is stored in the node representing the
 * last letter of the string.
 * If the value of a Node is null the string is not in the tree.
 * Allows for efficient insert and search/data access methods.
 */
class Trie {
 private:
  Node* root;
  int size;

 public:
  Trie();
  ~Trie();

  /** insert(char* word)
   * Inserts word with the associated val into the Trie.
   * If the word is already in the tree, its value is replaced with val.
   */
  void insert(char* word, int val);

  /** count()
   * Returns the number of word in the Trie.
   */
  int count();

  /** search(char* word)
   * Searches for word in the Trie, returning true if found and false otherwise.
   */
  bool search(char* word);

  /** get(char* word)
   * Searches for word in the Trie and returns its value.
   * Throws an error if word is not found.
   */
  int get(char* word);

  /** remove(char* word)
   * Searches for word in the tree and remove it if found.
   * Throws an error if word is not found.
   */
  void remove(char* word);

  /** clear()
   * Removes all words from the Trie.
   */
  void clear();

  /** print()
   * Prints the Trie's key-value (string-int) pairs to the ostream in
   * alphabetical order.
   * The key and value of each pair are separated by a space, and each pair is
   * separated by the newline character.
   */
  void print(std::ostream& oss = std::cout);
};

#pragma once
#include <iostream>
<<<<<<< HEAD
#include "../String/String.hpp"
#include <string>

/** A modified version of the linkedlist class available in the LinkedList Library */
=======
#include <string>
#include "../String/String.hpp"

/** A modified version of the linkedlist class available in the LinkedList
 * Library */
>>>>>>> upstream/master

/** Node Class
 * These are the building blocks of the linked list.
 */
class Node {
 private:
  String* key;
  int val;
  Node* next;
  Node* prev;

 public:
<<<<<<< HEAD
  Node();
  Node(const String& k, int v);
  ~Node();
=======
  Node() : key(new String()), val(0) { next = prev = nullptr; }
  Node(const String& k, int v) : key(new String(k.cstr())), val(v) {
    next = prev = nullptr;
  }
  ~Node() { delete key; };
>>>>>>> upstream/master

  friend class List;
};

/** Doubly Linked List
 * A class that manages nodes to store data
 * non-contiguously in memory.
 */
class List {
 private:
  Node* head;
  Node* tail;
  unsigned int len;

 public:
<<<<<<< HEAD
  List();
  ~List();
=======
  List() : head(nullptr), len(0) {}
  ~List() { clear(); }
>>>>>>> upstream/master

  /** length()
   * Returns the length of linked list.
   */
<<<<<<< HEAD
  unsigned int length();
=======
  unsigned int length() { return len; }
>>>>>>> upstream/master

  /** push(int data, [int index])
   * Pushes a node containing the given data to the list.
   */
<<<<<<< HEAD
  void push_back(const String& key, int val);
=======
  void push_back(const String& key, int val) {
    Node* n = new Node(key, val);
    if (!head) {
      head = n;
    } else {
      Node* iter = head;
      while (iter->next)
        iter = iter->next;

      iter->next = n;
    }
    ++len;
    return;
  }
>>>>>>> upstream/master

  /** clear()
   * Clears the entire list.
   */
<<<<<<< HEAD
  void clear();
=======
  void clear() {
    Node* to_remove;
    while (head) {
      to_remove = head;
      head = head->next;
      delete to_remove;
    }
    len = 0;
  }
>>>>>>> upstream/master

  /** remove(int data)
   * Removes the first item from the list with value data.
   */
<<<<<<< HEAD
  void remove(String& data);
=======
  void remove(String& data) {
    if (!head)
      throw "Nothing to remove";
    else if (head->key->compare(data)) {
      Node* temp = head;
      head = head->next;
      --len;
      delete temp;
    } else {
      for (Node* iter = head; iter->next; iter = iter->next) {
        if (iter->next->key->compare(data) == 1) {
          Node* to_remove = iter->next;
          iter->next = to_remove->next;
          delete to_remove;
          --len;
          break;
        }
      }
    }
  }
>>>>>>> upstream/master

  /** index(data)
   * Returns the index of the given data in the linked list,
   * -1 if that data is not present.
   */
<<<<<<< HEAD
  int index(String& d);
=======
  int index(String& d) {
    int i = 0;
    for (Node* iter = head; iter; iter = iter->next, ++i) {
      if (iter->key->compare(d) == 1)
        return i;
    }
    return -1;
  }
>>>>>>> upstream/master

  /** at(ind)
   * returns the val member at the given index
   */
<<<<<<< HEAD
  int at(int ind);
=======
  int at(int ind) {
    Node* iter = head;
    for (int i = 0; i < ind; ++i) {
      iter = iter->next;
    }
    return iter->val;
  }
>>>>>>> upstream/master

  /** print()
   * Prints the contents of the list to the ostream.
   */
<<<<<<< HEAD
  void print(std::ostream& oss = std::cout);
=======
  void print(std::ostream& oss = std::cout) {
    std::cout << "Length " << len << std::endl;
    Node* temp = head;
    while (temp) {
      oss << temp->val << ", ";
      temp->key->print();
      std::cout << std::endl;
      temp = temp->next;
    }
    oss << std::endl;
    return;
  }
>>>>>>> upstream/master
};

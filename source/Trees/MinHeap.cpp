#include "MinHeap.hpp"

  /** swim()
   * Restores the heap order property after an element is pushed. Assumes the
   * new element has been pushed at the end of the heap array (right-most node
   * in the bottom level of the tree), and swaps it upwards the tree until it's
   * greater than its parent.
   */
//Helper
void swap(int* y, int* x) {
  int temp;
  temp = *y;
  *y = *x;
  *x = temp;
}

void MinHeap::swim(){
    int i = size;
    while(arr[i/2] > arr[i])
        swap(&arr[i/2], &arr[i]);
}

  /** sink(int i)
   * Restores the heap order property after element removal. Assumes the element
   * at the end of the heap array has been swapped with the root, and the size
   * has been decremented (effectively removing the last element in the heap
   * array). It then swaps the element at the root down the tree until both
   * children are greater than it.
   */
  void MinHeap::sink(int i){
      while(true){
        if (arr[i*2] < arr[(i*2)+1]){
            if (&arr[i * 2] < &arr[i])
                swap(&arr[i], &arr[i*2]);
            else
                break;
            
        }
        else{
            if (&arr[(i*2) + 1] < &arr[i]){
                swap(&arr[(i*2) + 1], &arr[i]);
            }
            else
                break;
        }
      }
  }

  /** search(int i, int data)
   * Recursively searches for data in the MinHeap's subtree rooted at i,
   * returning true if the data is found and false if i is greater than or
   * equal to size or data is less than the MinHeap's value at i.
   */
  bool MinHeap::search(int i, int data){
    if (i >= size)    return false;
    else if (arr[i] < data)   return false;
    else if (arr[i] == data)  return true;
    else if (arr[i * 2] > arr[(i * 2) + 1])
        search((i * 2) + 1, data);
    else
        search((i * 2), data);
  }

  /** erase(int i, int data)
   * Recursively searches for data in the MinHeap's subtree rooted at i,
   * calling remove on i if data is found in the tree.
   * Does nothing if data is not found in the subtree.
   */
  void MinHeap::erase(int i, int data){}



  /** push(int data)
   * Inserts data into the MinHeap such that the heap order property is
   * preserved.
   * Assumes duplicate elements will not be pushed.
   */
  void MinHeap::push(int data){
      if (arr[i*2] < arr[(i*2)+1]);
  }

  /** count()
   * Returns the number of elements in the MinHeap.
   */
  int MinHeap::count(){}

  /** pop()
   * Removes and returns the minimum element in the MinHeap, preserving the
   * heap order property.
   * Throws an error if the heap is empty.
   */
  int MinHeap::pop(){}

  /** peek()
   * Returns the minimum element in the MinHeap without modifying its contents.
   * Throws an error if the heap is empty.
   */
  int MinHeap::peek(){}

  /** search(int data)
   * Searches the MinHeap for the given data, returning true if the data is
   * found and false otherwise.
   */
  bool MinHeap::search(int data){}

  /** remove(int i)
   * Removes the element at index i in the MinHeap tree (indexed left-to-right,
   * top-to-bottom) and returns its value.
   * Throws an error if the heap is empty or the index is out of bounds.
   */
  int MinHeap::remove(int i){}

  /** erase(int data)
   * Searches the MinHeap for the given data, and deletes it if it's found,
   * preserving the heap order property.
   * Does nothing if data is not found.
   */
  void MinHeap::erase(int data){}

  /** print()
   * Prints the contents of the MinHeap tree to the ostream from left-to-right,
   * top-to-bottom.
   */
  void MinHeap::print(std::ostream& oss = std::cout){}

